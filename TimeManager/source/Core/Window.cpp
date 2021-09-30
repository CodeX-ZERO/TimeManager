#include "Window.h"
#include <exception>



namespace Core
{
#define GET_USER_WINDOW(window) (Window*)glfwGetWindowUserPointer(window)

	Window::Window(WindowData data)
	{
		if (!glfwInit())
			throw std::exception();

		m_Window = glfwCreateWindow(data.Width, data.Height, data.Title.c_str(), nullptr, nullptr);
		m_EventCallback = [](Event& e) {};

		glfwMakeContextCurrent(m_Window);
		glfwShowWindow(m_Window);
		glfwSetWindowUserPointer(m_Window, this);

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
			{
				Window* userWindow = GET_USER_WINDOW(window);
				MouseMovedEvent e(x, y, false);
				userWindow->m_EventCallback(e);
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				Window* userWindow = GET_USER_WINDOW(window);
				MouseScrollEvent e(xOffset, yOffset);
				userWindow->m_EventCallback(e);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				Window* userWindow = GET_USER_WINDOW(window);
				KeyEvent e(key, action);
				userWindow->m_EventCallback(e);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				Window* userWindow = GET_USER_WINDOW(window);
				MouseButtonEvent e(button, action);
				userWindow->m_EventCallback(e);
			});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				Window* userWindow = GET_USER_WINDOW(window);
				WindowResizeEvent e(width, height);
				userWindow->m_Data.Width = width;
				userWindow->m_Data.Height = height;
				userWindow->m_EventCallback(e);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				Window* userWindow = GET_USER_WINDOW(window);
				WindowCloseEvent e;
				userWindow->m_EventCallback(e);
			});
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::SetEventCallback(EventCallbackFn callback)
	{
		m_EventCallback = callback;
	}

	unsigned int Window::GetWidth()
	{
		return m_Data.Width;
	}

	unsigned int Window::GetHeight()
	{
		return m_Data.Height;
	}

	std::string Window::GetTitle() 
	{
		return m_Data.Title;
	}


}
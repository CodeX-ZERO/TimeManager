#include "Application.h"
#include <iostream>


namespace Core 
{


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_Window = new Window(WindowData());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMove));
	}

	void Application::Run()
	{
		while (m_Running) 
		{
			m_Window->OnUpdate();
		}
	}

	bool Application::OnMouseMove(MouseMovedEvent& e) 
	{
		std::cout << e.GetName() << " : X -" << e.GetX() << " Y - " << e.GetY() << std::endl;
		return true;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) 
	{
		m_Running = false;
		return true;
	}

}
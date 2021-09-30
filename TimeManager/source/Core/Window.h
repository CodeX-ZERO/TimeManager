#pragma once
#include <GLFW/glfw3.h>
#include <functional>

#include "Events/MouseEvents.h"
#include "Events/KeyEvent.h"
#include "Events/WindowEvents.h"


namespace Core
{

	struct WindowData 
	{
		std::string Title;
		unsigned int Width, Height;
		
		WindowData(std::string title = "TimeManager",
					unsigned int width = 1280,
					unsigned int height = 720) 
			: Title(title), Width(width), Height(height)
		{}

	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(WindowData data);
		virtual ~Window();

		void OnUpdate();
		void SetEventCallback(EventCallbackFn eventCallback);

		unsigned int GetWidth();
		unsigned int GetHeight();
		std::string GetTitle();
		
	private:
		GLFWwindow* m_Window;
		EventCallbackFn m_EventCallback;
		WindowData m_Data;
	};

}
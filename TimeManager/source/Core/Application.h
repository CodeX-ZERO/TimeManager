#pragma once
#include "Window.h"

namespace Core
{
	class Application
	{
	public:
		Application();
		~Application();

		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnMouseMove(MouseMovedEvent& e);
		void Run();
	private:
		Window* m_Window;
		bool m_Running = true;
	};
}
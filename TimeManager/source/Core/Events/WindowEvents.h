#pragma once
#include "Event.h"

namespace Core
{
	class WindowResizeEvent : public Event 
	{
	public:
		WindowResizeEvent(int width, int height)
			: m_Width(width), m_Height(height)
		{}
		
		EVENT_CLASS_TYPE(WindowResizeEvent)

		inline int GetWidth() { return m_Width; }
		inline int GetHeight() { return m_Height; }
	private:
		int m_Width;
		int m_Height;
	};

	class WindowCloseEvent : public Event 
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowCloseEvent);
	};


}
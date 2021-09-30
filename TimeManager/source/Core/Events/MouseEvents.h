#pragma once
#include "Event.h"

namespace Core
{
	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(double xOffset, double yOffset) 
			: m_OffsetX(xOffset), m_OffsetY(yOffset)
		{}

		EVENT_CLASS_TYPE(MouseScrollEvent)


		inline double GetOffsetX(){ return m_OffsetX; }
		inline double GetOffsetY(){ return m_OffsetY; }

	private:
		double m_OffsetX;
		double m_OffsetY;
	};


	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(int x, int y, bool dragged)
			: m_X(x), m_Y(y), m_Dragged(dragged)
		{}

		EVENT_CLASS_TYPE(MouseMovedEvent)

		inline double GetX(){ return m_X; }
		inline double GetY() { return m_Y; }
		inline bool IsDragged() { return m_Dragged; }
	private:
		double m_X, m_Y;
		bool m_Dragged;
	};

	class MouseButtonEvent : public Event
	{

	public:
		MouseButtonEvent(int button, int action) 
			: m_Button(button), m_Action(action)
		{}
		
		EVENT_CLASS_TYPE(MouseButtonEvent)

		inline int GetAction(){ return m_Action; }
		inline int GetButton(){ return m_Button; }
	private:
		int m_Button;
		int m_Action;
	};
}
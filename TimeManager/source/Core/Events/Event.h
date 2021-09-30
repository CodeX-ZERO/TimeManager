#pragma once
#include <string>

namespace Core
{

	enum class EventType
	{
		MouseMovedEvent,
		MouseButtonEvent,
		MouseScrollEvent,
		KeyEvent,
		WindowResizeEvent,
		WindowCloseEvent
	};

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual std::string GetName() const = 0;
		
	private:
		bool m_Handled = false;
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual std::string GetName() const override { return #type; }

	class EventDispatcher 
	{
	public:
		template <class T>
		using EventFn = std::function<bool(T&)>;

		EventDispatcher(Event& e) : m_Event(e)
		{}

		template <class T>
		bool Dispatch(EventFn<T> function)
		{
			if (m_Event.GetEventType() == T::GetStaticType()) 
			{
				m_Event.m_Handled = function(*(T*)&m_Event);
				return true;
			}

			return false;
		}

	private:
		Event& m_Event;
	};
}
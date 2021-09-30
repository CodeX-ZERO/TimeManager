#pragma once
#include "Event.h"

namespace Core
{

	class KeyEvent : public Event
	{
	public:
		KeyEvent(int key, int action)
			: m_Action(action), m_Key(key)
		{}

		EVENT_CLASS_TYPE(KeyEvent)

		inline int GetKey() { return m_Key; }
		inline int GetAction() { return m_Action; }
	private:
		int m_Key;
		int m_Action;
	};

}
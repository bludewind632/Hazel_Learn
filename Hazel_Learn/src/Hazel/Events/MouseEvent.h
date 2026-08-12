#pragma once

#include "Event.h"

// #include <sstream>
#include "hzpch.h"

namespace Hazel {

	class HAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(int x, int y) : m_MouseX(x), m_MouseY(y) {}
		inline int GetMouseX() const { return m_MouseX; }
		inline int GetMouseY() const { return m_MouseY; }
		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		int m_MouseX, m_MouseY;
	};

	class HAZEL_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(int xOffSetet, int yOffSet) : m_XOffset(xOffSetet), m_YOffset(yOffSet) {}

		inline int GetXOffset() const { return m_XOffset; }
		inline int GetYOffset() const { return m_YOffset; }
		
		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseScroll);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		int m_XOffset, m_YOffset;
	};

}
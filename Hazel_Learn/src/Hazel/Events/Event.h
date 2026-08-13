#pragma once

#include "Hazel/Core.h"

#include "hzpch.h"

// #include <string>
// #include <functional>

namespace Hazel {
	/***
	* Event Blocking, meaning that when event occurs it gets dispatched and be dealt with right then and there
	* In the future, we might use a better strategy to cope with these events in event bus during the "Update Event" Stage.
	* 
	* 
	***/
	enum class EventType 
	{
		None = 0,
		WindowClose, WindowResize, WindowMove, WindowFocus, WindowLostFocus,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseHover, MouseScroll
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication =  BIT(0),
		EventCategoryInput       =  BIT(1),
		EventCategoryKeyBoard    =  BIT(2),
		EventCategoryMouse       =  BIT(3),
		EventCategoryMouseButton =  BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							    virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags() const override { return category; }


	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		// filter the specific event category
		inline bool IsInCategory(EventCategory category) const 
		{
			return GetEventCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event) {}
		// Abstract Class Event can't be instantiated, The parameter must be referred

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				 m_Event.m_Handled = func(static_cast<T&>(m_Event));
				// m_Event.m_Handled = func(*(T*)&m_Event); // DownCast
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
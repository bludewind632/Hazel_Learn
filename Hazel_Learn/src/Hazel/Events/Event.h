#pragma once

#include "Hazel/Core.h"

#include <string>
#include <functional>

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
		MouseButtonPressed, MouseButtonPressed, MouseMove, MouseHover, MouseScroll
	};

	enum EventCategory
	{

	};


	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		
	};

	class EventDispatcher
	{

	};
}
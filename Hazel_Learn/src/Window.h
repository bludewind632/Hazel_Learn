#pragma once

#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	// The basic properties of Window
	class WindowProps 
	{
	public:
		WindowProps(std::string title = "Hazel Engine", 
			unsigned int w = 1280, 
			unsigned int h = 720) 
			: Title(title), Width(w), Height(h) {}

		std::string Title;
		unsigned int Width, Height;
	};

	// A abstract class Window play as a foundation of The Engine's Interface
	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}

		virtual void OnUpdate() const = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Windows attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
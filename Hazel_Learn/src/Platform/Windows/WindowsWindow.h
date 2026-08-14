#pragma once

#include "GLFW/glfw3.h"
#include "Window.h"

namespace Hazel {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowProps& props) : () {}
		virtual ~WindowsWindow() {}	

		void OnUpdate() override;

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetWidth() const { return m_Data.Width; }

		// Windows attributes
		inline void SetEventCallback(const EventCallbackFn& back) override { m_Data.EventCallback = back; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowsData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		} m_Data;

	};
}
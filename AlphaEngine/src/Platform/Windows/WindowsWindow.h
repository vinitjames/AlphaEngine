#pragma once

#include "AlphaEngine/Window.h"
#include "GLFW/glfw3.h"

namespace AlphaEngine {
	class AlphaEngine_API WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		~WindowsWindow();

		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//window attributes
		inline void SetEventCallback(const EventCallbackFunc& func) override { m_Data.EventCallback = func; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		virtual void SetWindowSizeCallback();
		virtual void SetWindowCloseCallback();
		virtual void SetKeyCallback();
		virtual void SetMouseMoveCallback();
		virtual void SetMouseButtonCallback();
		virtual void SetMouseScrollCallback();

		GLFWwindow* m_Window;
		struct WindowsData {
			std::string Title;
			unsigned int Width, Height;
			bool Vsync;
			EventCallbackFunc EventCallback;
		};
		WindowsData m_Data;
	};
}

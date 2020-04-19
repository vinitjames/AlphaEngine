#pragma once
#include "Aepch.h"
#include "AlphaEngine/Core.h"
#include "AlphaEngine/Events/Event.h"

namespace AlphaEngine {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Alpha Engine",
			         unsigned int width = 1920,
			         unsigned int height = 1080)
			: Title(title), Width(width), Height(height) {}

	};

	class AlphaEngine_API Window {
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// windows attributes
		virtual void SetEventCallback(const EventCallbackFunc& func) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& windowprop = WindowProps());
	};
}
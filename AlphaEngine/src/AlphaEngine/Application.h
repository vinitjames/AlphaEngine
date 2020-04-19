#pragma once
#include "core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace AlphaEngine {
	class AlphaEngine_API Application
	{   public:
		Application();
		virtual ~Application();

		void Run();
		void onEvent(Event&);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool onWindowCloseEvent(WindowCloseEvent&);
	};

	Application* CreateApplication();
}

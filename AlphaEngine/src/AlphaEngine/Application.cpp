#include "Aepch.h"
#include "Application.h"


namespace AlphaEngine {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	Application::~Application() {
	}

	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::onWindowCloseEvent, this, std::placeholders::_1));
		AE_CORE_INFO("{0}", e);
	}

	void Application::Run() {

		while (m_Running) {
			m_Window->OnUpdate();
		}

	}
	bool Application::onWindowCloseEvent(WindowCloseEvent &e) {
		m_Running = false;
		return true;

	}
}

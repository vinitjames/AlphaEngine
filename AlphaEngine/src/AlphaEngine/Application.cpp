#include "Aepch.h"
#include "Application.h"
#include "Log.h"
namespace AlphaEngine {
	Application::Application() {
	
	}
	Application::~Application() {
	}
	void Application::Run() {
		WindowResizeEvent w(1230,58);
		AE_TRACE(w);

		while (true);

	}
}

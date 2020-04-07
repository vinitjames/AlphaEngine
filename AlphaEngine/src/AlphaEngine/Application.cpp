#include "Application.h"
#include "Log.h"
namespace AlphaEngine {
	Application::Application() {
	
	}
	Application::~Application() {
	}
	void Application::Run() {
		WindowResizeEvent w(1230,580);
		AE_TRACE(w);

		while (true);

	}
}

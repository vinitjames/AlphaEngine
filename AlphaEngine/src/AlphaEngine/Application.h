#pragma once
#include "core.h"
#include "Events/ApplicationEvent.h"
namespace AlphaEngine {
	class AlphaEngine_API Application
	{   public:
		Application();
		virtual ~Application();

		void Run();
		//------- to be implemented in client-----------
		
	};
	Application* CreateApplication();
}

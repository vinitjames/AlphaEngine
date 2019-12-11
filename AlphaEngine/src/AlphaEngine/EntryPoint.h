#pragma once
#ifdef AE_PLATFORM_WINDOWS

extern AlphaEngine::Application* AlphaEngine::CreateApplication();
int main() {
	AlphaEngine::Log::Init();
	AE_CORE_WARN("This is a Warning from AlphaEngine");
	AE_INFO("This is an Info from AlphaEngine Client");

	AlphaEngine::Application* app = AlphaEngine::CreateApplication();
	app->Run();
	delete app;

}


#endif
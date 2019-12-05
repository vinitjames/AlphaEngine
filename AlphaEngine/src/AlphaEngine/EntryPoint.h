#pragma once
#ifdef AE_PLATFORM_WINDOWS

extern AlphaEngine::Application* AlphaEngine::CreateApplication();
int main() {
	AlphaEngine::Application* app = AlphaEngine::CreateApplication();
	app->Run();
	delete app;

}


#endif
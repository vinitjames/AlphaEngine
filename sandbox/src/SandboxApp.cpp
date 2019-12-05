#include "AlphaEngine.h"

class SandboxApp : public AlphaEngine::Application
{
public:
	SandboxApp() {
	}
	~SandboxApp() {
	}
};

AlphaEngine::Application* AlphaEngine::CreateApplication() {
	return new SandboxApp;
}

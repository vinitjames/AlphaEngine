#pragma once
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace AlphaEngine {
	class AlphaEngine_API Log
	{   private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}

#define AE_CORE_TRACE(...) AlphaEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AE_CORE_INFO(...)  AlphaEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AE_CORE_WARN(...)  AlphaEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AE_CORE_ERROR(...) AlphaEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AE_CORE_FATAL(...) AlphaEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define AE_TRACE(...) AlphaEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AE_INFO(...)  AlphaEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define AE_WARN(...)  AlphaEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AE_ERROR(...) AlphaEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define AE_FATAL(...) AlphaEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
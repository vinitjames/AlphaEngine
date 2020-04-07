#pragma once
#ifdef AE_PLATFORM_WINDOWS
	#ifdef AE_BUILD_DLL
		#define AlphaEngine_API __declspec(dllexport)
	#else 
		#define AlphaEngine_API __declspec(dllimport)
	#endif
#else 
	#error AlphaEngine Currently only supports Windows
#endif

#define BIT(x) (1 << x)


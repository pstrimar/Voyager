#pragma once

#ifdef VGR_PLATFORM_WINDOWS
	#ifdef VGR_BUILD_DLL
		#define VOYAGER_API __declspec(dllexport)
	#else 
		#define VOYAGER_API __declspec(dllimport)
	#endif
#else
	#error Voyager only supports Windows!
#endif

#ifdef VGR_ENABLE_ASSERTS
	#define VGR_ASSERT(x, ...) { if(!(x)) { VGR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VGR_CORE_ASSERT(x, ...) { if(!(x)) { VGR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VGR_ASSERT(x, ...)
	#define VGR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
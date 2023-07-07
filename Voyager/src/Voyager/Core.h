#pragma once

#ifdef VGR_PLATFORM_WINDOWS
#if VGR_DYNAMIC_LINK
	#ifdef VGR_BUILD_DLL
		#define VOYAGER_API __declspec(dllexport)
	#else 
		#define VOYAGER_API __declspec(dllimport)
	#endif
#else
	#define VOYAGER_API
#endif
#else
	#error Voyager only supports Windows!
#endif

#ifdef VGR_DEBUG
	#define VGR_ENABLE_ASSERTS
#endif

#ifdef  VGR_ENABLE_ASSERTS
	#define VGR_ASSERT(x, ...) { if(!(x)) { VGR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VGR_CORE_ASSERT(x, ...) { if(!(x)) { VGR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VGR_ASSERT(x, ...)
	#define VGR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define VGR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
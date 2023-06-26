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

#define BIT(x) (1 << x)
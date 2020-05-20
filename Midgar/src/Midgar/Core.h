#pragma once

#ifdef MG_PLATFORM_WINDOWS
	#ifdef MG_BUILD_DLL
		#define MIDGAR_API __declspec(dllexport)
	#else
		#define MIDGAR_API __declspec(dllimport)
	#endif
#else
	#error Midgar only supports Windows!
#endif
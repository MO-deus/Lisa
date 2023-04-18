
// for modern maachines
#pragma once

// for legacy systems :

#ifdef GRIM_CORE_WINDOW_PLATFORM
	#ifdef GRIM_BUILD_DLL
		#define GRIM_API __declspec(dllexport) // for export through dll only
	#else
		#define GRIM_API __declspec(dllimport)
	#endif // GRIM_BUILD_DLL
	#else
#error Grimoire only supports Windows platform
#define GRIM_CORE_WINDOW_PLATFORM	

#endif // GRIM_CORE_WINDOW_PLATFORM

#define BIT(x) (1 << x)
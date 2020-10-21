#pragma once

#ifdef SD_PLATFORM_WINDOWS
	#ifdef SD_BUILD_DLL
		#define SEED_API __declspec(dllexport)
	#else
		#define SEED_API __declspec(dllimport)
	#endif
#else
	#error Seed only supports Windows
#endif

#define BIT(X) (1 << X)

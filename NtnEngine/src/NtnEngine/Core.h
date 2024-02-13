#pragma once


#ifdef NTN_PLATFORM_WINDOWS
	#ifdef NTN_BUILD_DLL
		#define NTN_API __declspec(dllexport)
	#else
		#define NTN_API __declspec(dllimport)
	#endif
#else
	#error NTN only support Windows!
#endif 

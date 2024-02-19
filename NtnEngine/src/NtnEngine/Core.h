#pragma once


#ifdef NTN_PLATFORM_WINDOWS
	#ifdef NTN_BUILD_DLL
		#define NTN_API __declspec(dllexport)
	#else
		#define NTN_API __declspec(dllimport)
	#endif
#else
	#error NTN only supports Windows!
#endif 

#ifdef NTN_ENABLE_ASSERTS
	#define NTN_CORE_ASSERT(condition, ...) { if(!(condition)) { NTN_ERROR("Assertion failed!")} }
	#define NTN_ASSERT(condition, ...) { if(!(condition)) { NTN_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); NTN_DEBUG_BREAK; } }
#else
	#define NTN_CORE_ASSERT(condition, ...)
	#define NTN_ASSERT(condition, ...)
#endif

#define BIT(x) (1 <<x)
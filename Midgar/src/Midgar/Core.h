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

#ifdef MG_ENABLE_ASSERTS
	#define MG_ASSERT(x, ...) { if (!(x)) { MG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MG_CORE_ASSERT(x, ...) { if (!(x)) { MG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MG_ASSERT(x, ...)
	#define MG_CORE_ASSERT(x, ...)
#endif

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
#define BIT(x) (1 << x)

//struct Vec2
//{
//	float x, y;
//	Vec2() { x = y = 0.0f; }
//	Vec2(float _x, float _y) { x = _x; y = _y; }
//};
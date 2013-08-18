#ifndef _KOVAN_COMPAT_HPP_
#define _KOVAN_COMPAT_HPP_

#ifdef _MSC_VER

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
typedef SSIZE_T ssize_t;
#define PRETTYFUNC __FUNCSIG__
#define YIELDFUNC() Sleep(0)
#define MICROSLEEP(x) Sleep((x) / 1000L)
#pragma section(".CRT$XCU", read)
#define INITIALIZER(f) \
   static void __cdecl f(void); \
   __declspec(allocate(".CRT$XCU")) void (__cdecl*f##_)(void) = f; \
   static void __cdecl f(void)

#else

#include <sched.h>
#define PRETTYFUNC __PRETTY_FUNCTION__
#define YIELDFUNC() sched_yield()
#define MICROSLEEP(x) usleep(x)
#define INITIALIZER(f) \
	static void f(void) __attribute__((constructor)); \
	static void f(void)

#endif

#endif
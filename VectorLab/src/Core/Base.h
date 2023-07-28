#pragma once

#if defined VL_PLATFORM_LINUX
    #include <signal.h>
    #define VL_DEBUG_BREAK { raise(SIGTRAP); }
#endif

#ifdef VL_DEBUG
    #define VL_ENABLE_ASSERTS
#endif

#ifdef VL_ENABLE_ASSERT
    #define VL_ASSERT(x, ...) { if(!(x)) {VL_ERROR("Assertion Failed: {0}",__VA_ARGS__); VL_DEBUG_BREAK} }
#else
    #define VL_ASSERT(x, ...)
#endif
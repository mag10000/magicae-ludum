#pragma once

// unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

//signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// boolean types
typedef int b32;
typedef char b8;

// properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// ensure all types are of the correct size
STATIC_ASSERT(sizeof(u8) == 1,"Expected u8 to be 1 byte");
STATIC_ASSERT(sizeof(u16) == 2,"Expected u16 to be 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4,"Expected u32 to be 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8,"Expected u64 to be 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1,"Expected i8 to be 1 byte");
STATIC_ASSERT(sizeof(i16) == 2,"Expected i16 to be 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4,"Expected i32 to be 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8,"Expected i64 to be 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4,"Expected f32 to be 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8,"Expected f64 to be 8 bytes");

#define TRUE 1
#define FALSE 0

//platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define KPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64 bit is required on windows!"
#endif
#elif defined(__linux__) || defined(__gnu_lunix__)
// lunix OS
#define KPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define KPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
//catch anything not caught by the above
#define 

// finish code timestamp: 10:24
//video url: https://www.youtube.com/watch?v=F6_WdnzQIQ4&list=PLv8Ddw9K0JPg1BEO-RS-0MYs423cvLVtj&index=3
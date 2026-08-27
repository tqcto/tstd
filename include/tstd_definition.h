#pragma once
#ifndef _TSTD_DEFINITION_H_
#define _TSTD_DEFINITION_H_

#ifndef DLL_EXPORT
//#ifdef _DLL
#ifndef defined(_MSC_VER)
#define DLL_EXPORT	__declspec(dllexport)
#else
#define DLL_EXPORT
#endif
#endif

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#include <stdbool.h>
#endif

typedef bool                t_bool;
typedef char                t_char;     // 1byte
typedef int16_t             t_short;    // 2byte
typedef int32_t             t_int;      // 4byte
typedef float               t_float;    // 4byte
typedef double              t_double;   // 8byte

typedef int64_t             t_int64;    // 8byte

typedef uint32_t            t_uint;     // 符号なし4byte
typedef unsigned char       t_uchar;    // 符号なし1byte
typedef uint64_t            t_uint64;   // 符号なし8byte

// if you use this macros then include Windows.h or define MAX_PATH 260
#ifndef TSTD_MAX_PATH_ANSI
#define TSTD_MAX_PATH_ANSI	MAX_PATH
//#define TSTD_MAX_PATH_ANSI  260
#endif
#ifndef TSTD_MAX_PATH_UNIC
#define TSTD_MAX_PATH_UNIC	(MAX_PATH >> 1)
//#define TSTD_MAX_PATH_UNIC  130
#endif

#ifdef _USE_TSTD_DEBUG_MACROS

#if _DEBUG

#define DEBUG_LOG	printf

/// include Windows.h ///
#define NEW_CONSOLE	AllocConsole()
#define DEL_CONSOLE	FreeConsole()
/// include Windows.h ///

#else

#define DEBUG_LOG
#define NEW_CONSOLE
#define DEL_CONSOLE

#endif

#endif

#endif
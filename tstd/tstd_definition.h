#pragma once
#ifndef _TSTD_DEFINITION_H_
#define _TSTD_DEFINITION_H_

#ifndef DLL_EXPORT
#ifdef _DLL
#define DLL_EXPORT	__declspec(dllexport)
#else
#define DLL_EXPORT
#endif
#endif

// if you use this macros then include Windows.h or define MAX_PATH 260
#ifndef TSTD_MAX_PATH_ANSI
#define TSTD_MAX_PATH_ANSI	MAX_PATH
#endif
#ifndef TSTD_MAX_PATH_UNIC
#define TSTD_MAX_PATH_UNIC	(MAX_PATH >> 1)
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
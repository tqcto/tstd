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
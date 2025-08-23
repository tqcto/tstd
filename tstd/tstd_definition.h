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
#else
#define DEBUG_LOG
#endif

#endif

#endif
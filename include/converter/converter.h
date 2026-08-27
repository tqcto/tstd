#ifndef _TSTD_CONVERTER_H_
#define _TSTD_CONVERTER_H_

#include "../tstd_definition.h"

#include <stdio.h>

DLL_EXPORT inline size_t char2wchar(t_char* src, wchar_t* dst);
DLL_EXPORT inline size_t wchar2char(wchar_t* src, t_char* dst);

#endif
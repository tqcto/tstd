#include "converter.h"

#include <stdbool.h>
#include <Windows.h>

inline size_t char2wchar(char* src, wchar_t* dst) {

	size_t dst_size;
	bool result = mbstowcs_s(&dst_size, dst, TSTD_MAX_PATH_UNIC, src, TSTD_MAX_PATH_ANSI);
	return dst_size;

}
inline size_t wchar2char(wchar_t* src, char* dst) {

	//std::wcstombs(dst, src, TSTD_PATH_LENGTH);
	size_t dst_size;
	wcstombs_s(&dst_size, dst, TSTD_MAX_PATH_ANSI, src, TSTD_MAX_PATH_UNIC);
	return dst_size;

}
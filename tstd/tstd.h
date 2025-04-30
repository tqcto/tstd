#pragma once
#ifndef _TSTD_H_
#define _TSTD_H_

#ifndef DLL_EXPORT
#define DLL_EXPORT	__declspec(dllexport)
#endif

#define ASCII_0	0x30	// 0x30はASCIIコードで'0'に対応する
#define ASCII_A	0x40

#ifdef __cplusplus
extern "C" {
#endif

	/**
	* @fn
	* @brief			10進数をp進数に基数変換
	* @param bufferP	基数変換後の各位の値を格納するメモリのポインタ
	* @param value		基数変換したい10進数
	* @param base		変換先の基数
	* @param str_size	桁の上限
	* @return			基数変換後の文字列ポインタ（str_sizeの範囲で計算できなかった場合は-1を返す）
	**/
	DLL_EXPORT unsigned char* convertDecimal(unsigned char* bufferP, int value, int base, unsigned int str_size);

	/**
	* @fn
	* @brief					10進数をp進法表記でコンソール上に表示
	* @param value_in_decimal	表示したい10進数
	* @param base				表示したい基数
	**/
	DLL_EXPORT void printd(int value_in_decimal, int base);

#ifdef __cplusplus
}
#endif

#endif

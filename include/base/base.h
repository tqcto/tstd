#include "../tstd_definition.h"

#ifndef _TSTD_BASE_H_
#define _TSTD_BASE_H_

/**
* @def
* @brief			convert2digit関数で基数変換した数値の桁数を計算
* @param bufferP	convert2digitに渡した第1引数
* @param convertedP	convert2digitの戻り値
* @param str_size	convert2digitに渡した第4引数
**/
#define length_in_convert2digit(bufferP, convertedP, str_size)	str_size - 1 - ( convertedP - bufferP )

/**
	* @fn
	* @brief			10進数をp進数に基数変換
	* @param bufferP	基数変換後の各位の値を格納するメモリのポインタ
	* @param value		基数変換したい10進数
	* @param base		変換先の基数
	* @param str_size	桁の上限
	* @return			基数変換後の文字列ポインタ（str_sizeの範囲で計算できなかった場合は-1を返す）
	**/
DLL_EXPORT unsigned char* convert2digit(unsigned char* bufferP, unsigned int value, unsigned int base, unsigned int str_size);

/**
* @fn
* @brief			p進数を10進数に基数変換
* @param digitP		p進数の文字列の先頭アドレス
* @param str_size	p進数の桁数
* @param base		変換前の基数
* @return			変換後の10進数
**/
DLL_EXPORT unsigned int convert2decimal(unsigned char* digitP, unsigned int str_size, unsigned int base);

/**
* @fn
* @brief					10進数をp進法表記でコンソール上に表示
* @param value_in_decimal	表示したい10進数
* @param base				表示したい基数
**/
DLL_EXPORT void printd(unsigned int value_in_decimal, unsigned int base);

#endif
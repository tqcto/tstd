#pragma once
#ifndef _TSTD_H_
#define _TSTD_H_

#ifndef DLL_EXPORT
#define DLL_EXPORT	__declspec(dllexport)
#endif

#define ASCII_0	0x3A	// 0x30はASCIIコードで'0'に対応する
#define ASCII_A	0x40

/**
* @fn
* @brief				10進数をp進法表記に基数変換
* @param convertedP		基数変換後の各位の値を格納するメモリのポインタ
* @param d				基数変換したい10進数
* @param p				変換先の基数
* @param buffer			桁の上限
* @return				正の整数値:基数変換後の桁数、-1:bufferの範囲で桁を計算しきれなかった
**/
DLL_EXPORT int convertDecimal(unsigned char* convertedP, int d, int p, int buffer);

/**
* @fn
* @brief	10進数をp進法表記でコンソール上に表示
* @param d	表示したい10進数
* @param p	表示したい基数
**/
//void printd(int d, int p);

#endif

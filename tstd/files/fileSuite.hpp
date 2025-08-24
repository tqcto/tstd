#pragma once
#ifndef _TSTD_FILE_SUITE_HPP_
#define _TSTD_FILE_SUITE_HPP_

#include "../tstd_definition.h"

#include <stdio.h>

typedef enum {

	INIT = 0,
	READ,
	WRITE

}fileSuiteOpeningMode;

class fileSuite {

private:

	// file pointer
	FILE* fp = nullptr;
	bool isFileOpened = false;

	fileSuiteOpeningMode opening_mode = INIT;

public:

	// コンストラクタ
	DLL_EXPORT fileSuite();
	/*
	* @fn
	* @brief			コンストラクタ・バイナリファイルを開く
	* @param filepath	バイナリファイルのファイルパス
	* @param mode		バイナリファイルの開き方
	*/
	DLL_EXPORT fileSuite(const char* filepath, fileSuiteOpeningMode mode);

	// デコンストラクタ
	DLL_EXPORT ~fileSuite();

	/*
	* @fn
	* @brief			バイナリファイルを開く
	* @param filepath	バイナリファイルのファイルパス
	* @param mode		バイナリファイルの開き方
	*/
	DLL_EXPORT void open(const char* filepath, fileSuiteOpeningMode mode);

	/*
	* @fn
	* @brief			バイナリファイルからデータを読み込む
	* @param dataP		読んだデータを格納するメモリのポインタ
	* @param elemSize	型のサイズ (ex: sizeof(unsigned char))
	* @param elemCount	配列の長さ
	*/
	DLL_EXPORT void read(void* dataP, size_t elemSize, size_t elemCount);

	/*
	* @fn
	* @brief			バイナリファイルにデータを書き込む
	* @param dataP		書き込むデータのメモリのポインタ
	* @param elemSize	型のサイズ (ex: sizeof(unsigned char))
	* @param elemCount	配列の長さ
	*/
	DLL_EXPORT void write(const void* dataP, size_t elemSize, size_t elemCount);

	/*
	* @fn
	* @brief ファイルを閉じる
	*/
	DLL_EXPORT void close();

};

#endif
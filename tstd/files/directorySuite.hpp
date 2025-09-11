#pragma once
#ifndef _TSTD_DIRECTORY_SUITE_H_
#define _TSTD_DIRECTORY_SUITE_H_

#include "../tstd_definition.h"

#include <stdio.h>
#include <Windows.h>				// define MAX_PATH
#include <Shlwapi.h>				// for PathFileExists
#pragma comment(lib, "Shlwapi.lib")	// for PathFileExists

typedef enum {

	NONE = 0,
	DIRECTORY_IS_NOT_EXIST

}directorySuiteErr;

class directorySuite {

private:

	wchar_t path[TSTD_MAX_PATH_UNIC];

	inline bool _isExist(const char* directory_path) const {

		return PathFileExistsA(directory_path);

	}
	inline bool _isExist(char* directory_path) const {

		return PathFileExistsA(directory_path);

	}
	inline bool _isExist(const wchar_t* directory_path) const {

		return PathFileExists(directory_path);

	}
	inline bool _isExist(wchar_t* directory_path) const {

		return PathFileExists(directory_path);

	}

public:

	/*
	* @fn
	* @brief				ディレクトリを開く
	* @param directory_path	開くディレクトリ
	*/
	DLL_EXPORT directorySuite(const char* directory_path);
	/*
	* @fn
	* @brief				ディレクトリを開く
	* @param directory_path	開くディレクトリ
	*/
	DLL_EXPORT directorySuite(char* directory_path);
	/*
	* @fn
	* @brief				ディレクトリを開く
	* @param directory_path	開くディレクトリ
	*/
	DLL_EXPORT directorySuite(const wchar_t* directory_path);
	/*
	* @fn
	* @brief				ディレクトリを開く
	* @param directory_path	開くディレクトリ
	*/
	DLL_EXPORT directorySuite(wchar_t* directory_path);

	// デコンストラクタ
	DLL_EXPORT ~directorySuite();

	/*
	* @fn
	* @brief	開いたディレクトリが存在するか確認
	* @return	ディレクトリが存在するか否か
	*/
	inline bool isExist() const {

		return this->_isExist(this->path);

	}

};

#endif
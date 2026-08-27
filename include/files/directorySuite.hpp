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

	inline t_bool _isExist(const t_char* directory_path) const {

		return PathFileExistsA(directory_path);

	}
	inline t_bool _isExist(t_char* directory_path) const {

		return PathFileExistsA(directory_path);

	}
	inline t_bool _isExist(const wchar_t* directory_path) const {

		return PathFileExists(directory_path);

	}
	inline t_bool _isExist(wchar_t* directory_path) const {

		return PathFileExists(directory_path);

	}

public:

	/*
	* @fn
	* @brief				�f�B���N�g�����J��
	* @param directory_path	�J���f�B���N�g��
	*/
	DLL_EXPORT directorySuite(const t_char* directory_path);
	/*
	* @fn
	* @brief				�f�B���N�g�����J��
	* @param directory_path	�J���f�B���N�g��
	*/
	DLL_EXPORT directorySuite(t_char* directory_path);
	/*
	* @fn
	* @brief				�f�B���N�g�����J��
	* @param directory_path	�J���f�B���N�g��
	*/
	DLL_EXPORT directorySuite(const wchar_t* directory_path);
	/*
	* @fn
	* @brief				�f�B���N�g�����J��
	* @param directory_path	�J���f�B���N�g��
	*/
	DLL_EXPORT directorySuite(wchar_t* directory_path);

	// �f�R���X�g���N�^
	DLL_EXPORT ~directorySuite();

	/*
	* @fn
	* @brief	�J�����f�B���N�g�������݂��邩�m�F
	* @return	�f�B���N�g�������݂��邩�ۂ�
	*/
	inline t_bool isExist() const {

		return this->_isExist(this->path);

	}

};

#endif
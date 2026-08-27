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
	t_bool isFileOpened = false;

	fileSuiteOpeningMode opening_mode = INIT;

public:

	// �R���X�g���N�^
	DLL_EXPORT fileSuite();
	/*
	* @fn
	* @brief			�R���X�g���N�^�E�o�C�i���t�@�C�����J��
	* @param filepath	�o�C�i���t�@�C���̃t�@�C���p�X
	* @param mode		�o�C�i���t�@�C���̊J����
	*/
	DLL_EXPORT fileSuite(const t_char* filepath, fileSuiteOpeningMode mode);

	// �f�R���X�g���N�^
	DLL_EXPORT ~fileSuite();

	/*
	* @fn
	* @brief			�o�C�i���t�@�C�����J��
	* @param filepath	�o�C�i���t�@�C���̃t�@�C���p�X
	* @param mode		�o�C�i���t�@�C���̊J����
	*/
	DLL_EXPORT void open(const t_char* filepath, fileSuiteOpeningMode mode);

	/*
	* @fn
	* @brief			�o�C�i���t�@�C������f�[�^��ǂݍ���
	* @param dataP		�ǂ񂾃f�[�^���i�[���郁�����̃|�C���^
	* @param elemSize	�^�̃T�C�Y (ex: sizeof(unsigned char))
	* @param elemCount	�z��̒���
	*/
	DLL_EXPORT void read(void* dataP, size_t elemSize, size_t elemCount);

	/*
	* @fn
	* @brief			�o�C�i���t�@�C���Ƀf�[�^����������
	* @param dataP		�������ރf�[�^�̃������̃|�C���^
	* @param elemSize	�^�̃T�C�Y (ex: sizeof(unsigned char))
	* @param elemCount	�z��̒���
	*/
	DLL_EXPORT void write(const void* dataP, size_t elemSize, size_t elemCount);

	/*
	* @fn
	* @brief �t�@�C�������
	*/
	DLL_EXPORT void close();

};

#endif
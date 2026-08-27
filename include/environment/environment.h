#pragma once
#ifndef _TSTD_ENVIRONMENT_H_
#define _TSTD_ENVIRONMENT_H_

#include "../tstd_definition.h"

#include <stdbool.h>	// use bool in C

// ���p�\��CPU�v���Z�b�T�[
typedef struct {

	t_bool SSE4_2;
	t_bool AVX2;
	t_bool AVX512F;

}availableProcessors;

/*
* @fn
* @brief	���p�\��CPU�v���Z�b�T�[���擾
* @return	CPU�v���Z�b�T�[���X�g
*/
DLL_EXPORT availableProcessors getAvailableProcessors();

/*
* @fn
* @brief			���s���ɉ������A���C�����g���擾
* @param processors	���p�\��CPU�v���Z�b�T�[���X�g
* @return			�A���C�����g
*/
DLL_EXPORT size_t getAlignment(availableProcessors processors);

#endif
#pragma once
#ifndef _TSTD_ENVIRONMENT_H_
#define _TSTD_ENVIRONMENT_H_

#include "../tstd_definition.h"

#include <stdbool.h>	// use bool in C

// 利用可能なCPUプロセッサー
typedef struct {

	bool SSE4_2;
	bool AVX2;
	bool AVX512F;

}availableProcessors;

/*
* @fn
* @brief	利用可能なCPUプロセッサーを取得
* @return	CPUプロセッサーリスト
*/
availableProcessors DLL_EXPORT getAvailableProcessors();

#endif
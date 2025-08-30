#pragma once
#ifndef _TSTD_MEMORY_HANDLER_HPP_
#define _TSTD_MEMORY_HANDLER_HPP_

#include <stdlib.h>
#include <stdalign.h>	// for _aligned_malloc and _aligned_free

#include "../environment/environment.h"

// メモリハンドラ
template<typename T>class memoryHandler {

protected:

	availableProcessors processors;
	size_t alignment = 16; // 16 byte
	bool isUsing = false;
	bool isUsedAline = false;

public:

	T* data = nullptr;
	
	// コンストラクタ
	memoryHandler() {

		this->processors = getAvailableProcessors();
		this->alignment = getAlignment(this->processors);

	}

	// デコンストラクタ
	~memoryHandler() {

		if (this->isUsing) {
			this->release();
		}

	}

	/*
	* @fn
	* @brief	テンプレートに指定した型の単一メモリを確保
	* @return	確保したメモリのポインタ
	*/
	inline T* allocate() {

		this->data = reinterpret_cast<T*>(malloc(sizeof(T)));
		this->isUsing = true;

		return this->data;

	}

	/*
	* @fn
	* @brief				テンプレートに指定した型にarray_lengthで指定した長さのメモリを確保
	* @param array_length	確保する配列の長さ
	* @return				確保したメモリのポインタ
	*/
	inline T* allocate(size_t array_length) {

		this->data = reinterpret_cast<T*>(malloc(sizeof(T) * array_length));
		this->isUsing = true;

		return this->data;

	}

	/*
	* @fn
	* @brief	テンプレートに指定した型の単一メモリをアライメント考慮で確保
	* @return	確保したメモリのポインタ
	*/
	inline T* allocateAligned() {

		this->data = (T*)_aligned_malloc(sizeof(T), this->alignment);
		this->isUsing = true;
		this->isUsedAline = true;

		return this->data;

	}

	/*
	* @fn
	* @brief				テンプレートに指定した型にarray_lengthで指定した長さのメモリをアライメント考慮で確保
	* @param array_length	確保する配列の長さ
	* @return				確保したメモリのポインタ
	*/
	inline T* allocateAligned(size_t array_length) {

		//this->data = reinterpret_cast<T*>(malloc(sizeof(T) * array_length));
		this->data = (T*)_aligned_malloc(sizeof(T) * array_length, this->alignment);
		this->isUsing = true;
		this->isUsedAline = true;

		return this->data;

	}

	/*
	* @fn
	* @brief	メモリが使用中か否か
	* @return	使用中か否か
	*/
	inline bool getIsUsing() const {

		return this->isUsing;

	}

	/*
	* @fn
	* @brief	確保したメモリの解放
	*/
	inline void release() {

		if (this->isUsedAline) {
			_aligned_free(this->data);
		}
		else {
			free(this->data);
		}
		
		this->data = nullptr;
		this->isUsing = false;
		this->isUsedAline = false;

	}

};

#endif
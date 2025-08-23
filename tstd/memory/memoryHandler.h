#pragma once
#ifndef _TSTD_MEMORY_HANDLER_HPP_
#define _TSTD_MEMORY_HANDLER_HPP_

#include <stdlib.h>

// メモリハンドラ
template<typename T>class memoryHandler {

private:

	T* data = nullptr;
	bool isUsing = false;

public:

	// コンストラクタ
	memoryHandler() {



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
	* @brief	確保したメモリのポインタを取得
	* @return	確保したメモリのポインタ
	*/
	inline T* getDataP() const {

		return this->data;

	}

	/*
	* @fn
	* @brief	確保したメモリの解放
	*/
	inline void release() {

		free(this->data);
		this->isUsing = false;

	}

};

#endif
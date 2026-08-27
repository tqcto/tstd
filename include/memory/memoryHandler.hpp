#pragma once
#ifndef _TSTD_MEMORY_HANDLER_HPP_
#define _TSTD_MEMORY_HANDLER_HPP_

#include <stdlib.h>
#include <stdalign.h>	// for _aligned_malloc and _aligned_free

#include "../../include/environment/environment.h"

// �������n���h��
template<typename T>class memoryHandler {

protected:

	availableProcessors processors;
	size_t alignment = 16; // 16 byte
	t_bool isUsing = false;
	t_bool isUsedAline = false;

public:

	T* data = nullptr;
	
	// �R���X�g���N�^
	memoryHandler() {

		this->processors = getAvailableProcessors();
		this->alignment = getAlignment(this->processors);

	}

	// �f�R���X�g���N�^
	~memoryHandler() {

		if (this->isUsing) {
			this->release();
		}

	}

	/*
	* @fn
	* @brief	�e���v���[�g�Ɏw�肵���^�̒P�ꃁ�������m��
	* @return	�m�ۂ����������̃|�C���^
	*/
	inline T* allocate() {

		this->data = reinterpret_cast<T*>(malloc(sizeof(T)));
		this->isUsing = true;

		return this->data;

	}

	/*
	* @fn
	* @brief				�e���v���[�g�Ɏw�肵���^��array_length�Ŏw�肵�������̃��������m��
	* @param array_length	�m�ۂ���z��̒���
	* @return				�m�ۂ����������̃|�C���^
	*/
	inline T* allocate(size_t array_length) {

		this->data = reinterpret_cast<T*>(malloc(sizeof(T) * array_length));
		this->isUsing = true;

		return this->data;

	}

	/*
	* @fn
	* @brief	�e���v���[�g�Ɏw�肵���^�̒P�ꃁ�������A���C�����g�l���Ŋm��
	* @return	�m�ۂ����������̃|�C���^
	*/
	inline T* allocateAligned() {

		this->data = (T*)_aligned_malloc(sizeof(T), this->alignment);
		this->isUsing = true;
		this->isUsedAline = true;

		return this->data;

	}

	/*
	* @fn
	* @brief				�e���v���[�g�Ɏw�肵���^��array_length�Ŏw�肵�������̃��������A���C�����g�l���Ŋm��
	* @param array_length	�m�ۂ���z��̒���
	* @return				�m�ۂ����������̃|�C���^
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
	* @brief	���������g�p�����ۂ�
	* @return	�g�p�����ۂ�
	*/
	inline t_bool getIsUsing() const {

		return this->isUsing;

	}

	/*
	* @fn
	* @brief	�m�ۂ����������̉��
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
#pragma once
#ifndef _TSTD_MEASURE_HPP_
#define _TSTD_MEASURE_HPP_

#include <time.h>

#include <utility>		// std::forward

// CPU���Ԃŏ������Ԃ̌v�����s���N���X
class measureCPU {

private:

	clock_t start_clock, end_clock;

public:

	// �R���X�g���N�^
	measureCPU() {

	}

	// �f�R���X�g���N�^
	~measureCPU() {

	}

	/*
	* @fn
	* @brief	�v���J�n
	*/
	inline void start() {

		this->start_clock = clock();

	}

	/*
	* @fn
	* @brief	�v���I��
	* @return	�v����������
	*/
	inline t_double end() {

		this->end_clock = clock();
		return this->getTime();

	}

	/*
	* @fn
	* @brief	�v���������Ԃ̎擾
	* @return	�v����������
	*/
	inline t_double getTime() const {

		return (t_double)(this->end_clock - this->start_clock) / CLOCKS_PER_SEC;

	}

	/*
	* @fn
	* @brief		�^����ꂽ�֐��̕��ώ��s���Ԃ��v��
	* @param func	�v������֐�
	* @param args	�֐��̈������X�g
	* @param count	�v����
	* @return		���ώ��s����
	*/
	template<typename Func, typename ... Args> double measure(Func func, Args ... args, t_uint count) {

		t_double sum = 0.0;

		for (t_int i = 0; i < count; i++) {

			this->start();

			std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

			sum += this->end();

		}

		return sum / (t_double)(count);

	}

};

// �������Ԃŏ������Ԃ̌v�����s���N���X
class measureTime {

private:

	time_t start_time, end_time;

public:

	// �R���X�g���N�^
	measureTime() {

	}

	// �f�R���X�g���N�^
	~measureTime() {

	}

	/*
	* @fn
	* @brief	�v���J�n
	*/
	inline void start() {

		this->start_time = time(NULL);

	}

	/*
	* @fn
	* @brief	�v���I��
	* @return	�v���������ԁi�b�P�ʁj
	*/
	inline t_double end() {

		this->end_time = time(NULL);
		return this->getTime();

	}

	/*
	* @fn
	* @brief	�v���������Ԃ̎擾
	* @return	�v���������ԁi�b�P�ʁj
	*/
	inline t_double getTime() const {

		return (t_double)(this->end_time - this->start_time);

	}

	/*
	* @fn
	* @brief		�^����ꂽ�֐��̕��ώ��s���Ԃ��v��
	* @param func	�v������֐�
	* @param args	�֐��̈������X�g
	* @param count	�v����
	* @return		���ώ��s����
	*/
	template<typename Func, typename ... Args> double measure(Func func, Args ... args, int count) {

		t_double sum = 0.0;

		for (t_int i = 0; i < count; i++) {

			this->start();

			std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

			sum += this->end();

		}

		return sum / (t_double)(count);

	}

};

#endif
#pragma once
#ifndef _TSTD_DEBUG_H_
#define _TSTD_DEBUG_H_

#include <time.h>
#include <stdarg.h>

#include <functional>
#include <utility>		// std::forward

// CPU時間で処理時間の計測を行うクラス
class measureCPU {

private:

	clock_t start_clock, end_clock;

public:

	// コンストラクタ
	measureCPU() {

	}

	// デコンストラクタ
	~measureCPU() {

	}

	/*
	* @fn
	* @brief	計測開始
	*/
	inline void start() {

		this->start_clock = clock();

	}

	/*
	* @fn
	* @brief	計測終了
	* @return	計測した時間
	*/
	inline double end() {

		this->end_clock = clock();
		return this->getTime();

	}

	/*
	* @fn
	* @brief	計測した時間の取得
	* @return	計測した時間
	*/
	inline double getTime() const {

		return (double)(this->end_clock - this->start_clock) / CLOCKS_PER_SEC;

	}

	/*
	* @fn
	* @brief		与えられた関数の平均実行時間を計測
	* @param func	計測する関数
	* @param args	関数の引数リスト
	* @param count	計測回数
	* @return		平均実行時間
	*/
	template<typename Func, typename ... Args> double measure(Func func, Args ... args, int count) {

		double sum = 0.0;

		for (int i = 0; i < count; i++) {

			this->start();

			std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);

			sum += this->end();

		}

		return sum / (double)(count);

	}

};

// 現実時間で処理時間の計測を行うクラス
class measureTime {

private:

	time_t start_time, end_time;

public:

	// コンストラクタ
	measureTime() {

	}

	// デコンストラクタ
	~measureTime() {

	}

	/*
	* @fn
	* @brief	計測開始
	*/
	inline void start() {

		this->start_time = time(NULL);

	}

	/*
	* @fn
	* @brief	計測終了
	* @return	計測した時間（秒単位）
	*/
	inline double end() {

		this->end_time = time(NULL);
		return this->getTime();

	}

	/*
	* @fn
	* @brief	計測した時間の取得
	* @return	計測した時間（秒単位）
	*/
	inline double getTime() const {

		return (double)(this->end_time - this->start_time);

	}

};

#endif
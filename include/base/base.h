#include "../tstd_definition.h"

#ifndef _TSTD_BASE_H_
#define _TSTD_BASE_H_

/**
* @def
* @brief			convert2digit�֐��Ŋ�ϊ��������l�̌������v�Z
* @param bufferP	convert2digit�ɓn������1����
* @param convertedP	convert2digit�̖߂�l
* @param str_size	convert2digit�ɓn������4����
**/
#define length_in_convert2digit(bufferP, convertedP, str_size)	str_size - 1 - ( convertedP - bufferP )

/**
	* @fn
	* @brief			10�i����p�i���Ɋ�ϊ�
	* @param bufferP	��ϊ���̊e�ʂ̒l���i�[���郁�����̃|�C���^
	* @param value		��ϊ�������10�i��
	* @param base		�ϊ���̊
	* @param str_size	���̏��
	* @return			��ϊ���̕�����|�C���^�istr_size�͈̔͂Ōv�Z�ł��Ȃ������ꍇ��-1��Ԃ��j
	**/
DLL_EXPORT t_uchar* convert2digit(t_uchar* bufferP, t_uint value, t_uint base, t_uint str_size);

/**
* @fn
* @brief			p�i����10�i���Ɋ�ϊ�
* @param digitP		p�i���̕�����̐擪�A�h���X
* @param str_size	p�i���̌���
* @param base		�ϊ��O�̊
* @return			�ϊ����10�i��
**/
DLL_EXPORT t_uint convert2decimal(t_uchar* digitP, t_uint str_size, t_uint base);

/**
* @fn
* @brief					10�i����p�i�@�\�L�ŃR���\�[����ɕ\��
* @param value_in_decimal	�\��������10�i��
* @param base				�\���������
**/
DLL_EXPORT void printd(t_uint value_in_decimal, t_uint base);

#endif
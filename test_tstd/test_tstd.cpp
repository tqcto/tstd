#include "tstd.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/*
	unsigned int value_in_decimal	= 300;
	unsigned int base				= 16;

	unsigned int str_size = 1 << 8;
	unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char) * str_size);

	unsigned char* converted = convert2digit(buffer, value_in_decimal, base, str_size);
	if (converted == NULL) return -1;

	printf("string:%s, length:%d\n", converted, length_in_convert2digit(buffer, converted, str_size));
	*/

	unsigned char*	digit		= (unsigned char*)"AA3F";
	unsigned int	str_size	= 4;
	printf("0x%s -> %d\n", digit, convert2decimal(digit, str_size, 16));

	return 0;

}
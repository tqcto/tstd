#include "tstd.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned char* convert2digit(unsigned char* bufferP, unsigned int value, unsigned int base, unsigned int str_size) {

	bufferP += str_size;
	*--bufferP = '\0';

	for (int i = 0; i < str_size; i++) {

		unsigned char digit = (unsigned char)(value % base);
		*--bufferP = (digit < 10 ? '0' : 'A' - 10) + digit;

		value /= base;

		if (value == 0)	return bufferP;

	}

	return NULL;

}

unsigned int convert2decimal(unsigned char* digitP, unsigned int str_size, unsigned int base) {

	unsigned int result = 0;

	for (int i = 0; i < str_size; i++) {

		unsigned char tmp = *(digitP + sizeof(unsigned char) * i);
		int char2int = (tmp >= 'A' ? 10 - 'A' : - '0') + tmp;
		result += pow(base, str_size - 1 - i) * char2int;

	}
	
	return result;

}

void printd(unsigned int value_in_decimal, unsigned int base) {

	unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char) * (1 << 8));
	unsigned char* converted = convert2digit(buffer, value_in_decimal, base, 1 << 8);
	if (converted == NULL) {

		printf("printd: couldn't calculate order.\n");
		return;

	}

	printf("%s\n", converted);

	free(buffer);

}

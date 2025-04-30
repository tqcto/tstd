#include "tstd.h"

#include <stdio.h>
#include <stdlib.h>

unsigned char* convertDecimal(unsigned char* bufferP, unsigned int value, unsigned int base, unsigned int str_size) {

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

void printd(unsigned int value_in_decimal, unsigned int base) {

	unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char) * (1 << 8));
	unsigned char* converted = convertDecimal(buffer, value_in_decimal, base, 1 << 8);
	if (converted == NULL) {

		printf("printd: couldn't calculate order.\n");
		return;

	}

	printf("%s\n", converted);

	free(buffer);

}

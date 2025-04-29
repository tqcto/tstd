#include "tstd.h"

int convertDecimal(unsigned char* convertedP, int d, int p, int buffer) {

	for (int i = 0; i < buffer; i++) {

		unsigned char tmp = ASCII_0 + d % p;
		*(convertedP + sizeof(unsigned char) * i) = tmp >= 0x3A ? ASCII_A + tmp - 0b111001 : tmp;

		d /= p;

		if (d == 0)	return i + 1;

	}

	return -1;

}

/*
void printd(int d, int p) {

	unsigned char* converted = (unsigned char*)malloc(sizeof(unsigned char) * (1 << 8));
	int buf = convertDecimal(converted, d, p, 1 << 8);
	if (buf == -1) {

		printf("printd: couldn't calculate order.\n");
		return;

	}

	for (int i = 0; i < buf; i++) {

		printf("%c", converted[buf - 1 - i]);

	}

	free(converted);

}
*/

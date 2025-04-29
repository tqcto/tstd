#include "tstd.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int d = 200;
	int p = 16;

	int buf = 1 << 8;
	unsigned char* converted = (unsigned char*)malloc(sizeof(unsigned char) * buf);
	buf = convertDecimal(converted, d, p, buf);
	if (buf == -1) {

		printf("printd: couldn't calculate order.\n");
		return -1;

	}

	for (int i = 0; i < buf; i++) {

		printf("%c", converted[buf - 1 - i]);

	}

	free(converted);

	return 0;

}
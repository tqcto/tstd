#include "../../include/base/base.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_uchar* convert2digit(t_uchar* bufferP, t_uint value, t_uint base, t_uint str_size) {

	bufferP += str_size;
	*--bufferP = '\0';

	for (t_int i = 0; i < str_size; i++) {

		t_uchar digit = (t_uchar)(value % base);
		*--bufferP = (digit < 10 ? '0' : 'A' - 10) + digit;

		value /= base;

		if (value == 0)	return bufferP;

	}

	return NULL;

}

t_uint convert2decimal(t_uchar* digitP, t_uint str_size, t_uint base) {

	t_uint result = 0;

	for (t_int i = 0; i < str_size; i++) {

		t_uchar tmp = *(digitP + sizeof(t_uchar) * i);
		t_int char2int = (tmp >= 'A' ? 10 - 'A' : -'0') + tmp;
		result += pow(base, str_size - 1 - i) * char2int;

	}

	return result;

}

void printd(t_uint value_in_decimal, t_uint base) {

	t_uchar* buffer = (t_uchar*)malloc(sizeof(t_uchar) * (1 << 8));
	t_uchar* converted = convert2digit(buffer, value_in_decimal, base, 1 << 8);
	if (converted == NULL) {

		printf("printd: couldn't calculate order.\n");
		return;

	}

	printf("%s\n", converted);

	free(buffer);

}

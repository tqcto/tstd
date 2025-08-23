#define _USE_TSTD_DEBUG_MACROS // use debug macros for tstd
#include "tstd.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <Windows.h>

void test_Printb() {

	/*
	unsigned int value_in_decimal	= 300;
	unsigned int base				= 16;

	unsigned int str_size = 1 << 8;
	unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char) * str_size);

	unsigned char* converted = convert2digit(buffer, value_in_decimal, base, str_size);
	if (converted == NULL) return -1;

	printf("string:%s, length:%d\n", converted, length_in_convert2digit(buffer, converted, str_size));
	*/

	unsigned char* digit = (unsigned char*)"AA3F";
	unsigned int	str_size = 4;
	printf("0x%s -> %d\n", digit, convert2decimal(digit, str_size, 16));

}

void test_memoryHandler() {

	memoryHandler<int> handle;
	int* dataP = handle.allocate();

	DEBUG_LOG("%d\n", *dataP);

	*dataP = 0;

	DEBUG_LOG("%d\n", *dataP);

}

void tset_fileSuite() {

	size_t size = 1 << 8;

	memoryHandler<unsigned char> memHandle;
	unsigned char* data = memHandle.allocate(size);

	for (int i = 0; i < size; i++) {
		data[i] = i;
	}

	fileSuite file("test.tmp", fileSuiteOpeningMode::WRITE);
	file.write(data, sizeof(unsigned char), size);
	file.close();

}

template<typename T> void test(T arg, ...) {

	va_list args;
	va_start(args, arg);

	// show first
	printf("%d\n", arg);

	while (true) {

	}

}

int main(void) {

	measureCPU measure;
	printf("%lf\n", measure.measure(test_memoryHandler, 1000));

	/*
	availableProcessors processors = getAvailableProcessors();

	measureCPU measure;
	measure.start();
	tset_fileSuite();
	printf("計測時間(CPU):%lf\n", measure.end());
	*/

	return 0;

}
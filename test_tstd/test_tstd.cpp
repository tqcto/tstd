#define _USE_TSTD_DEBUG_MACROS // use debug macros for tstd
#include "tstd.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>

#include <Windows.h>

void test_printb() {

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

	DEBUG_LOG("%p\n", dataP);

	*dataP = 0;

	DEBUG_LOG("%d\n", *dataP);

}

void test_fileSuite() {

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

void test_directorySuite() {

	directorySuite dir("..\\tstd\\");
	printf("%s\n", dir.isExist() ? "true" : "false");

}

void test_simdVector() {



}

class wndProcC : public windowProcedure {

public:

	LRESULT handleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override {

		switch (message) {

		case WM_PAINT:
			return 0;

		case WM_LBUTTONDOWN:
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		default:
			return DefWindowProcA(hWnd, message, wParam, lParam);

		}

		return 0;

	}

};
void test_window() {

	wndProcC wndProcClass;

	window win;
	win.setup(
		CS_HREDRAW | CS_VREDRAW,
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		"test",
		&wndProcClass
	);
	win.create("test", 100, 100, 500, 500);
	win.show();

}

int main(void) {

	test_window();

	return 0;

}
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
	static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

		switch (message) {

		case WM_LBUTTONUP:
		case WM_DESTROY:
			MessageBoxA(hWnd, "exit.", "!!", MB_OK);
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProcA(hWnd, message, wParam, lParam);

		}

		return 0;

	}

	int messageLoop(MSG* msgP, HWND hWnd) {

		bool ret;
		while ((ret = GetMessageA(msgP, hWnd, 0, 0)) != 0) {

			if (ret == -1) {
				return ret;
			}
			if (msgP->message == WM_LBUTTONUP) {

				break;

			}

			DispatchMessageA(msgP);

		}

		return (int)msgP->wParam;

	}

};
void test_window() {

	wndProcC wndProcClass;

	window win;
	win.setup(NULL, NULL, NULL, NULL, "test", &wndProcClass);
	win.create("test", 100, 100, 500, 500);
	win.show();

}

int main(void) {

	test_window();

	return 0;

}
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

class wndProcC : public wndProcInterface {

private:

	unsigned char* render_data = nullptr;
	const int channels = 4;
	size_t pitch = 0;

public:

	LRESULT OnSize(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

		DEBUG_LOG("size\n");

		size_t pitch = (width * channels + 15) & ~15;

		if (render_data != nullptr) {

			_aligned_free(render_data);
			render_data = nullptr;

		}

		render_data = (unsigned char*)_aligned_malloc(sizeof(unsigned char) * pitch * height, 16);
		memset(render_data, 0, sizeof(unsigned char) * pitch * height);

		return 0;

	}

	LRESULT OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

		DEBUG_LOG("paint\n");
		
		BITMAPINFO bmi;
		PAINTSTRUCT ps;

		HDC hdc = BeginPaint(hWnd, &ps);

		memset(&bmi, 0, sizeof(bmi));
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biWidth = width;
		bmi.bmiHeader.biHeight = -height;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 8 * channels;
		bmi.bmiHeader.biCompression = BI_RGB;

		StretchDIBits(
			hdc,
			0, 0, width, height,
			0, 0, width, height,
			render_data, &bmi,
			DIB_RGB_COLORS, SRCCOPY
		);

		EndPaint(hWnd, &ps);

		return 0;

	}

	LRESULT handleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override {

		switch (message) {

		case WM_CREATE:
			
			return 0;

		case WM_SIZE:

			return this->OnSize(hWnd, message, wParam, lParam);

		case WM_PAINT:

			return this->OnPaint(hWnd, message, wParam, lParam);

		case WM_LBUTTONDOWN:
		case WM_DESTROY:

			if (render_data) {
				_aligned_free(render_data);
				render_data = nullptr;
			}
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
	win.create("test", 100, 100, 500, 500, 0x00);
	win.show();

}

void test_complex() {

	complex<double> c1(3.0, 4.0);
	complex<double> c2(1.0, 2.0);

	complex<double> result = 2.0 * c1;

	DEBUG_LOG("Result: (%f, %f)\n", result.real, result.imag);

}

int main(void) {

	//test_window();
	test_complex();

	return 0;

}
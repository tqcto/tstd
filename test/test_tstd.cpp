#define _USE_TSTD_DEBUG_MACROS // use debug macros for tstd
#include "../include/tstd.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>

#include <Windows.h>

#include <immintrin.h>

#include <thread>

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

	t_uchar* digit = (t_uchar*)"AA3F";
	t_uint	str_size = 4;
	printf("0x%s -> %d\n", digit, convert2decimal(digit, str_size, 16));

}

void test_memoryHandler() {

	memoryHandler<t_int> handle;
	t_int* dataP = handle.allocate();

	DEBUG_LOG("%p\n", dataP);

	*dataP = 0;

	DEBUG_LOG("%d\n", *dataP);

}

void test_fileSuite() {

	size_t size = 1 << 8;

	memoryHandler<unsigned char> memHandle;
	t_uchar* data = memHandle.allocate(size);

	for (t_int i = 0; i < size; i++) {
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

	t_uchar* render_data = nullptr;
	const t_int channels = 4;
	size_t pitch = 0;

public:

	LRESULT OnSize(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

		DEBUG_LOG("size\n");

		size_t pitch = (width * channels + 15) & ~15;

		if (render_data != nullptr) {

			_aligned_free(render_data);
			render_data = nullptr;

		}

		render_data = (t_uchar*)_aligned_malloc(sizeof(t_uchar) * pitch * height, 16);
		memset(render_data, 0, sizeof(t_uchar) * pitch * height);

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

void t1(double* vector, double scalar) {

	__m256d vec = _mm256_set_pd(4.0, 3.0, 2.0, 1.0);
	__m256d sca = _mm256_set1_pd(scalar);

	__m256d result = _mm256_mul_pd(vec, sca);

	_mm256_storeu_pd(vector, result);


}
void test_thread() {

	t_double* v1 = (t_double*)malloc(sizeof(t_double) << 2);
	t_double* v2 = (t_double*)malloc(sizeof(t_double) << 2);

	std::thread thread1(t1, v1, 1.0);
	std::thread thread2(t1, v2, 2.0);

	thread1.join();
	thread2.join();

	for (t_int i = 0; i < 4; i++) {
		DEBUG_LOG("v1[%d]: %lf, v2[%d]: %lf\n", i, v1[i], i, v2[i]);
	}

}

void test_complex() {

	complex<t_double> c1(3.0, 4.0);
	complex<t_double> c2(1.0, 2.0);

	complex<t_double> result = 2.0 * c1;

	DEBUG_LOG("Result: (%f, %f)\n", result.real, result.imag);

}

int main(void) {

	//test_window();
	//test_complex();
	test_thread();

	return 0;

}
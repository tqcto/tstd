#pragma once
#ifndef _TSTD_WINDOW_HPP_
#define _TSTD_WINDOW_HPP_

#include "../tstd_definition.h"
#include "windowProcedure.hpp"

#include <Windows.h>

class window {

private:

	WNDCLASSA wc;
	MSG msg;
	windowProcedure* wndProcClassP;

public:

	HWND hWnd = NULL;

	DLL_EXPORT window();
	DLL_EXPORT ~window();

	DLL_EXPORT int setup(
		unsigned long style,
		HICON icon,
		HCURSOR cursor,
		HBRUSH background_color,
		const char* class_name,
		windowProcedure* procedure
	);
	DLL_EXPORT void create(const char* title, int x, int y, int width, int height) noexcept;

	DLL_EXPORT void show();
	DLL_EXPORT void show(int cmd);


};

#endif
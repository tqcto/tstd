#pragma once
#ifndef _TSTD_WINDOW_HPP_
#define _TSTD_WINDOW_HPP_

#include "../tstd_definition.h"
#include "windowProcedure.hpp"

#include <Windows.h>

class window {

private:

	WNDCLASSEXA wc;
	MSG msg;
	wndProcInterface* wndProcClassP = nullptr;

public:

	HWND hWnd = NULL;

	DLL_EXPORT window();
	DLL_EXPORT ~window();

	DLL_EXPORT t_int setup(
		unsigned long style,
		HICON icon,
		HCURSOR cursor,
		HBRUSH background_color,
		const t_char* class_name,
		wndProcInterface* procedure
	);
	DLL_EXPORT void create(
		const t_char* title,
		t_int x, t_int y, t_int width, t_int height,
		unsigned long style
	) noexcept;

	DLL_EXPORT void show();
	DLL_EXPORT void show(t_int cmd);


};

#endif
#ifndef _TSTD_WINDOW_PROCEDURE_HPP_
#define _TSTD_WINDOW_PROCEDURE_HPP_

#include "../tstd_definition.h"

#include <Windows.h>

class wndProcInterface {

protected:

	// window rect
	t_int width = 0;
	t_int height = 0;

public:

	DLL_EXPORT static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	DLL_EXPORT virtual LRESULT handleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	DLL_EXPORT virtual t_int messageLoop(MSG* msgP, HWND hWnd);

};

#endif
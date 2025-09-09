#include "windowProcedure.hpp"

LRESULT CALLBACK windowProcedure::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcA(hWnd, message, wParam, lParam);

	}

	return 0;

}

int windowProcedure::messageLoop(MSG* msgP, HWND hWnd) {

	bool ret;
	while ((ret = GetMessageA(msgP, hWnd, 0, 0)) != 0) {

		if (ret == -1) {
			return ret;
		}

		DispatchMessageA(msgP);

	}

	return (int)msgP->wParam;

}
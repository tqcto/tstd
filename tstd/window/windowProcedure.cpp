#include "windowProcedure.hpp"

LRESULT CALLBACK wndProcInterface::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	wndProcInterface* thisP = nullptr;

	if (message == WM_NCCREATE) {

		CREATESTRUCTA* cs = reinterpret_cast<CREATESTRUCTA*>(lParam);
		thisP = static_cast<wndProcInterface*>(cs->lpCreateParams);
		SetWindowLongPtrA(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(thisP));

	}
	else {

		thisP = reinterpret_cast<wndProcInterface*>(GetWindowLongPtrA(hWnd, GWLP_USERDATA));

	}

	if (thisP) {

		switch (message) {

		case WM_CREATE:
		case WM_SIZE:
			thisP->width = LOWORD(lParam);
			thisP->height = HIWORD(lParam);
			InvalidateRect(hWnd, NULL, FALSE);
			break;

		// ダブルバッファリング防止
		case WM_ERASEBKGND:
			return 0;

		}

		return thisP->handleMessage(hWnd, message, wParam, lParam);

	}

	return DefWindowProcA(hWnd, message, wParam, lParam);

}

LRESULT wndProcInterface::handleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProcA(hWnd, message, wParam, lParam);

	}

	return 0;

}

int wndProcInterface::messageLoop(MSG* msgP, HWND hWnd) {

	while (GetMessageA(msgP, nullptr, 0, 0)) {

		TranslateMessage(msgP);
		DispatchMessageA(msgP);

	}

	return (int)msgP->wParam;

}
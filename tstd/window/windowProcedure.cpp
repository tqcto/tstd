#include "windowProcedure.hpp"

LRESULT CALLBACK windowProcedure::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	windowProcedure* thisP = nullptr;

	if (message == WM_NCCREATE) {

		CREATESTRUCTA* cs = reinterpret_cast<CREATESTRUCTA*>(lParam);
		thisP = static_cast<windowProcedure*>(cs->lpCreateParams);
		SetWindowLongPtrA(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(thisP));

	}
	else {

		thisP = reinterpret_cast<windowProcedure*>(GetWindowLongPtrA(hWnd, GWLP_USERDATA));

	}

	if (thisP) {

		return thisP->handleMessage(hWnd, message, wParam, lParam);

	}

	return DefWindowProcA(hWnd, message, wParam, lParam);

}

LRESULT windowProcedure::handleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProcA(hWnd, message, wParam, lParam);

	}

	return 0;

}

int windowProcedure::messageLoop(MSG* msgP, HWND hWnd) {

	while (GetMessageA(msgP, nullptr, 0, 0)) {

		TranslateMessage(msgP);
		DispatchMessageA(msgP);

	}

	return (int)msgP->wParam;

}
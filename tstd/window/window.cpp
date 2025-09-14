#include "window.hpp"

window::window() {



}

window::~window() {



}

int window::setup(
	unsigned long style,
	HICON icon,
	HCURSOR cursor,
	HBRUSH background_color,
	const char* class_name,
	wndProcInterface* procedure
) {

	this->wc.cbSize = sizeof(WNDCLASSEXA);

	this->wc.style = style;

	this->wc.lpfnWndProc = wndProcInterface::wndProc;
	
	this->wc.cbClsExtra = NULL;	// 追加メモリ領域の確保
	this->wc.cbWndExtra = NULL;	// 追加メモリ領域の確保

	this->wc.hInstance = GetModuleHandleA(nullptr);	// hInstance
	this->wc.hIcon = icon;
	this->wc.hCursor = cursor;
	this->wc.hbrBackground = background_color;
	this->wc.lpszMenuName = NULL;	// メニュー名
	this->wc.lpszClassName = class_name;	// ex: takt_application

	if (!RegisterClassExA(&wc)) {
		return -1;
	}

	this->wndProcClassP = procedure;

	return 0;

}

void window::create(const char* title, int x, int y, int width, int height, unsigned long style) noexcept{

	this->hWnd = CreateWindowA(

		this->wc.lpszClassName,
		title,
		WS_OVERLAPPEDWINDOW | style,	// style
		x, y,
		width, height,
		NULL,	// parent window hwnd
		NULL,	// menu
		this->wc.hInstance,	// hInstance
		this->wndProcClassP	// lpParam

	);

}

void window::show() {

	ShowWindow(this->hWnd, SW_SHOWNORMAL);
	UpdateWindow(this->hWnd);
	this->wndProcClassP->messageLoop(&this->msg, this->hWnd);

}

void window::show(int cmd) {

	ShowWindow(this->hWnd, cmd);
	UpdateWindow(this->hWnd);
	this->wndProcClassP->messageLoop(&this->msg, this->hWnd);

}

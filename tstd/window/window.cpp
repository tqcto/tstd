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
	windowProcedure* procedure
) {

	this->wc.style = style;

	this->wc.lpfnWndProc = procedure->wndProc;
	this->wndProcClassP = procedure;

	this->wc.cbClsExtra = NULL;	// 追加メモリ領域の確保
	this->wc.cbWndExtra = NULL;	// 追加メモリ領域の確保

	this->wc.hInstance = NULL;	// hInstance
	this->wc.hIcon = icon;
	this->wc.hCursor = cursor;
	this->wc.hbrBackground = background_color;
	this->wc.lpszMenuName = NULL;	// メニュー名
	this->wc.lpszClassName = class_name;	// ex: takt_application

	return RegisterClassA(&wc);

}

void window::create(const char* title, int x, int y, int width, int height) noexcept{

	this->hWnd = CreateWindowA(

		this->wc.lpszClassName,
		title,
		WS_OVERLAPPEDWINDOW,	// style
		x, y,
		width, height,
		NULL,	// parent window hwnd
		NULL,	// menu
		NULL,	// hInstance
		NULL	// lpParam

	);

}

void window::show() {

	ShowWindow(this->hWnd, SW_SHOWNORMAL);
	this->wndProcClassP->messageLoop(&this->msg, this->hWnd);

}

void window::show(int cmd) {

	ShowWindow(this->hWnd, cmd);
	this->wndProcClassP->messageLoop(&this->msg, this->hWnd);

}

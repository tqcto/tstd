#include "../../include/window/window.hpp"

window::window() {



}

window::~window() {



}

t_int window::setup(
	unsigned long style,
	HICON icon,
	HCURSOR cursor,
	HBRUSH background_color,
	const t_char* class_name,
	wndProcInterface* procedure
) {

	this->wc.cbSize = sizeof(WNDCLASSEXA);

	this->wc.style = style;

	this->wc.lpfnWndProc = wndProcInterface::wndProc;
	
	this->wc.cbClsExtra = NULL;	// �ǉ��������̈�̊m��
	this->wc.cbWndExtra = NULL;	// �ǉ��������̈�̊m��

	this->wc.hInstance = GetModuleHandleA(nullptr);	// hInstance
	this->wc.hIcon = icon;
	this->wc.hCursor = cursor;
	this->wc.hbrBackground = background_color;
	this->wc.lpszMenuName = NULL;	// ���j���[��
	this->wc.lpszClassName = class_name;	// ex: takt_application

	if (!RegisterClassExA(&wc)) {
		return -1;
	}

	this->wndProcClassP = procedure;

	return 0;

}

void window::create(const t_char* title, t_int x, t_int y, t_int width, t_int height, unsigned long style) noexcept{

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

void window::show(t_int cmd) {

	ShowWindow(this->hWnd, cmd);
	UpdateWindow(this->hWnd);
	this->wndProcClassP->messageLoop(&this->msg, this->hWnd);

}

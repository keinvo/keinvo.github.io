#include "stdafx.h" // Includes windows.h and tchar.h
#include <atlbase.h>
#include <atlwin.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hinst,
					   HINSTANCE /*hinstPrev*/,
					   LPTSTR    pszCmdLine,
					   int       nCmdShow) {
	// Register the main window class
	LPCTSTR     pszMainWndClass = __T("HelloCWindowApp");
	WNDCLASSEX  wc = { sizeof(WNDCLASSEX) };
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance     = hinst;
	wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = pszMainWndClass;
	wc.lpfnWndProc   = WndProc;
	if( !RegisterClassEx(&wc) ) return -1;

	// Create the main window
	CWindow wnd;
	wnd.Create(pszMainWndClass, NULL, CWindow::rcDefault, 
        __T("Windows Application"), WS_OVERLAPPEDWINDOW);
	if (!wnd){ return -1; }

	// Show the main window
	wnd.ShowWindow(nCmdShow);
	wnd.UpdateWindow();

	// Main message loop
	MSG msg;
	while( GetMessage(&msg, 0, 0, 0) ) {
	   TranslateMessage(&msg);
	   DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT nMsg, WPARAM wparam,
						 LPARAM lparam) {
    CWindow wnd(hwnd);
    switch( nMsg ) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = wnd.BeginPaint(&ps);
            RECT rect = {0};
            wnd.GetClientRect(&rect);
            ::DrawText(hdc, __T("Hello, Windows"), -1, &rect,
              DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            wnd.EndPaint(&ps);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return ::DefWindowProc(hwnd, nMsg, wparam, lparam);
            break;
    }

	return 0;
}

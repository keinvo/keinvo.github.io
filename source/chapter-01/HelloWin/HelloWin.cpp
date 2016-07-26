#include "stdafx.h" // Includes windows.h and tchar.h
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hinst,
                    HINSTANCE /*hinstPrev*/,
                    LPTSTR pszCmdLine,
                    int nCmdShow) {
    LPCTSTR     pszMainWndClass = __T("HelloWinApp");
    WNDCLASSEX  wc = { sizeof(WNDCLASSEX) };
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hInstance = hinst;
    wc.hIcon = LoadIcon(0, IDI_APPLICATION);
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = pszMainWndClass;
    wc.lpfnWndProc = WndProc;
    if( !::RegisterClassEx(&wc) ) return -1;

	HWND hwnd = ::CreateWindowEx(WS_EX_CLIENTEDGE,
                            pszMainWndClass,
                            __T("Windows Application"),
                            WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, 0,
                            CW_USEDEFAULT, 0,
                            0, 0, hinst, 0);
    if( !hwnd ) return -1;

    ::ShowWindow(hwnd, nCmdShow);
    ::UpdateWindow(hwnd);

    MSG msg;
    while(::GetMessage(&msg, 0, 0, 0)) {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT nMsg, WPARAM wparam,LPARAM lparam) {
    switch( nMsg ) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = ::BeginPaint(hwnd, &ps);
        RECT rect; ::GetClientRect(hwnd, &rect);
        ::DrawText(hdc, __T("Hello Windows !"), -1, &rect, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        ::EndPaint(hwnd, &ps);
    }
    break;

    case WM_DESTROY:
        ::PostQuitMessage(0);
        break;

    default:
        return ::DefWindowProc(hwnd, nMsg, wparam, lparam);
        break;
    }

	return 0;
}

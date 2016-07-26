#include "stdafx.h" // Includes windows.h and tchar.h
#include "resource.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hinst,
                    HINSTANCE /*hinstPrev*/,
                    LPTSTR pszCmdLine,
                    int nCmdShow) {
    LPCTSTR pszMainWndClass = __T("HelloWinDlgApp");
    WNDCLASSEX wc = { sizeof(WNDCLASSEX) };
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hInstance = hinst;
    wc.hIcon = ::LoadIcon(0, IDI_APPLICATION);
    wc.hCursor = ::LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = pszMainWndClass;
    wc.lpfnWndProc = WndProc;
    wc.cbWndExtra = DLGWINDOWEXTRA;
    if( !::RegisterClassEx(&wc) ) return -1;

    HWND hwnd = ::CreateDialog (hinst, MAKEINTRESOURCE(IDD_DIALOG1), 0, NULL) ;
    if( !hwnd ) return -1;

    ::ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while( ::GetMessage(&msg, 0, 0, 0) ) {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT nMsg, WPARAM wparam,LPARAM lparam) {
    switch( nMsg ) {
    case WM_CLOSE:
        ::PostQuitMessage(0);
        break;
        
    case WM_DESTROY:
        ::PostQuitMessage(0);
        break;

    default:
        return ::DefWindowProc(hwnd, nMsg, wparam, lparam);
        break;
    }

    return ::DefWindowProc(hwnd, nMsg, wparam, lparam);
}   

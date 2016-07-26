#include "stdafx.h" // Includes windows.h and tchar.h
#include <atlbase.h>
#include <atlwin.h>

class CMainWindow : public CWindowImpl<CMainWindow>
{
public:
    virtual BOOL ProcessWindowMessage(HWND hwnd, UINT nMsg, WPARAM wparam,
                                    LPARAM lparam, LRESULT &lResult, DWORD /*dwMsgMapID*/) {
    BOOL bHandled = TRUE;
    
    switch( nMsg ) {
        case WM_PAINT: lResult = OnPaint(); break;
        case WM_DESTROY: lResult = OnDestroy(); break;
        default: bHandled = FALSE; break;
    }

	return bHandled;
  }

private:
    LRESULT OnPaint() {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(&ps);
        RECT rect; GetClientRect(&rect);
        DrawText(hdc, __T("Hello Windows !"), -1, &rect,
             DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        EndPaint(&ps);
        return 0;
    }
    LRESULT OnDestroy() {
        PostQuitMessage(0);
        return 0;
    }
};

int APIENTRY _tWinMain(HINSTANCE hinst,
					   HINSTANCE /*hinstPrev*/,
					   LPTSTR    pszCmdLine,
					   int       nCmdShow) {
    CMainWindow wnd;
    wnd.Create(0, CWindow::rcDefault, _T("CWindowImpl Demo"), WS_OVERLAPPEDWINDOW, WS_EX_CLIENTEDGE);
    if(!wnd) { return -1; }

    wnd.CenterWindow();
    wnd.ShowWindow(nCmdShow);
    wnd.UpdateWindow();

    MSG msg;
    while( GetMessage(&msg, 0, 0, 0) ) {
       TranslateMessage(&msg);
       DispatchMessage(&msg);
    }
  
	return msg.wParam;
}

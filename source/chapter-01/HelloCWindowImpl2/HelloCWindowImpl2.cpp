#include "stdafx.h" // Includes windows.h and tchar.h
#include <atlbase.h>
#include <atlwin.h>

class CMainWindow : public CWindowImpl<CMainWindow>
{
    BEGIN_MSG_MAP(CMainWindow)
	    MESSAGE_HANDLER(WM_PAINT, OnPaint)
    	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
    END_MSG_MAP()

private:
    LRESULT OnPaint(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(&ps);
        RECT rect; GetClientRect(&rect);
        ::DrawText(hdc, __T("Hello Windows !"), -1, &rect,
             DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        EndPaint(&ps);

        bHandled = TRUE;
        return 0;
    }
    LRESULT OnDestroy(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) {
        PostQuitMessage(0);

        bHandled = TRUE;
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

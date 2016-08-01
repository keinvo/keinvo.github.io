#include "stdafx.h" // Includes windows.h and tchar.h
#include <atlbase.h>
#include <atlwin.h>
#include "SkBitmap.h"
#include "skia\tools\Resources.h"

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

        SkBitmap bitmap;

        bool bRet = GetResourceAsBitmap("skia.png", &bitmap);

        BITMAPINFO bmi;
        memset(&bmi, 0, sizeof(bmi));
        bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth       = bitmap.width();
        bmi.bmiHeader.biHeight      = -bitmap.height();
        bmi.bmiHeader.biPlanes      = 1;
        bmi.bmiHeader.biBitCount    = 32;
        bmi.bmiHeader.biCompression = BI_RGB;
        bmi.bmiHeader.biSizeImage   = 0;

        bitmap.lockPixels();
        int ret = SetDIBitsToDevice(hdc,
                                    40, 30,
                                    bitmap.width(), bitmap.height(),
                                    0, 0,
                                    0, bitmap.height(),
                                    bitmap.getPixels(),
                                    &bmi,
                                    DIB_RGB_COLORS);
        (void)ret; // we're ignoring potential failures for now.
        bitmap.unlockPixels();

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
    wnd.Create(0, CWindow::rcDefault, _T("SkBitmap Demo"), WS_OVERLAPPEDWINDOW, WS_EX_CLIENTEDGE);
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

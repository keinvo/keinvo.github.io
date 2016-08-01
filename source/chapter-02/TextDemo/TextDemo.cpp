#include "stdafx.h" // Includes windows.h and tchar.h
#include <atlbase.h>
#include <atlwin.h>
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkRRect.h"
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
        bitmap.allocN32Pixels(480, 600);

        SkCanvas canvas(bitmap);
        Draw(&canvas);

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
                                    60, 30,
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

    void Draw(SkCanvas* canvas) {
        canvas->clear(SK_ColorWHITE);

        SkPaint paint1, paint2, paint3;

        paint1.setTextSize(64.0f);
        paint1.setAntiAlias(true);
        paint1.setColor(0xff4281A4);
        paint1.setStyle(SkPaint::kFill_Style);

        paint2.setTextSize(64.f);
        paint2.setAntiAlias(true);
        paint2.setColor(0xff9CAFB7);
        paint2.setStyle(SkPaint::kStroke_Style);
        paint2.setStrokeWidth(SkIntToScalar(3));

        paint3.setTextSize(64.0f);
        paint3.setAntiAlias(true);
        paint3.setColor(0xffE6B89C);
        paint3.setTextScaleX(SkFloatToScalar(1.5f));

        const char text[] = "Skia";
        canvas->drawText(text, strlen(text), 20.0f, 64.0f,  paint1);
        canvas->drawText(text, strlen(text), 20.0f, 144.0f, paint2);
        canvas->drawText(text, strlen(text), 20.0f, 224.0f, paint3);
    }
};

int APIENTRY _tWinMain(HINSTANCE hinst,
					   HINSTANCE /*hinstPrev*/,
					   LPTSTR    pszCmdLine,
					   int       nCmdShow) {
    CMainWindow wnd;
    wnd.Create(0, CWindow::rcDefault, _T("Text Demo"), WS_OVERLAPPEDWINDOW, WS_EX_CLIENTEDGE);
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

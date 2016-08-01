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
        bitmap.allocN32Pixels(760, 200);

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
        canvas->drawColor(SK_ColorLTGRAY);

        SkPaint paint;
        paint.setStyle(SkPaint::kFill_Style);
        paint.setStrokeWidth(4);
        paint.setColor(0xffFE938C);

        SkRect rect = SkRect::MakeXYWH(10, 10, 100, 160);
        canvas->drawRect(rect, paint);

        SkRRect oval;
        oval.setOval(rect);
        oval.offset(140, 0);
        paint.setColor(0xffE6B89C);
        canvas->drawRRect(oval, paint);

        paint.setColor(0xff9CAFB7);
        canvas->drawCircle(280, 50, 25, paint);

        rect.offset(360, 0);
        paint.setColor(0xff4281A4);
        paint.setStyle(SkPaint::kStroke_Style);
        canvas->drawRoundRect(rect, 10, 10, paint);

        canvas->translate(720, 0);
        canvas->rotate(60);
        rect = SkRect::MakeXYWH(0, 60, 90, 150);

        // paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kFill_Style);

        paint.setColor(0xff4281A4);
        canvas->drawRect(rect, paint);

        canvas->rotate(SkIntToScalar(20));
        paint.setColor(0xffFE938C);
        canvas->drawRect(rect, paint);
    }
};

int APIENTRY _tWinMain(HINSTANCE hinst,
					   HINSTANCE /*hinstPrev*/,
					   LPTSTR    pszCmdLine,
					   int       nCmdShow) {
    CMainWindow wnd;
    wnd.Create(0, CWindow::rcDefault, _T("SkCanvas Demo"), WS_OVERLAPPEDWINDOW, WS_EX_CLIENTEDGE);
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

#include "stdafx.h" // Includes windows.h and tchar.h
#include <atlbase.h>
#include <atlwin.h>
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkRRect.h"
#include "SkGradientShader.h"
#include "SkBlurMaskFilter.h"
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
        bitmap.allocN32Pixels(960, 600);

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
                                    20, 30,
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
        canvas->drawColor(SK_ColorWHITE);

        // SkGradientShader
        SkRect rect = SkRect::MakeXYWH(10, 10, 360, 180);

        SkPoint points[2] = {
            SkPoint::Make(0.0f, 0.0f),
            SkPoint::Make(0.0f, 256.0f)
        };
        SkColor colors[2] = {SK_ColorBLUE, SK_ColorYELLOW};
        SkPaint paint1;
        paint1.setShader(SkGradientShader::MakeLinear(
                            points, colors, nullptr, 2,
                            SkShader::kClamp_TileMode, 0, nullptr));
        canvas->drawRect(rect, paint1);

        rect.offset(400, 0);

        // ShShader
        SkMatrix matrix;
        matrix.setScale(1.0f, 1.0f);
        //matrix.preRotate(30.0f);

        SkBitmap bitmap;

        bool bRet = GetResourceAsBitmap("skia.png", &bitmap);
        SkPaint paint2;
        //paint2.setAntiAlias(true);
        paint2.setShader(SkShader::MakeBitmapShader(bitmap,
                                                   SkShader::kRepeat_TileMode,
                                                   SkShader::kRepeat_TileMode,
                                                   &matrix));
        canvas->drawRect(rect, paint2);

        // Radial Gradient Shader
        rect = SkRect::MakeXYWH(10, 200, 180, 180);

        SkPaint paint3;
        paint3.setShader(SkGradientShader::MakeRadial(
                            SkPoint::Make(100.0f, 290.0f), 90.0f,
                            colors, nullptr, 2, SkShader::kClamp_TileMode, 0, nullptr));
        canvas->drawRect(rect, paint3);

        // SkMaskFilter
        SkPaint paint4;
        paint4.setAntiAlias(true);
        paint4.setTextSize(120);
        paint4.setMaskFilter(SkBlurMaskFilter::Make(
                                kNormal_SkBlurStyle, 5.0f, 0));
        const char text[] = "Skia";
        canvas->drawText(text, strlen(text), 240, 340, paint4);

        // Emboss Mask Filter
        SkPaint paint5;
        paint5.setAntiAlias(true);
        paint5.setTextSize(120);
        SkScalar direction[3] = {1.0f, 1.0f, 1.0f};
        paint5.setMaskFilter(SkBlurMaskFilter::MakeEmboss(
                                2.0f, direction, 0.3f, 0.1f));

        canvas->drawText(text, strlen(text), 520, 340, paint5);
    }
};

int APIENTRY _tWinMain(HINSTANCE hinst,
					   HINSTANCE /*hinstPrev*/,
					   LPTSTR    pszCmdLine,
					   int       nCmdShow) {
    CMainWindow wnd;
    wnd.Create(0, CWindow::rcDefault, _T("SkPaint Demo"), WS_OVERLAPPEDWINDOW, WS_EX_CLIENTEDGE);
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

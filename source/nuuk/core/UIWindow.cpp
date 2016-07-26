#include "UIWindow.h"

UIWindow::UIWindow()
{
    m_szView.cx = 640;
    m_szView.cy = 480;

    m_rcView.l
}

UIWindow::~UIWindow()
{}

BOOL UIWindow::Create()
{
    Create(0, m_rcView, _T("UIWindow"), WS_POPUP);
}

LRESULT UIWindow::OnCreate(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    ModifyStyle(WS_CAPTION, 0);
    
    return 0;
}

LRESULT UIWindow::OnNcHitTest(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    return HTCAPTION;
}

LRESULT UIWindow::OnSize(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    INT width = LOWORD(lParam);
    INT height = HIWORD(lParam);
    this->resize(width, height);
    bHandled = TRUE;

    return 0;
}

LRESULT UIWindow::OnPaint(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	PAINTSTRUCT ps;
    HDC hdc = BeginPaint(&ps);
//    m_szBackgroundImg = "abc.png";
    this->forceInvalAll();
    this->doPaint(hdc);
    EndPaint(&ps);

    bHandled = TRUE;

    return 0;
}

LRESULT UIWindow::OnDestroy(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PostQuitMessage(0);
    bHandled = TRUE;

    return 0;
}

void UIWindow::doPaint(void* ctx) {
    this->update(NULL);

    HDC hdc = (HDC)ctx;
    const SkBitmap& bitmap = this->getBitmap();

    BITMAPINFO bmi;
    memset(&bmi, 0, sizeof(bmi));
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = bitmap.width();
    bmi.bmiHeader.biHeight      = -bitmap.height(); // top-down image
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage   = 0;

    //
    // Do the SetDIBitsToDevice.
    //
    // TODO(wjmaclean):
    //       Fix this call to handle SkBitmaps that have rowBytes != width,
    //       i.e. may have padding at the end of lines. The SkASSERT below
    //       may be ignored by builds, and the only obviously safe option
    //       seems to be to copy the bitmap to a temporary (contiguous)
    //       buffer before passing to SetDIBitsToDevice().
    SkASSERT(bitmap.width() * bitmap.bytesPerPixel() == bitmap.rowBytes());
    bitmap.lockPixels();
    int ret = SetDIBitsToDevice(hdc,
                                0, 0,
                                bitmap.width(), bitmap.height(),
                                0, 0,
                                0, bitmap.height(),
                                bitmap.getPixels(),
                                &bmi,
                                DIB_RGB_COLORS);
    (void)ret; // we're ignoring potential failures for now.
    bitmap.unlockPixels();

    return;
}

#include "NkWindow.h"
#include "skia\tools\Resources.h"

#define WM_EVENT_CALLBACK (WM_USER+0)

void post_skwinevent(HWND hwnd)
{
    PostMessage(hwnd, WM_EVENT_CALLBACK, 0, 0);
}

void SkEvent::SignalNonEmptyQueue()
{
}

static UINT_PTR gTimer;

VOID CALLBACK sk_timer_proc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    SkEvent::ServiceQueueTimer();
}

void SkEvent::SignalQueueTimer(SkMSec delay)
{
    if (gTimer)
    {
        KillTimer(NULL, gTimer);
        gTimer = NULL;
    }
    if (delay)
    {
        gTimer = SetTimer(NULL, 0, delay, sk_timer_proc);
    }
}

CNkWindow::CNkWindow()
    : m_szBackgroundImg(NULL)
{
    RECT rcDefault = {0, 0, 640, 480};
//    Create(0, rcDefault, _T("NkWindow"), WS_POPUP, WS_EX_LAYERED);
    Create(0, rcDefault, _T("NkWindow"), WS_POPUP);
    
    CenterWindow();
    ShowWindow(SW_SHOW);
    UpdateWindow();
}

CNkWindow::~CNkWindow()
{
}

int CNkWindow::RunMsgLoop()
{
    MSG msg;
    while( GetMessage(&msg, 0, 0, 0) ) {
       TranslateMessage(&msg);
       DispatchMessage(&msg);
    }

    return msg.wParam;
}

void CNkWindow::put_size(const SIZE &sz)
{
    MoveWindow(0, 0, sz.cx, sz.cy, TRUE);
    CenterWindow();

    return ;
}

void CNkWindow::put_background(LPCSTR szImgPath)
{
    m_szBackgroundImg = szImgPath;

    this->forceInvalAll();
    Invalidate();
    
    return ;
}

void CNkWindow::draw(SkCanvas *pCanvas)
{
    if(m_szBackgroundImg)
    {
        SkBitmap bitmap;
        bool bRet = GetResourceAsBitmap(m_szBackgroundImg, &bitmap);
        if(bRet)
        {
            pCanvas->drawBitmap(bitmap, 0, 0);
        }        
    }
    else
    {
        pCanvas->drawColor(SK_ColorWHITE);
    }
    
    return ;
}

LRESULT CNkWindow::OnCreate(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    ModifyStyle(WS_CAPTION, 0);
    
    return 0;
}

LRESULT CNkWindow::OnNcHitTest(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    return HTCAPTION;
}

LRESULT CNkWindow::OnSize(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{

    INT width = LOWORD(lParam);
    INT height = HIWORD(lParam);
    this->resize(width, height);
    bHandled = TRUE;

    return 0;
}

LRESULT CNkWindow::OnPaint(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
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

LRESULT CNkWindow::OnDestroy(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PostQuitMessage(0);
    bHandled = TRUE;

    return 0;
}

void CNkWindow::doPaint(void* ctx) {
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

#include "BasicControls.h"
#include "UILabel.h"
#include "UIButton.h"

CMainWindow::CMainWindow()
{}

CMainWindow::~CMainWindow()
{}

BOOL CMainWindow::OnInit()
{
    UILabel *pLabel = new(std::nothrow) UILabel();
    if(pLabel)
    {
        pLabel->put_parent(this);
        pLabel->put_marginType(UIMarginLeftTop);
        pLabel->put_margin(CRect(80, 60, 0, 0));
        pLabel->put_size(CSize(140, 40));
        pLabel->put_color(0xffffffff);
        pLabel->put_backgroundColor(0xff222222);
        pLabel->put_text(CComBSTR(L"Hello Label"));
    }

    UIButton *pCloseBtn = new(std::nothrow) UIButton();
    if(pCloseBtn)
    {
        pCloseBtn->put_parent(this);
        pCloseBtn->put_marginType(UIMarginRightTop);
        pCloseBtn->put_margin(CRect(0, 9, 9, 0));
        pCloseBtn->put_size(CSize(16, 16));
        pCloseBtn->put_normalBackground(L"btn_close.png");
    }

    return TRUE;
}

void CMainWindow::OnUninit()
{
    return ;
}

int APIENTRY _tWinMain(HINSTANCE hinst,
                       HINSTANCE /*hinstPrev*/,
                       LPTSTR    pszCmdLine,
                       int       nCmdShow) {
    CMainWindow wnd;
    wnd.put_background(L"abc.png");
    wnd.CreateWin();

    MSG msg;
    while( GetMessage(&msg, 0, 0, 0) ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

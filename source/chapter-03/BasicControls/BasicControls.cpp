#include "BasicControls.h"
#include "UILabel.h"

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

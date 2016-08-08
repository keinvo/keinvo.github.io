#include "BasicControls.h"
#include "UILabel.h"

CMainWindow::CMainWindow()
{}

CMainWindow::~CMainWindow()
{}

BOOL CMainWindow::AfterCreated()
{
    UILabel *pLabel = new(std::nothrow) UILabel();
    if(pLabel)
    {
		LPCTSTR pszText = L"Hello Label";
        pLabel->put_text(pszText);
        this->AddChild(pLabel);
    }

    return TRUE;
}

int APIENTRY _tWinMain(HINSTANCE hinst,
                       HINSTANCE /*hinstPrev*/,
                       LPTSTR    pszCmdLine,
                       int       nCmdShow) {
    UIWindow wnd;
    wnd.put_background("abc.png");
    wnd.CreateWin();

    MSG msg;
    while( GetMessage(&msg, 0, 0, 0) ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

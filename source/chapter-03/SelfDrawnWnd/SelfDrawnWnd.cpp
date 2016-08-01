#include "stdafx.h" // Includes windows.h and tchar.h

#include "UIWindow.h"

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

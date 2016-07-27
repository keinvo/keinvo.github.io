#include "stdafx.h" // Includes windows.h and tchar.h

// #define InterlockedIncrement64(x) (*x)

#include "NkWindow.h"

int APIENTRY _tWinMain(HINSTANCE hinst,
					   HINSTANCE /*hinstPrev*/,
					   LPTSTR    pszCmdLine,
					   int       nCmdShow) {
    CNkWindow wnd;
    wnd.put_background("abc.png");

    return wnd.RunMsgLoop();
}

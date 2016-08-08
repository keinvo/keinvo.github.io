#pragma once

#include "UIWindow.h"

class CMainWindow : public UIWindow
{
public:
    CMainWindow();
    ~CMainWindow();

protected:
    BOOL AfterCreated();
};

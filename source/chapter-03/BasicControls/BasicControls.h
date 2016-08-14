#pragma once

#include "UIWindow.h"

class CMainWindow : public UIWindow
{
public:
    CMainWindow();
    ~CMainWindow();

public:
    virtual BOOL OnInit();
    virtual void OnUninit();
};

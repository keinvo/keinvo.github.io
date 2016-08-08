#pragma once

#include <atlbase.h>
#include <atlwin.h>
#include "UIView.h"
#include "UICanvas.h"

class UIWindow
: public CWindowImpl<UIWindow>
, public UIView
{
 public:
    UIWindow();
    virtual ~UIWindow();

    void put_background(LPCTSTR szBackground);

    BOOL CreateWin();

    BEGIN_MSG_MAP(CNkWindow)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_NCHITTEST, OnNcHitTest)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        END_MSG_MAP()

        protected:
    LRESULT OnCreate(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnNcHitTest(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnSize(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnPaint(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnDestroy(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);

public:
    virtual BOOL AfterCreated();

private:
    void doPaint(HDC hdc);
    void OnDraw(CRect *pRect);

private:
    SkCanvas *m_pCanvas;
    CAtlString m_strBackground;
};

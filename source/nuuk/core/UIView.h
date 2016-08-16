#pragma once

#include <vector>
#include <windows.h>
#include <atltypes.h>
#include <atlstr.h>
#include "UIType.h"

enum UIMarginType
{
    UIMarginLeftTop = 0,
    UIMarginLeftCenter,
    UIMarginLeftBottom,
    UIMarginCenterTop,
    UIMarginCenter,
    UIMarginCenterBottom,
    UIMarginRightTop,
    UIMarginRightCenter,
    UIMarginRightBottom,
};

class UIView
{
 public:
    UIView();
    virtual ~UIView();

    HRESULT put_name(BSTR bsName);
    HRESULT get_name(BSTR *pbsName);

    HRESULT put_parent(UIView *pView);
    HRESULT get_parent(UIView **ppView);

    HRESULT put_marginType(UIMarginType type);
    HRESULT get_marginType(UIMarginType *pType);

    HRESULT put_margin(const RECT &rc);
    HRESULT get_margin(RECT *prc);

    HRESULT put_autoWidth(BOOL bAuto);
    HRESULT get_autoWidth(BOOL *pbAuto);

    HRESULT put_autoHeight(BOOL bAuto);
    HRESULT get_autoHeight(BOOL *pbAuto);

    HRESULT put_size(const SIZE &sz);
    HRESULT get_size(SIZE *psz);

    HRESULT put_rect(const RECT &rc);
    HRESULT get_rect(RECT *prc);

    void AddChild(UIView *pView);

    void Draw(CRect *pRect);

    virtual void  OnDraw(CRect *pRect) = 0;

protected:
    void Arrange();

protected:
    UIView *m_pParent;    // parent view
    std::vector<UIView *> m_vecChildren;    // vector of child views
    CComBSTR m_bsName;
    UIMarginType m_UIMarginType;
    CRect m_rcMargin;    // rect to parent
    CRect m_rcView;   // rect to window

    BOOL m_bAutoWidth;
    BOOL m_bAutoHeight;

    CSize m_szView;    // size
};

#pragma once

#include <vector>
#include <windows.h>
#include <atltypes.h>
#include <atlstr.h>

class UIView
{
 public:
    UIView();
    virtual ~UIView();

    HRESULT put_name(BSTR bsName);
    HRESULT get_name(BSTR *pbsName);

    HRESULT put_parent(UIView *pView);
    HRESULT get_parent(UIView **ppView);

    HRESULT put_size(const SIZE &sz);
    HRESULT get_size(SIZE *psz);

    HRESULT put_rect(const RECT &rc);
    HRESULT get_rect(RECT *prc);

    void AddChild(UIView *pView);

    void Draw(CRect *pRect);

    virtual void  OnDraw(CRect *pRect) = 0;

 protected:
    UIView *m_pParent;    // parent view
    std::vector<UIView *> m_vecChildren;    // vector of child views
    CComBSTR m_bsName;
	CRect m_rcView;    // rect
    CSize m_szView;    // size
};

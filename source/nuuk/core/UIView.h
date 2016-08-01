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

    void put_name(LPCSTR szName);
    void put_size(const SIZE &sz);
    void put_rect(const RECT &rc);

    void put_parent(UIView *pView);
    UIView *get_parent();

    void AddChild(UIView *pView);

    void Draw(CRect *pRect);

    virtual void  OnDraw(CRect *pRect) = 0;

 protected:
    UIView *m_pParent;    // parent view
    std::vector<UIView *> m_vecChildren;    // vector of child views
    CAtlString m_strName;
	CRect m_rcView;    // rect
    CSize m_szView;    // size
};

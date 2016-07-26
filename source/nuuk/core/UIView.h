#pragma once

class UIView
{
 public:
    UIView();
    virtual ~UIView();

    HRESULT OnDraw(CRect *pRect);

 protected:
    UIView *m_pParent;    // parent view
    std::vector<UIView *> m_vecChildren;    // vector of child views
	CRect m_rcView;    // rect
    CSize m_szView;    // size
};

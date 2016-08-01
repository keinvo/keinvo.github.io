#include "UIView.h"

UIView::UIView()
    : m_pParent(NULL)
{
}

UIView::~UIView()
{}

void UIView::put_parent(UIView *pView)
{
    m_pParent = pView;

    return ;
}

UIView *UIView::get_parent()
{
    return m_pParent;
}

void UIView::AddChild(UIView *pView)
{
    m_vecChildren.push_back(pView);

    return ;
}

void UIView::put_name(LPCSTR szName)
{
    m_strName = szName;

    return ;
}

void UIView::put_size(const SIZE &sz)
{
    m_szView = sz;

    return ;
}

void UIView::put_rect(const RECT &rc)
{
    m_rcView = rc;

    return ;
}

void UIView::Draw(CRect *pRect)
{
    this->OnDraw(pRect);

    for(size_t i=0; i<m_vecChildren.size(); ++i)
    {
        UIView *pChild = m_vecChildren[i];
        if(pChild)
        {
            pChild->Draw(NULL);
        }
    }
    return ;
}

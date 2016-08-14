#include "UIView.h"
#include "UICanvas.h"

UIView::UIView()
    : m_pParent(nullptr)
{
}

UIView::~UIView()
{}

HRESULT UIView::put_name(BSTR bsName)
{
    m_bsName = bsName;

    return S_OK;
}

HRESULT UIView::get_name(BSTR *pbsName)
{
    CComBSTR bsName = m_bsName;
    *pbsName = bsName.Detach();

    return S_OK;
}

HRESULT UIView::put_parent(UIView *pView)
{
    m_pParent = pView;
    if(pView)
    {
        pView->AddChild(this);
    }

    return S_OK;
}

HRESULT UIView::get_parent(UIView **ppView)
{
    *ppView = m_pParent;

    return S_OK;
}

HRESULT UIView::put_size(const SIZE &sz)
{
    m_szView = sz;

    return S_OK;
}

HRESULT UIView::get_size(SIZE *psz)
{
    *psz = m_szView;

    return S_OK;
}

HRESULT UIView::put_rect(const RECT &rc)
{
    m_rcView = rc;

    return S_OK;
}

HRESULT UIView::get_rect(RECT *prc)
{
    *prc = m_rcView;

    return S_OK;
}

void UIView::AddChild(UIView *pView)
{
    if(pView)
    {
        std::vector<UIView *>::const_iterator iter =
            std::find(m_vecChildren.begin(), m_vecChildren.end(), pView);
        if(iter == m_vecChildren.end())
        {
            m_vecChildren.push_back(pView);
            pView->put_parent(this);
        }
    }

    return ;
}


void UIView::Draw(CRect *pRect)
{
    UICanvas *pCanvas = CSingleton<UICanvas>::Instance();
    if(pCanvas)
    {
        SkCanvas *p = pCanvas->GetCanvas();
        if(p)
        {
            SkRect rc;
            rc.iset(m_rcView.left, m_rcView.top, m_rcView.right, m_rcView.bottom);
            p->clipRect(rc);
        }
    }

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

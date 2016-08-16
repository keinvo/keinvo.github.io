#include "UIView.h"
#include "UICanvas.h"

UIView::UIView()
    : m_pParent(nullptr)
    , m_UIMarginType(UIMarginLeftTop)
    , m_rcMargin(0, 0, 0, 0)
    , m_rcView(0, 0, 0, 0)
    , m_bAutoWidth(TRUE)
    , m_bAutoHeight(TRUE)
    , m_szView(0, 0)
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

    put_margin(CRect(0, 0, 0, 0));

    return S_OK;
}

HRESULT UIView::get_parent(UIView **ppView)
{
    *ppView = m_pParent;

    return S_OK;
}

HRESULT UIView::put_marginType(UIMarginType type)
{
    m_UIMarginType = type;

    return S_OK;
}

HRESULT UIView::get_marginType(UIMarginType *pType)
{
    *pType = m_UIMarginType;

    return S_OK;
}

HRESULT UIView::put_margin(const RECT &rc)
{
    m_rcMargin = rc;

    Arrange();

    return S_OK;
}

HRESULT UIView::get_margin(RECT *prc)
{
    *prc = m_rcView;

    return S_OK;
}

HRESULT UIView::put_autoWidth(BOOL bAuto)
{
    m_bAutoWidth = bAuto;
    return S_OK;
}

HRESULT UIView::get_autoWidth(BOOL *pbAuto)
{
    *pbAuto = m_bAutoWidth;
    return S_OK;
}

HRESULT UIView::put_autoHeight(BOOL bAuto)
{
    m_bAutoHeight = bAuto;
    return S_OK;
}

HRESULT UIView::get_autoHeight(BOOL *pbAuto)
{
    *pbAuto = m_bAutoHeight;
    return S_OK;
}

HRESULT UIView::put_size(const SIZE &sz)
{
    m_szView = sz;

    Arrange();

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

void UIView::Arrange()
{
    RECT rcParent = {0};
    if(m_pParent)
    {
        m_pParent->get_rect(&rcParent);
    }

    switch(m_UIMarginType)
    {
    case UIMarginLeftTop:
    {
        m_rcView.left = rcParent.left + m_rcMargin.left;
        m_rcView.top = rcParent.top + m_rcMargin.top;
        m_rcView.right = m_rcView.left + m_szView.cx;
        m_rcView.bottom = m_rcView.top + m_szView.cy;
    }
    break;

    case UIMarginLeftCenter:
    {
        m_rcView.left = rcParent.left + m_rcMargin.left;
        m_rcView.top = rcParent.top + (rcParent.bottom - rcParent.top)/2;
    }
    break;

    case UIMarginLeftBottom:
    {
        m_rcView.left = rcParent.left + m_rcMargin.left;
        m_rcView.bottom = rcParent.bottom - m_rcMargin.bottom;
    }
    break;

    case UIMarginCenterTop:
    {
        m_rcView.left = rcParent.left + (rcParent.right - rcParent.left)/2;
        m_rcView.top = rcParent.top + m_rcMargin.top;
    }
    break;

    case UIMarginCenter:
    {
        m_rcView.left = rcParent.left + (rcParent.right - rcParent.left)/2;
        m_rcView.top = rcParent.top + (rcParent.bottom - rcParent.top)/2;
    }
    break;

    case UIMarginCenterBottom:
    {
        m_rcView.left = rcParent.left + (rcParent.right - rcParent.left)/2;
        m_rcView.bottom = rcParent.bottom - m_rcMargin.bottom;
    }
    break;

    case UIMarginRightTop:
    {
        m_rcView.right = rcParent.right - m_rcMargin.right;
        m_rcView.top = rcParent.top + m_rcMargin.top;
        m_rcView.left = m_rcView.right - m_szView.cx;
        m_rcView.bottom = m_rcView.top + m_szView.cy;
    }
    break;

    case UIMarginRightCenter:
    {
        m_rcView.right = rcParent.right - m_rcMargin.right;
        m_rcView.top = rcParent.top + (rcParent.bottom - rcParent.top)/2;
    }
    break;

    case UIMarginRightBottom:
    {
        m_rcView.right = rcParent.right - m_rcMargin.right;
        m_rcView.bottom = rcParent.bottom - m_rcMargin.bottom;
    }
    break;
    }

    return ;
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
    UICanvas *pUICanvas = CSingleton<UICanvas>::Instance();

    if(pUICanvas)
    {
        SkCanvas *pCanvas = pUICanvas->GetCanvas();
        if(pCanvas)
        {
            pCanvas->save();

            SkRect rc;
            rc.iset(m_rcView.left, m_rcView.top, m_rcView.right, m_rcView.bottom);
            pCanvas->clipRect(rc);

            this->OnDraw(pRect);

            for(size_t i=0; i<m_vecChildren.size(); ++i)
            {
                UIView *pChild = m_vecChildren[i];
                if(pChild)
                {
                    pChild->Draw(NULL);
                }
            }

            pCanvas->restore();
        }
    }

    return ;
}

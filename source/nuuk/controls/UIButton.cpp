#include "NkButton.h"

UIButton::CNkButton()
    : m_rcAnchor(0, 0, 48, 32)
    , m_sz(48, 32)
{
    m_strNormalBkg = _T("commonres\\button\\btn_normal.png");
    m_strHoveredBkg = _T("commonres\\button\\btn_hovered.png");
    m_strPressedBkg = _T("commonres\\button\\btn_pressed.png");
}

CNkButton::~CNkButton()
{}

HRESULT CNkButton::put_parent(SkView *pParent)
{
    if(NULL == pParent)
    {
        return E_INVALIDARG;
    }

    pParent->attachChildToFront(this);
    
    return S_OK;
}

SkView *CNkButton::get_parent()
{
    return this->getParent();
}

HRESULT CNkButton::put_anchor(const RECT rect)
{
    m_rcAnchor = rect;
    
    return S_OK;
}

HRESULT CNkButton::get_anchor(RECT *pRect)
{
    *pRect = m_rcAnchor;
    
    return S_OK;
}

HRESULT CNkButton::put_size(const SIZE size)
{
    m_sz = size;
    this->inval(nullptr);
    
    return S_OK;
}

HRESULT CNkButton::get_size(SIZE *pSize)
{
    *pSize = m_Size;
    
    return S_OK;
}

HRESULT CNkButton::put_text(BSTR bsText);
{
    this->inval(nullptr);
    
    return S_OK;
}

HRESULT CNkButton::get_text(BSTR *pbsText)
{
    return S_OK;
}

HRESULT CNkButton::put_normalBackground(LPCSTR szImgPath)
{
    m_strNormalBkg = szImgPath;
    this->inval(nullptr);

    return S_OK;
}

HRESULT CNkButton::put_hoveredBackground(LPCSTR szImgPath)
{
    m_strHoveredBkg = szImgPath;
    this->inval(nullptr);

    return S_OK;
}

HRESULT CNkButton::put_pressedBackground(LPCSTR szImgPath)
{
    m_strPressedBkg = szImgPath;
    this->inval(nullptr);

    return S_OK;
}

void CNkButton::onDraw(SkCanvas *pCanvas)
{
    CAtlStringA strBkg = m_strNormalBkg;
    switch(Click::fState)
    {
    // case Click::kUp_State:
    //     strBkg = m_strNormalBkg;
    //     break;

    case Click::kDown_State:
        strBkg = m_strPressedBkg;
        break;

    default:
        break;
    }
    
    if(!strBkg.IsEmpty())
    {
        SkBitmap bitmap;
        bool bRet = GetResourceAsBitmap(m_strNormalBkg, &bitmap);
        if(bRet)
        {
            pCanvas->drawBitmap(bitmap, 0, 0);
        }        
    }
    
    return ;
}

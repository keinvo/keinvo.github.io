#include "UILabel.h"

UILabel::UILabel()
    : m_color(RGB(0, 0, 0))
    , m_backgroundColor(RGB(255, 255, 255))
{
}

UILabel::~UILabel()
{}

HRESULT UILabel::put_text(BSTR bsText)
{
    m_bsText = bsText;

    return S_OK;
}

HRESULT UILabel::get_text(BSTR *pbsText)
{
    CComBSTR bsText = m_bsText;
    *pbsText = bsText.Detach();

    return S_OK;
}

HRESULT UILabel::put_color(ARGB32 color)
{
    m_color = color;

    return S_OK;
}

HRESULT UILabel::put_backgroundColor(ARGB32 color)
{
    m_backgroundColor = color;

    return S_OK;
}

void UILabel::OnDraw(CRect *pRect)
{
    UICanvas *pCanvas = CSingleton<UICanvas>::Instance();
    if(pCanvas)
    {
        SkCanvas *p = pCanvas->GetCanvas();
        p->drawColor(m_backgroundColor);

        pCanvas->DrawText(m_bsText, m_rcView.left+10, m_rcView.top+30, m_color, 18.0f);
    }

    return ;
}

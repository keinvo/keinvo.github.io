#include "UILabel.h"

UILabel::UILabel()
    : m_color(RGB(0, 0, 0))
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

void UILabel::OnDraw(CRect *pRect)
{
    UICanvas *pCanvas = CSingleton<UICanvas>::Instance();
    if(pCanvas)
    {
        SkCanvas *p = pCanvas->GetCanvas();
        p->drawColor(SK_ColorRED);
        pCanvas->DrawText(m_bsText, 0, 0);
    }

    return ;
}

#include "UILabel.h"

UILabel::UILabel()
    : m_color(RGB(0, 0, 0))
{
}

UILabel::~UILabel()
{}

void UILabel::put_text(LPCTSTR szText)
{
    m_strText = szText;
}

void UILabel::put_color(ARGB32 color)
{
    m_color = color;
}

void UILabel::OnDraw(CRect *pRect)
{
    UICanvas *pCanvas = CSingleton<UICanvas>::Instance();
    if(pCanvas)
    {
        pCanvas->DrawText(m_strText, 0, 0);
    }

    return ;
}

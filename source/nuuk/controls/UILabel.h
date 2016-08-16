#pragma once

#include "UIView.h"
#include "UICanvas.h"

class UILabel
: public UIView
{
public:
    UILabel(void);
    virtual ~UILabel();

public:
    HRESULT put_text(BSTR bsText);
    HRESULT get_text(BSTR *pbsText);

    HRESULT put_color(ARGB32 color);
    HRESULT put_backgroundColor(ARGB32 color);

protected:
    void OnDraw(CRect *pRect);

protected:
    CComBSTR m_bsText;
    ARGB32 m_color;
    ARGB32 m_backgroundColor;
};

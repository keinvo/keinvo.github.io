#pragma once

#include "UIType.h"
#include "UIView.h"
#include "UICanvas.h"

class UILabel
: public UIView
{
public:
    UILabel();
    virtual ~UILabel();

public:
    HRESULT put_text(BSTR bsText);
    HRESULT get_text(BSTR *pbsText);

    HRESULT put_color(ARGB32 color);

    HRESULT put_anchor(const RECT rect);
    HRESULT get_anchor(RECT *pRect);

    HRESULT put_size(const SIZE size);
    HRESULT get_size(SIZE *pSize);

protected:
    void OnDraw(CRect *pRect);

protected:
    CComBSTR m_bsText;
    ARGB32 m_color;
};

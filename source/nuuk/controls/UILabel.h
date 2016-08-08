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
    void put_text(LPCTSTR szText);
    void put_color(ARGB32 color);

protected:
    void OnDraw(CRect *pRect);

protected:
    CAtlString m_strText;
    ARGB32 m_color;
};

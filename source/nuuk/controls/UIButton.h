#pragma once

#include "UIView.h"

class UIButton
: public UIView
{
public:
    enum UIButtonState{
        STATE_NORMAL = 0,
        STATE_HOVERED,
        STATE_PRESSED,
        STATE_DISABLED,
    };

public:
    UIButton();
    ~UIButton();

public:
    HRESULT put_text(BSTR bsText);
    HRESULT get_text(BSTR *pbsText);
    
    HRESULT put_normalBackground(BSTR bsImgPath);
    HRESULT put_hoveredBackground(BSTR bsImgPath);
    HRESULT put_pressedBackground(BSTR bsImgPath);

protected:
    void OnDraw(CRect *pRect);

private:
    CComBSTR m_bsNormalBkg;
    CComBSTR m_bsHoveredBkg;
    CComBSTR m_bsPressedBkg;
};

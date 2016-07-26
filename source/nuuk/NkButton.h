#pragma once

#include "SkView.h"

class CNkButton : public SkView
{
 public:
    enum NKButtonState{
        STATE_NORMAL = 0,
        STATE_HOVERED,
        STATE_PRESSED,
        STATE_DISABLED,
    };

 public:
    CNkButton(void);
    ~CNkButton(void);

    HRESULT put_parent(SkView *pParent);
    SkView *get_parent();

    HRESULT put_anchor(const RECT rect);
    HRESULT get_anchor(RECT *pRect);

    HRESULT put_size(const SIZE size);
    HRESULT get_size(SIZE *pSize);

    HRESULT put_text(BSTR bsText);
    HRESULT get_text(BSTR *pbsText);
    
    HRESULT put_normalBackground(LPCSTR szImgPath);
    HRESULT put_hoveredBackground(LPCSTR szImgPath);
    HRESULT put_pressedBackground(LPCSTR szImgPath);

 protected:
    virtual void onDraw(SkCanvas *pCanvas);

 private:
    CRect m_rcAnchor;
    CSize m_sz;
    CAtlStringA m_strNormalBkg;
    CAtlStringA m_strHoveredBkg;
    CAtlStringA m_strPressedBkg;
};

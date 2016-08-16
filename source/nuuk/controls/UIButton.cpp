#include "UIButton.h"
#include "UICanvas.h"

UIButton::UIButton()
{
}

UIButton::~UIButton()
{}

HRESULT UIButton::put_normalBackground(BSTR bsImgPath)
{
    m_bsNormalBkg = bsImgPath;

    return S_OK;
}

HRESULT UIButton::put_hoveredBackground(BSTR bsImgPath)
{
    m_bsHoveredBkg = bsImgPath;

    return S_OK;
}

HRESULT UIButton::put_pressedBackground(BSTR bsImgPath)
{
    m_bsPressedBkg = bsImgPath;

    return S_OK;
}

void UIButton::OnDraw(CRect *pRect)
{
    UICanvas *pUICanvas = CSingleton<UICanvas>::Instance();
    if(pUICanvas)
    {
        pUICanvas->DrawImage(m_bsNormalBkg, m_rcView);
    }

    return ;
}

// void UIButton::onDraw(SkCanvas *pCanvas)
// {
//     CAtlStringA strBkg = m_strNormalBkg;
//     switch(Click::fState)
//     {
//     // case Click::kUp_State:
//     //     strBkg = m_strNormalBkg;
//     //     break;

//     case Click::kDown_State:
//         strBkg = m_strPressedBkg;
//         break;

//     default:
//         break;
//     }
    
//     if(!strBkg.IsEmpty())
//     {
//         SkBitmap bitmap;
//         bool bRet = GetResourceAsBitmap(m_strNormalBkg, &bitmap);
//         if(bRet)
//         {
//             pCanvas->drawBitmap(bitmap, 0, 0);
//         }
//     }
    
//     return ;
// }

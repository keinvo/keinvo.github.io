#include "NkCanvas.h"

HRESULT CNkView::DrawImage(
    const std::string &imagepath,
    LPCRECT pRcSource,
    LPCRECT pRcDest)
{
    SkBitmap bitmap;
    bool bRet = GetResourceAsBitmap(imagepath.c_str(), &bitmap);

    SkRect rcSrc;
    rcSrc.setLTRB(pRcSource->left, pRcSource->top, pRcSource->right, pRcSource->bottom);

    SkRect rcDst;
    rcDst.setLTRB(pRcDest->left, pRcDest->top, pRcDest->right, pRcDest->bottom);
    
    m_canvas.drawBitmapRect(bitmap, rcSrc, rcDst);
    
    return S_OK;
}

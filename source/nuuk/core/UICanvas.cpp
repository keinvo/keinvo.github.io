#include "UICanvas.h"
#include "skia\tools\Resources.h"

HRESULT UICanvas::DrawImage(LPCTSTR szImgPath, const RECT &rcSrc, const RECT &rcDst)
{
    HRESULT hr = E_FAIL;

    do
    {
    	if(nullptr == szImgPath)
        {
            hr =  E_INVALIDARG;
            break;
        }

        CAtlStringA strImgPath = CW2A(szImgPath, CP_UTF8);

        SkBitmap bitmap;
        bool bRet = GetResourceAsBitmap(strImgPath, &bitmap);
       
        if(bRet)
        {
            hr = E_UNEXPECTED;
            break;
        }
        SkRect src, dst;
        src.set(rcSrc.left, rcSrc.top, rcSrc.right, rcSrc.bottom);
        dst.set(rcDst.left, rcDst.top, rcDst.right, rcDst.bottom);
        
        m_canvas.drawBitmapRect(bitmap, src, dst, &m_paint);

        hr = S_OK;
    } while(0);

    return hr;
}

HRESULT UICanvas::DrawText(LPCTSTR szText)
{
	HRESULT hr = E_FAIL;
    do
    {
    } while(0);

    return hr;
}

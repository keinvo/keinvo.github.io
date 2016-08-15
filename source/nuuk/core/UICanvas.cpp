#include "UICanvas.h"
#include <atlstr.h>
#include <atlconv.h>
#include <comutil.h>
#include "SkSurface.h"
#include "skia\tools\Resources.h"

UICanvas::UICanvas()
    : m_SurfaceProps(SkSurfaceProps::kLegacyFontHost_InitType)
    , m_pCanvas(nullptr)
{
    m_bitmap.allocN32Pixels(0, 0);
}

void UICanvas::Resize(int iWidth, int iHeight)
{
	SkImageInfo info = m_bitmap.info();

	info = info.makeWH(iWidth, iHeight);

	if (m_bitmap.info() != info)
	{
		m_bitmap.allocPixels(info);
    }

    if(m_pCanvas)
    {
        delete m_pCanvas;
    }

    m_pCanvas = new SkCanvas(m_bitmap);

    return;
}

HRESULT UICanvas::DrawImage(BSTR bsImgPath, const RECT *pDst, const RECT *pSrc)
{
    HRESULT hr = E_FAIL;

    do
    {
        if(nullptr == m_pCanvas)
        {
            hr = E_UNEXPECTED;
            break;
        }
        if(nullptr == pDst)
        {
            hr =  E_INVALIDARG;
            break;
        }

        char *szImgPath = _com_util::ConvertBSTRToString(bsImgPath);
        if(!szImgPath)
        {
            hr = E_INVALIDARG;
            break;
        }

        SkBitmap bitmap;
        bool bRet = GetResourceAsBitmap(szImgPath, &bitmap);

        delete[] szImgPath;

        if(!bRet)
        {
            hr = E_UNEXPECTED;
            break;
        }

        SkRect src, dst;

        if(pSrc)
        {
            src.set(pSrc->left, pSrc->top, pSrc->right, pSrc->bottom);
        }
        else
        {
            src.set(0, 0, bitmap.width(), bitmap.height());
        }

        dst.set(pDst->left, pDst->top, pDst->right, pDst->bottom);

        m_pCanvas->drawBitmapRect(bitmap, src, dst, &m_paint);

        hr = S_OK;
    } while(0);

    return hr;
}

HRESULT UICanvas::DrawText(BSTR bsText, int x, int y, ARGB32 color, float fSize)
{
	HRESULT hr = E_FAIL;
    do
    {
        if(nullptr == m_pCanvas)
        {
            hr = E_UNEXPECTED;
            break;
        }

        SkPaint paint;
        paint.setColor(color);
        paint.setTextSize(fSize);

        char *szText = _com_util::ConvertBSTRToString(bsText);
        if(szText)
        {
            m_pCanvas->drawText(szText, strlen(szText), x, y, paint);
//            delete[] szText;

            hr = S_OK;
        }

    } while(0);

    return hr;
}

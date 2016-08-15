#include "UICanvas.h"
#include <atlstr.h>
#include <atlconv.h>
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

        // CAtlStringA strImgPath = CW2A(szImgPath, CP_UTF8); // vs2015 compiler bug:error C2440: '<function-style-cast>': cannot convert from * to *
        // CAtlString strImgPath = szImgPath;
        // int iLen = strImgPath.GetLength();

		// CHAR szImg[MAX_PATH] = { 0 };

        // AtlW2AHelper(szImg, (LPCWSTR)szImgPath, iLen, CP_UTF8);

        SkBitmap bitmap;
        bool bRet = GetResourceAsBitmap(szImgPath, &bitmap);

        if(szImgPath)
        {
            delete[] szImgPath;
        }
       
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

HRESULT UICanvas::DrawText(BSTR bsText, int x, int y)
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

        const char text[] = "Skia";
        m_pCanvas->drawText(text, strlen(text), 100.0f, 80.0f, paint);

        
    } while(0);

    return hr;
}

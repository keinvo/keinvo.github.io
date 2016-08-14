#pragma once
#include "UIType.h"
#include "SkCanvas.h"
#include "SkBitmap.h"
#include "../common/Singleton.h"

class UICanvas
{
public:
    virtual ~UICanvas(){};

 private:
    friend class CSingleton<UICanvas>;
    
    UICanvas();

 public:
    void Resize(int iWidth, int iHeight);
    SkBitmap &GetBitmap() { return m_bitmap; };
    SkCanvas *GetCanvas() { return m_pCanvas; };

    virtual HRESULT DrawImage(BSTR bsImgPath, const RECT *pDst, const RECT *pSrc=NULL);
    virtual HRESULT DrawText(BSTR bsText, int x, int y);
    
 protected:
    SkSurfaceProps  m_SurfaceProps;
    SkCanvas *m_pCanvas;
    SkBitmap m_bitmap;
    SkPaint m_paint;
};

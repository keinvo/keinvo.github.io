#pragma once
#include "SkCanvas.h"
#include "SkBitmap.h"
#include "../common/Singleton.h"

class UICanvas
{
 private:
    friend class CSingleton<UICanvas>;
    
    UICanvas(){};
    virtual ~UICanvas(){};

 public:
    virtual HRESULT DrawImage(LPCTSTR szImgPath, const RECT &rcSrc, const RECT &rcDst);
    virtual HRESULT DrawText(LPCTSTR szText, int x, int y);
    
 protected:
    SkCanvas m_canvas;
    SkBitmap m_bitmap;
    SkPaint m_paint;
};

#pragma once

#include "SkImage.h"
#include "SkCanvas.h"

class CNkView
{
 public:
    virtual HRESULT DrawImage(const std::string &imagepath,
                              LPCRECT pRcDest);
    
    virtual HRESULT DrawImage(const std::string &imagepath,
                              LPCRECT pRcSource,
                              LPCRECT pRcDest);

 protected:
    SkCanvas m_canvas;
    SkBitmap m_bitmap;
};

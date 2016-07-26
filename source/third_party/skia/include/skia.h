// skia.h generated by CMake.
#ifndef skia_DEFINED
#define skia_DEFINED

#include "SkBitmapRegionDecoder.h"
#include "SkBRDAllocator.h"

#include "sk_canvas.h"
#include "sk_data.h"
#include "sk_image.h"
#include "sk_maskfilter.h"
#include "sk_matrix.h"
#include "sk_paint.h"
#include "sk_path.h"
#include "sk_picture.h"
#include "sk_shader.h"
#include "sk_surface.h"
#include "sk_types.h"

#include "SkAndroidCodec.h"
#include "SkCodec.h"
#include "SkEncodedFormat.h"
#include "SkEncodedInfo.h"

#include "SkAnnotation.h"
#include "SkBBHFactory.h"
#include "SkBitmap.h"
#include "SkBitmapDevice.h"
#include "SkBlitRow.h"
#include "SkBlurTypes.h"
#include "SkCanvas.h"
#include "SkChunkAlloc.h"
#include "SkClipStack.h"
#include "SkColor.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkColorTable.h"
#include "SkData.h"
#include "SkDataTable.h"
#include "SkDeque.h"
#include "SkDevice.h"
#include "SkDocument.h"
#include "SkDraw.h"
#include "SkDrawable.h"
#include "SkDrawFilter.h"
#include "SkDrawLooper.h"
#include "SkError.h"
#include "SkFilterQuality.h"
#include "SkFlattenable.h"
#include "SkFlattenableSerialization.h"
#include "SkFont.h"
#include "SkFontLCDConfig.h"
#include "SkFontStyle.h"
#include "SkGraphics.h"
#include "SkImage.h"
#include "SkImageEncoder.h"
#include "SkImageFilter.h"
#include "SkImageGenerator.h"
#include "SkImageInfo.h"
#include "SkMallocPixelRef.h"
#include "SkMask.h"
#include "SkMaskFilter.h"
#include "SkMath.h"
#include "SkMatrix.h"
#include "SkMatrix44.h"
#include "SkMetaData.h"
#include "SkMilestone.h"
#include "SkMultiPictureDraw.h"
#include "SkOSFile.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkPathEffect.h"
#include "SkPathMeasure.h"
#include "SkPathRef.h"
#include "SkPicture.h"
#include "SkPictureAnalyzer.h"
#include "SkPictureRecorder.h"
#include "SkPixelRef.h"
#include "SkPixelSerializer.h"
#include "SkPixmap.h"
#include "SkPngChunkReader.h"
#include "SkPoint.h"
#include "SkPoint3.h"
#include "SkPostConfig.h"
#include "SkPreConfig.h"
#include "SkRasterizer.h"
#include "SkRect.h"
#include "SkRefCnt.h"
#include "SkRegion.h"
#include "SkRRect.h"
#include "SkRSXform.h"
#include "SkRWBuffer.h"
#include "SkScalar.h"
#include "SkShader.h"
#include "SkSize.h"
#include "SkStream.h"
#include "SkString.h"
#include "SkStrokeRec.h"
#include "SkSurface.h"
#include "SkSurfaceProps.h"
#include "SkSwizzle.h"
#include "SkTextBlob.h"
#include "SkTime.h"
#include "SkTLazy.h"
#include "SkTraceMemoryDump.h"
#include "SkTRegistry.h"
#include "SkTypeface.h"
#include "SkTypes.h"
#include "SkUnPreMultiply.h"
#include "SkWriteBuffer.h"
#include "SkWriter32.h"
#include "SkXfermode.h"
#include "SkYUVSizeInfo.h"

#include "Sk1DPathEffect.h"
#include "Sk2DPathEffect.h"
#include "SkAlphaThresholdFilter.h"
#include "SkArcToPathEffect.h"
#include "SkArithmeticMode.h"
#include "SkBlurDrawLooper.h"
#include "SkBlurImageFilter.h"
#include "SkBlurMaskFilter.h"
#include "SkColorCubeFilter.h"
#include "SkColorFilterImageFilter.h"
#include "SkColorMatrix.h"
#include "SkColorMatrixFilter.h"
#include "SkComposeImageFilter.h"
#include "SkCornerPathEffect.h"
#include "SkDashPathEffect.h"
#include "SkDiscretePathEffect.h"
#include "SkDisplacementMapEffect.h"
#include "SkDropShadowImageFilter.h"
#include "SkEmbossMaskFilter.h"
#include "SkGradientShader.h"
#include "SkImageSource.h"
#include "SkLayerDrawLooper.h"
#include "SkLayerRasterizer.h"
#include "SkLightingImageFilter.h"
#include "SkLumaColorFilter.h"
#include "SkMagnifierImageFilter.h"
#include "SkMatrixConvolutionImageFilter.h"
#include "SkMergeImageFilter.h"
#include "SkMorphologyImageFilter.h"
#include "SkOffsetImageFilter.h"
#include "SkPaintFlagsDrawFilter.h"
#include "SkPaintImageFilter.h"
#include "SkPerlinNoiseShader.h"
#include "SkPictureImageFilter.h"
#include "SkTableColorFilter.h"
#include "SkTableMaskFilter.h"
#include "SkTestImageFilters.h"
#include "SkTileImageFilter.h"
#include "SkXfermodeImageFilter.h"

#include "GrConstColorProcessor.h"
#include "GrCoverageSetOpXP.h"
#include "GrCustomXfermode.h"
#include "GrPorterDuffXferProcessor.h"
#include "GrXfermodeFragmentProcessor.h"

#include "GrGLAssembleInterface.h"
#include "GrGLConfig.h"
#include "GrGLExtensions.h"
#include "GrGLFunctions.h"
#include "GrGLInterface.h"
#include "GrGLSLPrettyPrint.h"
#include "GrGLTypes.h"

#include "GrBlend.h"
#include "GrBuffer.h"
#include "GrBufferAccess.h"
#include "GrCaps.h"
#include "GrClip.h"
#include "GrColor.h"
#include "GrConfig.h"
#include "GrContext.h"
#include "GrContextOptions.h"
#include "GrCoordTransform.h"
#include "GrDrawContext.h"
#include "GrFragmentProcessor.h"
#include "GrGpuResource.h"
#include "GrGpuResourceRef.h"
#include "GrInvariantOutput.h"
#include "GrPaint.h"
#include "GrProcessor.h"
#include "GrProcessorUnitTest.h"
#include "GrProgramElement.h"
#include "GrRenderTarget.h"
#include "GrResourceKey.h"
#include "GrShaderVar.h"
#include "GrSurface.h"
#include "GrTestUtils.h"
#include "GrTexture.h"
#include "GrTextureAccess.h"
#include "GrTextureParams.h"
#include "GrTextureProvider.h"
#include "GrTypes.h"
#include "GrTypesPriv.h"
#include "GrXferProcessor.h"
#include "SkGr.h"
#include "SkGrPixelRef.h"
#include "SkGrTexturePixelRef.h"

#include "SkForceLinking.h"
#include "SkMovie.h"

#include "SkPathOps.h"

#include "SkFontConfigInterface.h"
#include "SkFontMgr.h"
#include "SkFontMgr_android.h"
#include "SkFontMgr_custom.h"
#include "SkFontMgr_fontconfig.h"
#include "SkFontMgr_indirect.h"
#include "SkRemotableFontMgr.h"
#include "SkTypeface_mac.h"
#include "SkTypeface_win.h"

#include "SkCGUtils.h"

#include "SkBoundaryPatch.h"
#include "SkCamera.h"
#include "SkCanvasStateUtils.h"
#include "SkDumpCanvas.h"
#include "SkEventTracer.h"
#include "SkFrontBufferedStream.h"
#include "SkInterpolator.h"
#include "SkLayer.h"
#include "SkLua.h"
#include "SkLuaCanvas.h"
#include "SkMeshUtils.h"
#include "SkNinePatch.h"
#include "SkNoSaveLayerCanvas.h"
#include "SkNullCanvas.h"
#include "SkNWayCanvas.h"
#include "SkPaintFilterCanvas.h"
#include "SkParse.h"
#include "SkParsePath.h"
#include "SkPictureUtils.h"
#include "SkRandom.h"
#include "SkRTConf.h"
#include "SkTextBox.h"

#include "SkAutoCoInitialize.h"
#include "SkHRESULT.h"
#include "SkIStream.h"
#include "SkTScopedComPtr.h"

#endif  // skia_DEFINED
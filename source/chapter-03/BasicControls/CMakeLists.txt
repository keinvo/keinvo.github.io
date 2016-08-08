set(PROJNAME BasicControls)
set(CHAPTER "chapter-03")

include_directories(${PROJECT_SOURCE_DIR}/third_party)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/tools)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/tools/flags)

include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/config)

include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/android)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/c)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/codec)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/core)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/effects)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/gpu/effects)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/gpu/gl)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/gpu)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/images)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/pathops)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/ports)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/utils/mac)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/utils)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/utils/win)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/views)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/xml)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/private)

include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/android)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/animator)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/c)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/codec)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/core)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/effects/gradients)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/effects)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/fonts)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/batches)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/effects)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/gl/builders)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/gl)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/gl/mesa)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/glsl)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/text)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/gpu/vk)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/image)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/images)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/lazy)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/opts)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/pathops)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/pdf)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/ports)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/sfnt)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/svg/parser)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/svg)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/utils)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/utils/win)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/views/mac)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/views)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/views/unix)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/src/xps)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/include/private)

include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/common/etc1)
include_directories(${PROJECT_SOURCE_DIR}/third_party/skia/common/ktx)

include_directories(${PROJECT_SOURCE_DIR}/nuuk)
include_directories(${PROJECT_SOURCE_DIR}/nuuk/core)
include_directories(${PROJECT_SOURCE_DIR}/nuuk/controls)


file (GLOB FILE_SOURCE
  "stdafx.h",
  "stdafx.cpp",
  "BasicControls.cpp",
  "../../third_party/skia/tools/Resources.h"
  "../../third_party/skia/tools/Resources.cpp"
  "../../third_party/skia/tools/flags/SkCommandLineFlags.h"
  "../../third_party/skia/tools/flags/SkCommandLineFlags.cpp"
  "../../nuuk/core/UICanvas.cpp"
  "../../nuuk/core/UIView.cpp"
  "../../nuuk/core/UIWindow.cpp")


source_group("source" FILES ${FILE_SOURCE})

add_executable(${PROJNAME} WIN32 ${FILE_SOURCE})
target_link_libraries(${PROJNAME} skia usp10 opengl32)

set_property(TARGET ${PROJNAME} PROPERTY FOLDER ${CHAPTER})

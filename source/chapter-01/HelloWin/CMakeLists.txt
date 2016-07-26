cmake_minimum_required (VERSION 3.1)

set(PROJNAME HelloWin)
set(CHAPTER "chapter-01")

file (GLOB FILE_SOURCE
  "*.h",
  "*.cpp")

source_group("source" FILES ${FILE_SOURCE})

add_executable(${PROJNAME} WIN32 ${FILE_SOURCE})

set_property(TARGET ${PROJNAME} PROPERTY FOLDER ${CHAPTER})

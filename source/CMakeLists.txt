cmake_minimum_required(VERSION 3.1)

project(uiengine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(third_party)

add_subdirectory(chapter-01/HelloWin)
add_subdirectory(chapter-01/HelloWinDlg)

add_subdirectory(chapter-01/HelloCWindow)
add_subdirectory(chapter-01/HelloCwindowImpl)
add_subdirectory(chapter-01/HelloCwindowImpl2)
add_subdirectory(chapter-01/StopWatch)
add_subdirectory(chapter-01/StopWatchUseThunk)

add_subdirectory(chapter-02/SelfDrawnWnd)

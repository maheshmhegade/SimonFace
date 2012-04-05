PROJECT(simonface)

FIND_PACKAGE(Qt4 4.6.0 REQUIRED)

FIND_PACKAGE(KDE4 REQUIRED)

FIND_PACKAGE( OpenCV)

INCLUDE(KDE4Defaults)

INCLUDE_DIRECTORIES (${QDBUS_INCLUDE_DIRS} ${KDE4_INCLUDES})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(/usr/lib)

include_directories(/usr/include/opencv)

set(opencv_libraries libcxcore.so libcv.so libhighgui.so libcvaux.so)

SET(simonface_src main.cpp simonface.cpp)

kde4_add_ui_files(simonface_src simonface.ui)

KDE4_ADD_EXECUTABLE(simonface ${simonface_src})

TARGET_LINK_LIBRARIES(simonface ${KDE4_KDECORE_LIBS}  ${KDE4_KDEUI_LIBS} ${QT_QTGUI_LIBRARY} ${LIBFACE_LIBRARIES} ${KDE4_KDECORE_LIBS} ${QT_QTCORE_LIBRARY} 

${QT_QTGUI_LIBRARY} ${opencv_libraries})


include(KDE4Defaults)
include(KDE4Macros)
add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
set(opencv_LIBS libcv.so libcvaux.so libhighgui.so libcxcore.so libml.so)
include_directories(${KDE4_INCLUDE_DIRS} ${KDE4_INCLUDE_DIR}
${KDE4_INCLUDE_DIR}/KDE ${QT_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR}/../../../simonlib  /usr/include/opencv/)

set (simonfaceconditionplugin_SRCS 
	simonfacecondition.cpp 
        createsimonfaceconditionwidget.cpp
    )

kde4_add_ui_files(simonfaceconditionplugin_SRCS
        createsimonfaceconditionwidget.ui
    )

kde4_add_plugin(simonfaceconditionplugin ${simonfaceconditionplugin_SRCS})


target_link_libraries(simonfaceconditionplugin ${KDE4_KDEUI_LIBS} ${opencv_LIBS}
  ${QT_QTXML_LIBRARY} simoncontextdetection simonuicomponents)

install(TARGETS simonfaceconditionplugin DESTINATION ${PLUGIN_INSTALL_DIR} COMPONENT simonfaceconditionplugin )
install( FILES simonfaceconditionplugin.desktop  DESTINATION  ${SERVICES_INSTALL_DIR} COMPONENT simonfaceconditionplugin )
 

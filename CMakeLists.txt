cmake_minimum_required(VERSION 3.5)

project(Qt-leptonica CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)  # https://stackoverflow.com/questions/46862737/cmake-qt-uic-failed
 
find_package(Qt5 REQUIRED Widgets Svg)
find_package(Leptonica REQUIRED)

include_directories(
    ${Leptonica_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
link_directories(${leptonica_LIBRARY_DIRS})
add_definitions(${leptonica_DEFINITIONS})

set(project_FORMS
    ${CMAKE_CURRENT_LIST_DIR}/dialogs/mainwindow.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialogs/dpidialog.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialogs/cdbdialog.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialogs/combodialog.ui)
qt5_wrap_ui(UI_HEADERS ${project_FORMS})

set(project_RESOURCES
    resources/application.qrc)

set(project_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/undo.cpp
    src/scene.cpp
    src/areaitem.cpp
    src/qleptonica.cpp
    src/logger.cpp
    dialogs/dpidialog.cpp
    dialogs/cdbdialog.cpp
    dialogs/combodialog.cpp)

set(project_HEADERS
    src/mainwindow.h
    src/settings.h
    src/scene.h
    src/areaitem.h
    src/qleptonica.h
    dialogs/dpidialog.h
    dialogs/cdbdialog.h
    dialogs/combodialog.h)

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE
      Release
      CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

STRING(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
if(WIN32 AND ${BUILD_TYPE} MATCHES RELEASE)
   set(EXTRA_FLAGS "WIN32")
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    enable_language("RC")
    set (WIN32_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/win.rc)
endif()

add_executable(
  ${CMAKE_PROJECT_NAME} ${EXTRA_FLAGS} ${project_SOURCES} ${UI_HEADERS}
                               ${project_HEADERS} ${project_RESOURCES} ${WIN32_RESOURCES})
target_link_libraries(
  ${CMAKE_PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Svg ${Leptonica_LIBRARIES})

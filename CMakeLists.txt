cmake_minimum_required(VERSION 3.5)

project(Qt-leptonica CXX)

set(PROJECT_VERSION "1.0-alpha")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)  # https://stackoverflow.com/questions/46862737/cmake-qt-uic-failed
 
find_package(Qt5 REQUIRED Widgets Svg)
find_package(leptonica REQUIRED)

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
    src/scene.cpp
    src/areaitem.cpp
    src/qleptonica.cpp
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


if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    enable_language("RC")
    set (WIN32_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/win.rc)
endif()

add_executable(
  ${CMAKE_PROJECT_NAME}-${PROJECT_VERSION} ${project_SOURCES} ${UI_HEADERS}
                               ${project_HEADERS} ${project_RESOURCES} ${WIN32_RESOURCES})
target_link_libraries(
  ${CMAKE_PROJECT_NAME}-${PROJECT_VERSION} Qt5::Widgets Qt5::Svg ${Leptonica_LIBRARIES})
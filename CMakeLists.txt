cmake_minimum_required(VERSION 3.5)

project(Password_manager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Sql)

set(PROJECT_HEADERS
    addnewnote.h
    databasemanager.h
    mainwindow.h
    widget.h
    )

set(PROJECT_SOURCES
    main.cpp
    addnewnote.cpp
    databasemanager.cpp
    mainwindow.cpp
    widget.cpp
)

set(PROJECT_UI
    mainwindow.ui
    addnewnote.ui
    widget.ui
)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Password_manager
        MANUAL_FINALIZATION
        ${PROJECT_HEADERS}
        ${PROJECT_SOURCES}
        ${PROJECT_UI}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Password_manager APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Password_manager SHARED
            ${PROJECT_HEADERS}
            ${PROJECT_SOURCES}
            ${PROJECT_UI}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Password_manager
            ${PROJECT_HEADERS}
            ${PROJECT_SOURCES}
            ${PROJECT_UI}
        )
    endif()
endif()

target_link_libraries(Password_manager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Password_manager PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Sql)


set_target_properties(Password_manager PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Password_manager)
endif()

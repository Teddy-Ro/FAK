cmake_minimum_required(VERSION 3.16)
project(FieldManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

# Qt resource files
set(RESOURCE_FILES
    resources.qrc
)

qt_add_resources(RESOURCES ${RESOURCE_FILES})

# UI files
set(UI_FILES
    mainwindow.ui
)

qt_wrap_ui(UIS ${UI_FILES})

add_executable(FieldManager
    main.cpp
    mainwindow.cpp
    mainwindow.h
    fieldgroup.cpp
    fieldgroup.h
    ${UIS}
    ${RESOURCES}
)

target_link_libraries(FieldManager PRIVATE Qt6::Widgets)

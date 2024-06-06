cmake_minimum_required(VERSION 3.5)

project(waveGen LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(sources         wavheader.h
        wavheader.cpp
        waveclass.h
        waveclass.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui)

target_link_libraries(sources PRIVATE Qt5::Widgets)
add_executable(waveGen

        main.cpp
)


target_link_libraries(waveGen PRIVATE Qt5::Widgets sources)


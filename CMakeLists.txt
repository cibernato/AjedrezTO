cmake_minimum_required(VERSION 3.5)

project(Ajedrez-to LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)


if (ANDROID)
    add_library(Ajedrez-to SHARED
            main.cpp
            chesspiece.h
            chesspiece.cpp
            chesscell.cpp
            chesscell.h
            bishop.cpp
            bishop.h
            king.cpp
            king.h
            horse.cpp
            horse.h
            pawn.cpp
            pawn.h
            queen.cpp
            queen.h
            tower.cpp
            tower.h
            button.cpp
            button.h
            board.cpp
            board.h
            core.cpp
            core.h
            constants.h
            resources.qrc
            )
else ()
    add_executable(Ajedrez-to
            main.cpp
            chesspiece.h
            chesspiece.cpp
            chesscell.cpp
            chesscell.h
            bishop.cpp
            bishop.h
            king.cpp
            king.h
            horse.cpp
            horse.h
            pawn.cpp
            pawn.h
            queen.cpp
            queen.h
            tower.cpp
            tower.h
            button.cpp
            button.h
            board.cpp
            board.h
            core.cpp
            core.h
            resources.qrc
            constants.h
            )
endif ()


target_link_libraries(Ajedrez-to PRIVATE Qt5::Widgets)

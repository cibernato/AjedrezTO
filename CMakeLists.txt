cmake_minimum_required(VERSION 3.5)

project(Emilio-Sergio-to LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "C:\\QT\\5.15.2\\mingw81_64\\lib\\cmake")
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)


if(ANDROID)
  add_library(Emilio-Sergio-to SHARED
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
else()
  add_executable(Emilio-Sergio-to
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
endif()



target_link_libraries(Emilio-Sergio-to PRIVATE Qt5::Widgets )

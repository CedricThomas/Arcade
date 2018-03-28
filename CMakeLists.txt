project(arcade)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_EXE_LINKER_FLAGS "-W -Wall -Wextra -g ")

set(sources

        #include

        Color.hpp
        entryPoint.cpp
        IGameLib.hpp
        IGraphicLib.hpp
        Keys.hpp
        PixelBox.hpp
        TextBox.hpp
        Vect.hpp

        #core

        core/main.cpp
        core/DLLoader.hpp
        core/ParseError.cpp
        core/ParseError.hpp
        core/MainParse.cpp
        core/MainParse.hpp
        core/Core.cpp
        core/Core.hpp

        #games

        games/pacman/entry.cpp
        games/nibbler/entry.cpp

        #libs

        lib/nCurses/entry.cpp
        lib/SFML/entry.cpp
        lib/SFML/SFML.cpp
        lib/SFML/SFML.hpp
        lib/SDL2/entry.cpp

        )

add_executable(arcade ${sources})

target_include_directories(arcade PRIVATE .)
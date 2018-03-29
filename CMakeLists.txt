project(arcade)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_EXE_LINKER_FLAGS "-W -Wall -Wextra -g ")

set(sources

        #api

        api/Color.hpp
        api/entryPoint.cpp
        api/IGameLib.hpp
        api/IGraphicLib.hpp
        api/Keys.hpp
        api/PixelBox.hpp
        api/TextBox.hpp
        api/Vect.hpp

        #core

        core/main.cpp
        core/DLLoader.hpp
        core/Errors.cpp
        core/Errors.hpp
        core/SyntaxAnalyser.cpp
        core/SyntaxAnalyser.hpp
        core/Core.cpp
        core/Core.hpp

        #games

        games/pacman/entry.cpp
        games/nibbler/entry.cpp

        #libs

        lib/lib_nCurses/entry.cpp
        lib/lib_nCurses/NCursesGraphicLib.cpp
        lib/lib_nCurses/NCursesGraphicLib.hpp

        lib/lib_SFML/entry.cpp
        lib/lib_SFML/SFMLGraphicLib.cpp
        lib/lib_SFML/SFMLGraphicLib.hpp

        lib/lib_SDL2/entry.cpp

        )

add_executable(arcade ${sources})

target_include_directories(arcade PRIVATE .)
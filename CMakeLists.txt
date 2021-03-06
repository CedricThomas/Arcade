project(arcade)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_EXE_LINKER_FLAGS "-W -Wall -Wextra -g ")

set(sources

        #api

        api/Color.hpp
        api/Color.cpp
        api/IGameLib.hpp
        api/IGraphicLib.hpp
        api/Keys.hpp
        api/PixelBox.hpp
        api/PixelBox.cpp
        api/TextBox.hpp
        api/TextBox.cpp
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
        core/Menu.cpp
        core/Menu.hpp
        core/ScoreManager.cpp
        core/ScoreManager.hpp

        #games

        games/pacman/entry.cpp
        games/nibbler/entry.cpp
        games/pacman/Pacman.hpp
        games/pacman/Pacman.cpp
        games/pacman/Player.hpp
        games/pacman/Player.cpp
        games/pacman/Ghost.hpp
        games/pacman/Ghost.cpp
        games/nibbler/Nibbler.cpp
        games/nibbler/Nibbler.hpp

        #libs

        lib/lib_nCurses/entry.cpp
        lib/lib_nCurses/NCursesGraphicLib.cpp
        lib/lib_nCurses/NCursesGraphicLib.hpp

        lib/lib_SFML/entry.cpp
        lib/lib_SFML/SFMLGraphicLib.cpp
        lib/lib_SFML/SFMLGraphicLib.hpp

        lib/lib_SDL2/entry.cpp
        lib/lib_SDL2/SDLGraphicLib.cpp
        lib/lib_SDL2/SDLGraphicLib.hpp


        graph/SFML/SFML.hpp
        graph/SFML/SFML.cpp
        )

add_executable(arcade ${sources})

target_include_directories(arcade PRIVATE .)
target_include_directories(arcade PRIVATE api)
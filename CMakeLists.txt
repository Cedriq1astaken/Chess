cmake_minimum_required(VERSION 3.30)
project(imguitest)

set(CMAKE_CXX_STANDARD 20)
include_directories(headers)


add_executable(imguitest
        main.cpp
        gui.cpp
        gui.h
        bindings/imgui_impl_glfw.cpp
        bindings/imgui_impl_glfw.h
        bindings/imgui_impl_opengl3.cpp
        bindings/imgui_impl_opengl3.h
        bindings/imgui_impl_opengl3_loader.h
        headers/Bishop.h
        headers/Board.h
        headers/King.h
        headers/Pawn.h
        headers/Piece.h
        headers/Queen.h
        headers/Rook.h
        src/pieces/Bishop.cpp
        src/pieces/King.cpp
        src/pieces/Knight.cpp
        src/pieces/Pawn.cpp
        src/pieces/Queen.cpp
        src/pieces/Rook.cpp
        src/Board.cpp
        src/Piece.cpp
        headers/Knight.h
)

find_package(glfw3)
find_package(glad)
find_package(imgui)
target_link_libraries(imguitest PRIVATE glfw glad::glad imgui::imgui)
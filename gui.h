//
// Created by cedri on 4/20/2025.
//
#pragma once
#include <imgui.h>

#include "Board.h"
#include "bindings/imgui_impl_glfw.h"
#include "bindings/imgui_impl_opengl3.h"

class gui {
private:
    Board theBoard;
public:
    gui(Board board);
    void Init(GLFWwindow *window, const char *glsl_version);
    void NewFrame();

    void DrawChessBoard();

    void DrawPieces(string FEN);

    void AddHighlight(int row, int col);

    void AddHightlight(int row, int col);

    void Click();

    void DrawGreenSpaces();

    void DrawRedSquares(int row, int col);

    void KingCheck();

    virtual void Update();
    void Render();
    void Shutdown();
};




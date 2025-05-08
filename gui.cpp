//
// Created by cedri on 4/20/2025.
//

#include "gui.h"
#include <iostream>
#include <string>
#include <Board.h>

/*
 *  Init, newFrame, Update, Render, Shutdown methods from https://github.com/ocornut/imgui/blob/master/imgui_demo.cpp
 */


using namespace std;


int highlight[28][2];
int i = 0;
int mode = 0;
int moves[2] = {-1, -1};
Board theBoard;
int turn = 'W'; //W == white; B == black

gui::gui(Board board) {
    theBoard = board;
}

void gui::Init(GLFWwindow* window, const char* glsl_version) {
    // Initializes the Window
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();

    for (int i = 0; i < 28; i++) {
        for (int j  = 0; j < 2; j++) {
            highlight[i][j] = -1;
        }
    }
};

void gui::NewFrame() {
    // feed inputs to dear imgui, start new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
};


void gui::DrawChessBoard() {
    //Draws the chessboard, each tile being 160 * 160 px
    ImDrawList* draw_list = ImGui::GetForegroundDrawList(); // Use background if needed

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if ((i + j)%2 == 1) {
                draw_list->AddRectFilled(
                    ImVec2(160 * i,160 * j),
                    ImVec2(160 * (i+ 1),160 * (j + 1)),
                    IM_COL32(123, 96, 95, 50)
                );
            }
            else {
                draw_list->AddRectFilled(
                    ImVec2(160 * i,160 * j),
                    ImVec2(160 * (i+ 1),160 * (j + 1)),
                    IM_COL32(237, 237, 225, 200)
                );
            }
        }
    }
}


void gui::DrawPieces(string fen) {
    //Draws pieces using letters
    ImDrawList* draw_list = ImGui::GetForegroundDrawList(); // Use background if needed

    string FEN = fen;

    int col = 0;
    int row = 0;
    for (int i = 0; i < FEN.length(); i++) {
        char current = FEN[i];
        ImU32 color = (isupper(current)) ? IM_COL32(255, 255, 255, 255) : IM_COL32(0, 0, 0, 255);
        if (isdigit(current)) {
            col += (int) current;
            col = col%8;
        }
        else if (current == '/') {
            row++;
            col = 0;
        }
        else {
            string str(1, current);
            draw_list->AddText(
            ImGui::GetFont(),
            100,
            ImVec2(160 * col + 80 - 30, 160 * row + 80 - 50),
            IM_COL32(40, 40, 40, 150),
            str.c_str()
            );
            draw_list->AddText(
            ImGui::GetFont(),
            90,
            ImVec2(160 * col + 80 - 25, 160 * row + 80 - 42),
                color,
            str.c_str()
            );
            col++;
        }
    }
}

void gui::AddHighlight(int row, int col) {
    //Puts all possible moves in an array
    for (int i = 0; i < 28; i++) {
        if (highlight[i][0] == -1) {
            highlight[i][0] = row;
            highlight[i][1] = col;
            break;
        }
    }
}
void gui::DrawGreenSpaces() {
    //Draws greeen spaces from the possible moves arrays
    ImDrawList* draw_list = ImGui::GetForegroundDrawList(); // Use background if needed
    for (int i = 0; i < 28; i++) {
        int row = highlight[i][0];
        int col = highlight[i][1];

        draw_list->AddRectFilled(
            ImVec2(160 * col,160 * row),
            ImVec2(160 * (col + 1),160 * (row + 1)),
            IM_COL32(0, 255, 0, ((row + col)%2 ? 30 : 100))
        );
    }
}

void gui::DrawRedSquares(int row, int col) {
    //Draws red square when king is in danger
    ImDrawList* draw_list = ImGui::GetForegroundDrawList(); // Use background if needed
    draw_list->AddRectFilled(
    ImVec2(160 * col,160 * row),
    ImVec2(160 * (col + 1),160 * (row + 1)),
    IM_COL32(255, 0, 0,100)
    );
}

void gui::KingCheck() {
    //Check if king is in check on the GUI side of thing
    int kingRow = -1, kingCol = -1;

    if (theBoard.isKingInCheck(turn)){
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (theBoard.board[row][col] != nullptr && (theBoard.board[row][col]->symbol == 'k' || theBoard.board[row][col]->symbol == 'K') && theBoard.board[row][col]->color == turn) {
                    kingRow = row;
                    kingCol = col;
                    break;
                }
            }
        }
    }
    else if (theBoard.isKingInCheck(((turn == 'W') ? 'B' : 'W'))) {
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (theBoard.board[row][col] != nullptr && (theBoard.board[row][col]->symbol == 'k' || theBoard.board[row][col]->symbol == 'K') && theBoard.board[row][col]->color == ((turn == 'W') ? 'B' : 'W')) {
                    kingRow = row;
                    kingCol = col;
                    break;
                }
            }
        }
    }
    DrawRedSquares(kingRow, kingCol);
}

void gui::Click() {
    //Detects if mouse was clicked and handles the logic
    if (ImGui::IsMouseClicked(0)) {
        //it is forever guaranteed that 0=Left, 1=Right, 2=Middle
        int col = (ImGui::GetMousePos()).x/160; //160 is the side length of each square
        int row = (ImGui::GetMousePos()).y/160;

        if (mode == 0){

            moves[0] = row;
            moves[1] = col;

            if (theBoard.board[row][col] != nullptr && theBoard.board[row][col]->color == turn) {

                AddHighlight(row, col);
                theBoard.displayMoves(row, col);
                cout << theBoard.board[row][col]->moveSet[7][6];

                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (theBoard.board[row][col]->moveSet[i][j]) {
                            AddHighlight(i, j);
                        }
                    }
                }

                mode++;
            }
        }
        else if (mode == 1) {
            mode = 0;

            if (theBoard.board[moves[0]][moves[1]]->moveSet[row][col]) {
                theBoard.movePieceHelper(moves[0], moves[1], row, col);
                moves[0] = -1;
                moves[1] = -1;
                turn = (mode == 0) ? ((turn == 'W') ? 'B' : 'W') : turn;
            }

            for (int i = 0; i < 28; i++) {
                for (int j  = 0; j < 2; j++) {
                    highlight[i][j] = -1;
                }
            }
            mode = 0;
        }
    }
}


void gui::Update() {
    //Refreshes the screen every frame
    DrawChessBoard();
    DrawPieces(theBoard.getFEN());
    Click();
    DrawGreenSpaces();
    KingCheck();
    i++;
};

void gui::Render() {

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
};
void gui::Shutdown() {
    //Shutdown the window when no longer needed
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
};

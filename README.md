# Chess Rule's
The goal of chess is to checkmate your opponent’s king. This means the king is under threat of capture and cannot escape.
# Game Setup
<br><img src="https://github.com/user-attachments/assets/18818b34-3108-4b54-91a9-500ceeaf4ee4" Width="300" />
1. Each player starts with 16 pieces: 1 King, 1 Queen, 2 Rooks, 2 Bishops, 2 Knights, and 8 Pawns.
2. The board has 64 squares, arranged in an 8×8 grid.
3. White always moves first.
# How Each Piece Move's
1. king(K)
   <br><img src= "https://github.com/user-attachments/assets/56bd3e9a-4ede-4e5c-befd-1d443ca18a6a" width="300" />
   * Moves one square in any direction.
   * Cannot move into check.
   * Special move: Castling.
3. Queen(Q)
   <br><img src= "https://github.com/user-attachments/assets/5aea2c54-8c67-45cf-bc14-cc797f32647d" width="300" />
   * Moves any number of squares and captures in any direction: horizontal, vertical, or diagonal.
4. Rook(R)
   <br><img src= "https://github.com/user-attachments/assets/13990b23-441f-46a4-8181-a0aa45fdf8ef" width="300" />
   * moves any number of squares horizontally or vertically.
   * particpates in castling
5. Bishop(B)
   <br><img src= "https://github.com/user-attachments/assets/c7ede398-05fd-44bd-aa27-287eeec5bbab" width="300" />
   * Moves diagonally any number of squares.
6. Knight(N)
   <br><img src= "https://github.com/user-attachments/assets/8058b921-5dd8-476a-8ca8-f0917baf619d" width="300" />
   * Moves in an L-shape: two squares in one direction, then one square perpendicular.
   * Can jump over other pieces.
7. Pawn(P)
   <br><img src= "https://github.com/user-attachments/assets/2fb40cc4-b827-4304-96bb-e35c75a57415" width="300" />
   * Moves forward one square (or two from its starting position).
   * Captures diagonally.
   * Special moves:
      * En passant: Capture a pawn that has just moved two squares forward, as if it had moved only one.
      * Promotion: When a pawn reaches the opposite end, it must be promoted (usually to a queen).
# Special Rules
1. Castling

https://github.com/user-attachments/assets/67928079-f7d5-4a45-bdb9-123f285869cd

   * A one-time move involving the king and a rook.
   * Conditions:
     * Neither piece has moved.
     * No pieces between the king and rook.
     * The king is not in, through, or into check.
   * King moves two squares toward the rook, rook jumps over the king.
3. Pawn Pronotion
   * When a pawn reaches the opposite rank (8th for white, 1st for black), it must be promoted to a Queen, Rook, Bishop, or
     Knight (usually a Queen).
4. Check and Checkmate

https://github.com/user-attachments/assets/972832f1-1423-4640-95e2-81fe799e0af8

   * Check: King is under attack.
   * Checkmate: King is in check and cannot escape = game over.
   * You must move out of check; you cannot leave your king in check.
5. Stalemate and Draws
   * Stalemate: A player has no legal moves, but is not in check = draw.
   * Other draws:
     * Agreement between players.
     * Insufficient material to checkmate.
     * 50-move rule: no pawn movement or captures in 50 moves.
     * Threefold repetition: same position appears 3 times.


# Group contributions to the project. (Put your contributions to the project in here. afterwards delete this comente)
 # Alessandro 
 # Cedric 
 For our C++ game project, I was responsible for writting some of the initial game logic, dividing the code into different classes and making sure everybody's code work together with minimal. I was also responsible for implementing the Gui using dear IMGUI library and making sure the game logic works well with the GUI.
 # Sergio
For our C++ chess game project, I was responsible for implementing the full movement logic for all six chess pieces—Rook, Knight, Bishop, Queen, King, and Pawn—adhering to object-oriented design principles. While the base PieceClass was authored by another teammate, I developed all derived subclasses, overriding the displayMoves() method in each to define legal movement patterns per chess rules. I also designed and implemented the Board class, which manages the 8x8 grid, initializes the standard starting layout for both colors, and handles piece placement, movement, and capture logic. The board uses a Piece* board[8][8] structure, and my logic marks valid move squares with '1' and possible captures with 'X', enabling visualization of threats and legal options. In total, I contributed over 500 lines of code in my initial branch that were later used and adapted by other teammates. My work forms the core backend logic of the game engine, which other team members will extend with UI integration, special move support (e.g., castling, en passant), and full game control flow.
 # Szymon
 # Safwaan
    Worked on the following:
   - Created a function that can move a piece from one position to another in an array
   - Created a function that checks if the "King is in check"
   - Created a function that returns the FEN of the chessboard
   - Created a "Castling" function


# Libraries used
Dear ImGui <br>
Glfw3 <br>
Glad


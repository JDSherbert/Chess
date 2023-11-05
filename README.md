![image](https://github.com/JDSherbert/Chess/assets/43964243/bb5c2a73-c100-48ce-ba4f-6dbcd80220f9)

# Chess

<!-- Header Start -->
  <a href = "https://learn.microsoft.com/en-us/cpp/cpp-language"> <img align="left" img height="40" img width="40" src="https://cdn.simpleicons.org/c++"> </a>
<img align="right" alt="Stars Badge" src="https://img.shields.io/github/stars/jdsherbert/Chess?label=%E2%AD%90"/>
<img align="right" alt="Forks Badge" src="https://img.shields.io/github/forks/jdsherbert/Chess?label=%F0%9F%8D%B4"/>
<img align="right" alt="Watchers Badge" src="https://img.shields.io/github/watchers/jdsherbert/Chess?label=%F0%9F%91%81%EF%B8%8F"/>
<img align="right" alt="Issues Badge" src="https://img.shields.io/github/issues/jdsherbert/Chess?label=%E2%9A%A0%EF%B8%8F"/>
<img align="right" src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FJDSherbert%2FChess%2Fhit-counter%2FREADME&count_bg=%2379C83D&title_bg=%23555555&labelColor=0E1128&title=🔍&style=for-the-badge">
  <br></br>
  -----------------------------------------------------------------------
  <a href="https://learn.microsoft.com/en-us/cpp/cpp-language"> 
  <img align="top" alt="C++ Console Application" src="https://img.shields.io/badge/C++%20Console%20Application-FFFFFF?style=for-the-badge&logo=visualstudio&color=000000&labelColor=5C2D91"> </a>

  <a href="https://choosealicense.com/licenses/mit/"> 
  <img align="right" alt="License" src="https://img.shields.io/badge/License%20:%20MIT-black?style=for-the-badge&logo=mit&logoColor=white&color=black&labelColor=black"> </a>
  
  -----------------------------------------------------------------------
This is a simple command-line chess game implemented in C++. It allows you to play against an AI player using basic chess rules.

## Features

- Human vs AI gameplay
- Basic chess piece movements (pawn, knight, bishop, rook, queen, king)
- Valid move checking
- Alpha-beta pruning for AI player using the Minimax algorithm
- Evaluation function to assess the board position

## Getting Started

To compile and run the game, you'll need a C++ compiler installed on your system. Follow these steps:

1. Clone the repository to your local machine:

```shell
   git clone https://github.com/JDSherbert/Chess.git
```
Navigate to the project directory:

```shell
cd Chess
```
Compile the code (exact method will depend on your compiler):

```shell
g++ -std=c++11 Chess.cpp -o Chess
```
Run the game:

```shell
./chess
```
Follow the on-screen instructions to play the game.

## How to Play
The chessboard is displayed as an 8x8 grid.
The black pieces are represented by Unicode symbols.
The white pieces are represented by uppercase letters.
Moves are entered in the format "from_square to_square" (e.g., "e2 e4" to move a pawn from e2 to e4).
The game alternates between the human player and the AI player.
The AI player uses the Minimax algorithm with alpha-beta pruning to make its moves.

### Example Gameplay

```mathematica
  A  B  C  D  E  F G  H
1 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
2 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
3
4
5
6
7 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
8 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖

Enter your move (e.g., 'e2 to e4'): e2 e4

  A  B  C  D  E  F G  H
1 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
2 ♟ ♟ ♟    ♟ ♟ ♟ ♟
3
4          ♟
5
6
7 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
8 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖

AI moved: g8 f6
  A  B  C  D  E  F G  H
1 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
2 ♟ ♟ ♟    ♟ ♟ ♟ ♟
3
4          ♟
5
6               ♘
7 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
8 ♖ ♘ ♗ ♕ ♔ ♗    ♖
```

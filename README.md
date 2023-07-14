![image](https://github.com/JDSherbert/Chess/assets/43964243/bb5c2a73-c100-48ce-ba4f-6dbcd80220f9)

# Chess

<!-- Header Start -->
  <a href = "https://learn.microsoft.com/en-us/cpp/cpp-language"> <img align="left" img height="40" img width="40" src="https://cdn.simpleicons.org/c++"> </a>
  <img align="right" alt="stars badge" src="https://img.shields.io/github/stars/jdsherbert/Chess"/>
  <img align="right" alt="forks badge" src="https://img.shields.io/github/forks/jdsherbert/Chess=Fork"/>
  <img align="right" alt="watching badge" src="https://img.shields.io/github/watchers/jdsherbert/Chess"/>
  <br></br>
  -----------------------------------------------------------------------
  <a href="https://learn.microsoft.com/en-us/cpp/cpp-language"> 
  <img align="top" alt="C++ Console Application" src="https://img.shields.io/badge/C++%20Console%20Application-FFFFFF?style=for-the-badge&logo=cpp&logoColor=black&color=black&labelColor=FFFFFF"> </a>
  
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
Compile the code:

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
   A B C D E F G H
1 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
2 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
3
4
5
6
7 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
8 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖

Enter your move (e.g., 'e2 e4'): e2 e4

   A B C D E F G H
1 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
2 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
3
4          ♙
5
6
7 ♙ ♙ ♙ ♙   ♙ ♙ ♙
8 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖

AI moved: g8 f6
   A B C D E F G H
1 ♜ ♞ ♝ ♛ ♚ ♝   ♜
2 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
3
4          ♙
5
6        ♞
7 ♙ ♙ ♙ ♙   ♙ ♙ ♙
8 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖
```

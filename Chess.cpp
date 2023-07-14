// ©2023 JDSherbert

#include <iostream>
#include <vector>
#include <limits>

// Chess board dimensions
const int BOARD_SIZE = 8;

// Chess piece representation
enum class Piece 
{
    None,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};

// Chess player representation
enum class Player 
{
    None,
    White,
    Black
};

// Chess piece and its owning player
struct ChessPiece 
{
    Piece piece;
    Player player;
};

// Chessboard representation
using Chessboard = std::vector<std::vector<ChessPiece>>;

// Function to initialize the chessboard
void initializeChessboard(Chessboard& board) 
{
    // Set up the black pieces
    board[0][0] = {Piece::Rook, Player::Black};
    board[0][1] = {Piece::Knight, Player::Black};
    board[0][2] = {Piece::Bishop, Player::Black};
    board[0][3] = {Piece::Queen, Player::Black};
    board[0][4] = {Piece::King, Player::Black};
    board[0][5] = {Piece::Bishop, Player::Black};
    board[0][6] = {Piece::Knight, Player::Black};
    board[0][7] = {Piece::Rook, Player::Black};
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        board[1][i] = {Piece::Pawn, Player::Black};
    }

    // Set up the white pieces
    board[7][0] = {Piece::Rook, Player::White};
    board[7][1] = {Piece::Knight, Player::White};
    board[7][2] = {Piece::Bishop, Player::White};
    board[7][3] = {Piece::Queen, Player::White};
    board[7][4] = {Piece::King, Player::White};
    board[7][5] = {Piece::Bishop, Player::White};
    board[7][6] = {Piece::Knight, Player::White};
    board[7][7] = {Piece::Rook, Player::White};
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        board[6][i] = {Piece::Pawn, Player::White};
    }

    // Fill the rest of the board with empty spaces
    for (int i = 2; i < 6; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            board[i][j] = {Piece::None, Player::None};
        }
    }
}

// Function to print the chessboard
void printChessboard(const Chessboard& board) 
{
    std::cout << "   A B C D E F G H" << std::endl;
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        std::cout << i + 1 << " ";
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            const ChessPiece& piece = board[i][j];
            if (piece.player == Player::Black) 
            {
                switch (piece.piece) 
                {
                    case Piece::Pawn: std::cout << "♟ "; break;
                    case Piece::Knight: std::cout << "♞ "; break;
                    case Piece::Bishop: std::cout << "♝ "; break;
                    case Piece::Rook: std::cout << "♜ "; break;
                    case Piece::Queen: std::cout << "♛ "; break;
                    case Piece::King: std::cout << "♚ "; break;
                    default: std::cout << "  ";
                }
            } 
            else if (piece.player == Player::White) 
            {
                switch (piece.piece) 
                {
                    case Piece::Pawn: std::cout << "♙ "; break;
                    case Piece::Knight: std::cout << "♘ "; break;
                    case Piece::Bishop: std::cout << "♗ "; break;
                    case Piece::Rook: std::cout << "♖ "; break;
                    case Piece::Queen: std::cout << "♕ "; break;
                    case Piece::King: std::cout << "♔ "; break;
                    default: std::cout << "  ";
                }
            } 
            else 
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

// Function to check if a move is valid
bool isValidMove(const Chessboard& board, int fromX, int fromY, int toX, int toY, Player player) 
{
    const ChessPiece& fromPiece = board[fromX][fromY];
    const ChessPiece& toPiece = board[toX][toY];

    if (fromPiece.player != player || fromPiece.piece == Piece::None) 
    {
        return false;
    }

    if (fromX == toX && fromY == toY) 
    {
        return false;
    }

    switch (fromPiece.piece) 
    {
        case Piece::Pawn:
            if (fromPiece.player == Player::White) 
            {
                if (fromX == 6 && toX == 4 && fromY == toY && toPiece.piece == Piece::None) 
                {
                    return true;
                }
                if (fromX - 1 == toX && fromY == toY && toPiece.piece == Piece::None) 
                {
                    return true;
                }
                if (fromX - 1 == toX && (fromY - 1 == toY || fromY + 1 == toY) && toPiece.player == Player::Black) 
                {
                    return true;
                }
            } 
            else 
            {
                if (fromX == 1 && toX == 3 && fromY == toY && toPiece.piece == Piece::None) 
                {
                    return true;
                }
                if (fromX + 1 == toX && fromY == toY && toPiece.piece == Piece::None) 
                {
                    return true;
                }
                if (fromX + 1 == toX && (fromY - 1 == toY || fromY + 1 == toY) && toPiece.player == Player::White) 
                {
                    return true;
                }
            }
            break;

        case Piece::Knight:
            if ((std::abs(fromX - toX) == 2 && std::abs(fromY - toY) == 1) ||
                (std::abs(fromX - toX) == 1 && std::abs(fromY - toY) == 2)) 
            {
                return true;
            }
            break;

        case Piece::Bishop:
            if (std::abs(fromX - toX) == std::abs(fromY - toY)) 
            {
                int dx = (toX > fromX) ? 1 : -1;
                int dy = (toY > fromY) ? 1 : -1;
                int x = fromX + dx;
                int y = fromY + dy;
                while (x != toX) 
                {
                    if (board[x][y].piece != Piece::None) 
                    {
                        return false;
                    }
                    x += dx;
                    y += dy;
                }
                return true;
            }
            break;

        case Piece::Rook:
            if (fromX == toX || fromY == toY) 
            {
                int dx = (fromX == toX) ? 0 : ((toX > fromX) ? 1 : -1);
                int dy = (fromY == toY) ? 0 : ((toY > fromY) ? 1 : -1);
                int x = fromX + dx;
                int y = fromY + dy;
                while (x != toX || y != toY) 
                {
                    if (board[x][y].piece != Piece::None) 
                    {
                        return false;
                    }
                    x += dx;
                    y += dy;
                }
                return true;
            }
            break;

        case Piece::Queen:
            if (fromX == toX || fromY == toY || std::abs(fromX - toX) == std::abs(fromY - toY)) 
            {
                int dx = (fromX == toX) ? 0 : ((toX > fromX) ? 1 : -1);
                int dy = (fromY == toY) ? 0 : ((toY > fromY) ? 1 : -1);
                int x = fromX + dx;
                int y = fromY + dy;
                while (x != toX || y != toY) 
                {
                    if (board[x][y].piece != Piece::None) 
                    {
                        return false;
                    }
                    x += dx;
                    y += dy;
                }
                return true;
            }
            break;

        case Piece::King:
            if (std::abs(fromX - toX) <= 1 && std::abs(fromY - toY) <= 1) 
            {
                return true;
            }
            break;

        default:
            return false;
    }

    return false;
}

// Function to make a move on the chessboard
void makeMove(Chessboard& board, int fromX, int fromY, int toX, int toY) 
{
    board[toX][toY] = board[fromX][fromY];
    board[fromX][fromY] = {Piece::None, Player::None};
}

// Function to evaluate the chessboard position
int evaluatePosition(const Chessboard& board) 
{
    int whiteScore = 0;
    int blackScore = 0;

    // Piece values
    const int pawnValue = 1;
    const int knightValue = 3;
    const int bishopValue = 3;
    const int rookValue = 5;
    const int queenValue = 9;

    // Evaluate each piece on the board
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            const ChessPiece& piece = board[i][j];
            if (piece.player == Player::White) 
            {
                switch (piece.piece) 
                {
                    case Piece::Pawn: whiteScore += pawnValue; break;
                    case Piece::Knight: whiteScore += knightValue; break;
                    case Piece::Bishop: whiteScore += bishopValue; break;
                    case Piece::Rook: whiteScore += rookValue; break;
                    case Piece::Queen: whiteScore += queenValue; break;
                    default: break;
                }
            } 
            else if (piece.player == Player::Black) 
            {
                switch (piece.piece) 
                {
                    case Piece::Pawn: blackScore += pawnValue; break;
                    case Piece::Knight: blackScore += knightValue; break;
                    case Piece::Bishop: blackScore += bishopValue; break;
                    case Piece::Rook: blackScore += rookValue; break;
                    case Piece::Queen: blackScore += queenValue; break;
                    default: break;
                }
            }
        }
    }

    // Return the difference between white and black scores
    return whiteScore - blackScore;
}

// Minimax algorithm with alpha-beta pruning
int minimax(Chessboard& board, int depth, int alpha, int beta, bool maximizingPlayer) 
{
    // Base case: reached maximum depth or end of the game
    if (depth == 0) 
    {
        return evaluatePosition(board);
    }

    // Get all valid moves for the current player
    Player currentPlayer = maximizingPlayer ? Player::White : Player::Black;
    std::vector<std::tuple<int, int, int, int>> validMoves;
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            if (board[i][j].player == currentPlayer) 
            {
                for (int k = 0; k < BOARD_SIZE; k++) 
                {
                    for (int l = 0; l < BOARD_SIZE; l++) 
                    {
                        if (isValidMove(board, i, j, k, l, currentPlayer)) 
                        {
                            validMoves.push_back(std::make_tuple(i, j, k, l));
                        }
                    }
                }
            }
        }
    }

    // If no valid moves, it's a stalemate or checkmate
    if (validMoves.empty()) 
    {
        return 0;
    }

    // Apply the minimax algorithm with alpha-beta pruning
    if (maximizingPlayer) 
    {
        int maxScore = std::numeric_limits<int>::min();
        for (const auto& move : validMoves) 
        {
            int fromX, fromY, toX, toY;
            std::tie(fromX, fromY, toX, toY) = move;

            Chessboard boardCopy = board;
            makeMove(boardCopy, fromX, fromY, toX, toY);

            int score = minimax(boardCopy, depth - 1, alpha, beta, false);
            maxScore = std::max(maxScore, score);
            alpha = std::max(alpha, score);

            if (beta <= alpha) 
            {
                break;
            }
        }
        return maxScore;
    } 
    else 
    {
        int minScore = std::numeric_limits<int>::max();
        for (const auto& move : validMoves) 
        {
            int fromX, fromY, toX, toY;
            std::tie(fromX, fromY, toX, toY) = move;

            Chessboard boardCopy = board;
            makeMove(boardCopy, fromX, fromY, toX, toY);

            int score = minimax(boardCopy, depth - 1, alpha, beta, true);
            minScore = std::min(minScore, score);
            beta = std::min(beta, score);

            if (beta <= alpha) 
            {
                break;
            }
        }
        return minScore;
    }
}

// Function for AI to make a move using the minimax algorithm
void makeAIMove(Chessboard& board) 
{
    int maxScore = std::numeric_limits<int>::min();
    int bestFromX, bestFromY, bestToX, bestToY;

    // Get all valid moves for the AI player
    Player currentPlayer = Player::White;
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            if (board[i][j].player == currentPlayer) 
            {
                for (int k = 0; k < BOARD_SIZE; k++) 
                {
                    for (int l = 0; l < BOARD_SIZE; l++) 
                    {
                        if (isValidMove(board, i, j, k, l, currentPlayer)) 
                        {
                            Chessboard boardCopy = board;
                            makeMove(boardCopy, i, j, k, l);

                            int score = minimax(boardCopy, 3, std::numeric_limits<int>::min(),
                                                std::numeric_limits<int>::max(), false);

                            if (score > maxScore) 
                            {
                                maxScore = score;
                                bestFromX = i;
                                bestFromY = j;
                                bestToX = k;
                                bestToY = l;
                            }
                        }
                    }
                }
            }
        }
    }

    // Make the best move
    makeMove(board, bestFromX, bestFromY, bestToX, bestToY);
    std::cout << "AI moved: " << bestFromX << bestFromY << " to " << bestToX << bestToY << std::endl;
}

int main() 
{
    Chessboard board(BOARD_SIZE, std::vector<ChessPiece>(BOARD_SIZE, {Piece::None, Player::None}));
    initializeChessboard(board);

    Player currentPlayer = Player::White;

    while (true) {
        printChessboard(board);

        if (currentPlayer == Player::White) 
        {
            // Human player's turn
            char fromCol, toCol;
            int fromRow, toRow;

            std::cout << "Enter your move (e.g., 'e2 e4'): ";
            std::cin >> fromCol >> fromRow >> toCol >> toRow;

            int fromX = fromRow - 1;
            int fromY = fromCol - 'a';
            int toX = toRow - 1;
            int toY = toCol - 'a';

            if (isValidMove(board, fromX, fromY, toX, toY, currentPlayer)) 
            {
                makeMove(board, fromX, fromY, toX, toY);
                currentPlayer = Player::Black;
            } 
            else 
            {
                std::cout << "Invalid move. Try again!" << std::endl;
            }
        } 
        else 
        {
            // AI player's turn
            makeAIMove(board);
            currentPlayer = Player::White;
        }
    }

    return 0;
}

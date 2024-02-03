#include <iostream>

class TicTacToe {
private:
    char board[3][3];
    bool player1_turn;

public:
    TicTacToe() {
        player1_turn = true;

        // Initialize the board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void printBoard() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) {
                    std::cout << " | ";
                }
            }
            std::cout << std::endl;
            if (i < 2) {
                std::cout << "---------" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    void makeMove() {
        int row, col;

        // Asks the user first the row and next the column
        if (player1_turn) {
            std::cout << "Player X's turn. Enter row (1-3): ";
            std::cin >> row;

            std::cout << "Enter column (1-3): ";
            std::cin >> col;
        } else {
            std::cout << "Player O's turn. Enter row (1-3): ";
            std::cin >> row;

            std::cout << "Enter column (1-3): ";
            std::cin >> col;
        }

        // Adjust to zero-based indices
        --row;
        --col;

        if (isValidMove(row, col)) {
            char symbol = (player1_turn) ? 'X' : 'O';
            board[row][col] = symbol;
            player1_turn = !player1_turn;
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
            makeMove();
        }
    }

    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    bool checkForWinner() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;  // Winner in the row
            }

            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;  // Winner in the column
            }
        }

        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;  // Winner in the diagonal
        }

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;  // Winner in the diagonal
        }

        return false;
    }

    bool isBoardFull() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;  // There is an empty space, the board is not full
                }
            }
        }
        return true;  // No empty space, the board is full
    }

    void play() {
        while (!checkForWinner() && !isBoardFull()) {
            printBoard();
            makeMove();
        }

        printBoard();

        if (checkForWinner()) {
            std::cout << "Player " << ((player1_turn) ? 'O' : 'X') << " wins!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }
    }
};

int main() {
    TicTacToe game;
    game.play();

    return 0;
}

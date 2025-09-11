#include <iostream>
#include <vector>

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';

void print_board(const std::vector<std::vector<char>>& board) {
    std::cout << '\n';
    std::cout << " "  << board.at(0).at(0);
    for (int i = 1; i < 3; i++) {
        std::cout << " | " << board.at(0).at(i);
    }
    std::cout << "\n";
    for (int i = 1; i < 3; i++) {
        std::cout << "---+---+---\n";
        std::cout << " "  << board.at(i).at(0);
        for (int j = 1; j < 3; j++) {
            std::cout << " | " << board.at(i).at(i);
        }
        std::cout << "\n";
    }
}

void place_X(std::vector<std::vector<char>>& board, size_t row, size_t column) {
    board.at(row).at(column) = X;
}

void place_O(std::vector<std::vector<char>>& board, size_t row, size_t column) {
    board.at(row).at(column) = O;
}

int main() {
    std::vector<std::vector<char>> board(3, {EMPTY, EMPTY, EMPTY});
    print_board(board);
    place_X(board, 1, 1);
    print_board(board);
    place_O(board, 0, 2);
    print_board(board);
    place_X(board, 1, 2);
    print_board(board);
    return 0;
}

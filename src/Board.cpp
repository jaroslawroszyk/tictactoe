#include "Board.hpp"

#include <iostream>
#include <string>

void Board::drawBoard() const {
    std::cout << "----1---2---3--\n";
    size_t row_cnt{1};
    for (const auto& row : m_board) {
        std::cout << row_cnt++ << " | ";
        for (const auto field : row) {
            std::cout << field << " | ";
        }
        std::cout << '\n';
    }
    std::cout << "---------------\n";
}

void Board::refresh(size_t row, size_t col, char mark) {
    mark = static_cast<char>(std::toupper(mark));
    if (m_board[row - 1][col - 1] == '_' and (mark == 'X' or mark == 'O')) {
        m_board[row - 1][col - 1] = mark; // -1 cus of array indexing
    }
}

Input Board::getUserInput() {
    size_t row, col;
    char mark;
    std::cout << "Row: ";
    std::cin >> row;
    std::cout << "Col: ";
    std::cin >> col;
    std::cout << "Mark: ";
    std::cin >> mark;
    return {row, col, mark};
}

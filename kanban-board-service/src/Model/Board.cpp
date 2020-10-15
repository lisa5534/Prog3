#include "Board.hpp"

using namespace Prog3::Model;

Board::Board(std::string givenTitle) : title(givenTitle) {}

std::string Board::getTitle() {
    return title;
}

void Board::setTitle(std::string givenTitle) {
    title = givenTitle;
}

std::vector<Column> Board::getColumns() {
    return columns;
}

void Board::addColumn(Column givenColumn) {
    columns.push_back(givenColumn);
}
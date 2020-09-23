#include "Board.hpp"

using namespace Prog3::Repository::Model;

Board::Board(std::string givenTitle):
    title(givenTitle)
{ }

std::string Board::getTitle()
{
    return title;
}

std::vector<Column> Board::getColumns()
{
    return columns;
}

void Board::addColumn(Column givenColumn)
{
    columns.push_back(givenColumn);
}
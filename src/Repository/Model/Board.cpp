#include "Board.hpp"

using namespace Prog3::Repository::Model;

Board::Board(std::string name):
    name(name)
{ }

std::string Board::getName()
{
    return name;
}

std::vector<Column> Board::getColumns()
{
    return columns;
}

void Board::addColumn(Column givenColumn)
{
    columns.push_back(givenColumn);
}
#pragma once

#include <string>
#include <iostream>
#include <vector>


namespace Prog3 { namespace Repository { namespace Model {

typedef struct Column 
{
    int id;
    std::string name;
    int position;
    std::vector<std::string> items;
} Column;

class Board
{
public:
    Board(std::string givenTitle);
    Board(Board &&) = default;
    Board(const Board &) = default;
    Board &operator=(Board &&) = default;
    Board &operator=(const Board &) = default;
    ~Board() {}

    std::string getTitle();
    std::vector<Column> getColumns();
    void addColumn(Column givenColumn);

private:

    std::string title;
    std::vector<Column> columns;
};

}}}
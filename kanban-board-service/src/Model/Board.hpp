#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Prog3 {
namespace Model {

typedef struct Column {
    int id;
    std::string name;
    int position;
    std::vector<std::string> items;
} Column;

class Board {
  public:
    Board(std::string givenTitle);
    Board() = default;
    ~Board() {}

    std::string getTitle();

    std::vector<Column> &getColumns();
    void addColumn(Column &givenColumn);

  private:
    std::string title;
    std::vector<Column> columns;
};

} // namespace Model
} // namespace Prog3

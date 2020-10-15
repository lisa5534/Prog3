#include "BoardRepository.hpp"
#include <vector>

using namespace Prog3::Repository::DatabaseMock;
using namespace std;

Prog3::Model::Board BoardRepository::getBoard() {
    vector<string> fakeItems = {"todo", "tableFlip", "zelda"};

    Model::Column fakeColumn = {0};
    fakeColumn.id = 7;
    fakeColumn.name = "FakeColumn";
    fakeColumn.position = 0;
    fakeColumn.items = fakeItems;

    board->addColumn(fakeColumn);

    return *board;
}

void BoardRepository::initialize() {
    std::string boardTitle("Mock - Kanban Board");

    board = new Model::Board(boardTitle);
}

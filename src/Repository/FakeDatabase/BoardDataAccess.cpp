#include "BoardDataAccess.hpp"
#include <vector>

using namespace Prog3::Repository::FakeDatabase;
using namespace std;

Prog3::Model::Board BoardDataAccess::getBoard()
{
    vector<string> fakeItems = {"todo", "tableFlip", "zelda"};

    Model::Column fakeColumn = {0};
    fakeColumn.id = 7;
    fakeColumn.name = "FakeColumn";
    fakeColumn.position = 0;
    fakeColumn.items = fakeItems;
    
    Model::Board * board = new Model::Board("FakeDataBase *_* ");
    board->addColumn(fakeColumn);

    return *board;
}
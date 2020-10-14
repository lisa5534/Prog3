#include "BoardRepository.hpp"

using namespace Prog3::Repository::SQLite;
using namespace Prog3::Model;

BoardRepository::BoardRepository()
  : database(nullptr)
{
  int result;

  result = sqlite3_open("../data/kanban-board.db", &database);

  if (result)
  {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
  }
  else
  {
    fprintf(stderr, "Opened database successfully\n");
  }
}

BoardRepository::~BoardRepository()
{
    sqlite3_close(database);
}

Prog3::Model::Board BoardRepository::getBoard()
{
    Board board = Board("title");
    return board;
}

void BoardRepository::initialize()
{
  return;
}

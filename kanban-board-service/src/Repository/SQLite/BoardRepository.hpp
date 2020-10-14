#pragma once

#include "Repository/RepositoryIf.hpp"
#include "sqlite3.h"

namespace Prog3 { namespace Repository { namespace SQLite {

class BoardRepository : public RepositoryIf
{
private:
  sqlite3 * database;

public:
  BoardRepository();
  virtual ~BoardRepository();
  virtual Prog3::Model::Board getBoard();
  virtual void initialize();
};

}}}


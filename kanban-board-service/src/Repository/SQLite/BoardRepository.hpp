#pragma once

#include "Repository/RepositoryIf.hpp"
#include "sqlite3.h"

namespace Prog3 {
namespace Repository {
namespace SQLite {

class BoardRepository : public RepositoryIf {
  private:
    sqlite3 *database;

    void handleSQLError(int statementResult, char *errorMessage);
    static int queryBoardCallback(void *data, int numberOfColumns, char **fieldValues, char **columnNames);

  public:
    BoardRepository();
    virtual ~BoardRepository();
    virtual Prog3::Model::Board getBoard();
    virtual void initialize();

    static const std::string boardTitle;
    static const std::string databasePath;

    void createDummyData();
};

} // namespace SQLite
} // namespace Repository
} // namespace Prog3

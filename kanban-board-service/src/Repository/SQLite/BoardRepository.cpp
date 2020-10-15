#include "BoardRepository.hpp"
#include <filesystem>
#include <string.h>

using namespace Prog3::Repository::SQLite;
using namespace Prog3::Model;
using namespace std;

const std::string BoardRepository::boardTitle = "Kanban Board";
const std::string BoardRepository::databasePath = "../data/kanban-board.db";

BoardRepository::BoardRepository() : database(nullptr) {

    string dataDirectory = "../data/";

    if (filesystem::is_directory(dataDirectory) == false) {
        filesystem::create_directory(dataDirectory);
    }

    int result = sqlite3_open(databasePath.c_str(), &database);

    if (SQLITE_OK != result) {
        cout << "Cannot open database: " << sqlite3_errmsg(database) << endl;
    }
}

BoardRepository::~BoardRepository() {
    sqlite3_close(database);
}

void BoardRepository::initialize() {
    int result = 0;
    char *errorMessage = nullptr;

    string sqlCreateTableBoard =
        "CREATE TABLE IF NOT EXISTS board("
        "id INT PRIMARY KEY NOT NULL,"
        "title TEXT NOT NULL);";

    result = sqlite3_exec(database, sqlCreateTableBoard.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    string sqlInsertBoardTitle = string("INSERT OR IGNORE INTO board (id, title) VALUES (1, '") + boardTitle + "');";

    result = sqlite3_exec(database, sqlInsertBoardTitle.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);
}

Prog3::Model::Board BoardRepository::getBoard() {

    Board board = Board();

    string sqlQueryBoard = "SELECT title from board";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlQueryBoard.c_str(), queryBoardCallback, &board, &errorMessage);
    handleSQLError(result, errorMessage);

    return board;
}

int BoardRepository::queryBoardCallback(void *data, int numberOfColumns, char **fieldValues, char **columnNames) {

    Board *board = static_cast<Board *>(data);

    int titleColumnIndex = 0;

    if (strcmp(columnNames[titleColumnIndex], "title") == 0) {
        board->setTitle(fieldValues[titleColumnIndex] ? fieldValues[titleColumnIndex] : "unknown Board");
    }

    return 0;
}

void BoardRepository::handleSQLError(int statementResult, char *errorMessage) {

    if (statementResult != SQLITE_OK) {
        cout << "SQL error: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    }
}

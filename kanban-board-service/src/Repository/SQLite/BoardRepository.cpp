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

    string sqlCreateTableColumn =
        "create table if not exists column("
        "id integer primary key autoincrement,"
        "name text not null,"
        "position integer not null UNIQUE);";

    string sqlCreateTableItem =
        "create table if not exists item("
        "id integer primary key autoincrement,"
        "title text not null,"
        "date text not null,"
        "position integer not null,"
        "column_id integer not null,"
        "unique (position, column_id),"
        "foreign key (column_id) references column (id));";

    result = sqlite3_exec(database, sqlCreateTableColumn.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);
    result = sqlite3_exec(database, sqlCreateTableItem.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    // only if needed ;)
    //createDummyData();
}

Prog3::Model::Board BoardRepository::getBoard() {

    Board board = Board(boardTitle);

    string sqlQueryBoard =
        "SELECT column.id, name, column.position, title, date, item.position from column "
        "join item on item.column_id = column.id "
        "order by column.position, item.position";

    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlQueryBoard.c_str(), queryBoardCallback, &board, &errorMessage);
    handleSQLError(result, errorMessage);

    return board;
}

int BoardRepository::queryBoardCallback(void *data, int numberOfColumns, char **fieldValues, char **columnNames) {

    Board *board = static_cast<Board *>(data);

    Column column = {0};

    for (int i = 0; i < numberOfColumns; i++) {
        cout << columnNames[i] << ": " << fieldValues[i] << endl;
    }

    uint32_t positionOfColumn = static_cast<uint32_t>(atoi(fieldValues[2]));
    string item = fieldValues[3];

    std::vector<Column> &columns = board->getColumns();

    if (columns.size() < positionOfColumn) {
        column.id = atoi(fieldValues[0]);
        column.name = fieldValues[1];
        column.position = atoi(fieldValues[2]);
        column.items.push_back(item);

        board->addColumn(column);
    } else {
        Column &refToColumn = columns.at(positionOfColumn - 1);
        refToColumn.items.push_back(item);
    }
    return 0;
}

void BoardRepository::handleSQLError(int statementResult, char *errorMessage) {

    if (statementResult != SQLITE_OK) {
        cout << "SQL error: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    }
}

void BoardRepository::createDummyData() {

    cout << "creatingDummyData ..." << endl;

    int result = 0;
    char *errorMessage;
    string sqlInsertDummyColumns =
        "insert into column (name, position)"
        "VALUES"
        "(\"prepare\", 1),"
        "(\"running\", 2),"
        "(\"finished\", 3);";

    result = sqlite3_exec(database, sqlInsertDummyColumns.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    string sqlInserDummyItems =
        "insert into item (title, date, position, column_id)"
        "VALUES"
        "(\"in plan\", date('now'), 1, 1),"
        "(\"some running task\", date('now'), 1, 2),"
        "(\"finished task 1\", date('now'), 1, 3),"
        "(\"finished task 2\", date('now'), 2, 3);";

    result = sqlite3_exec(database, sqlInserDummyItems.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);
}

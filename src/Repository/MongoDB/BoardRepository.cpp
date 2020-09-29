#include "BoardRepository.hpp"

#include <vector>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using namespace Prog3::Repository::MongoDB;
using namespace bsoncxx::builder::stream;
using namespace std;

const std::string BoardRepository::databaseName = "Prog3";
const std::string BoardRepository::collectionName = "Board";

BoardRepository::BoardRepository(std::string connectionString):
    mongoClient(mongocxx::uri(connectionString))
{
    mongocxx::instance instance{}; //initialize mongoDB driver only once!
    std::cout << "created MongoDB::BoardRepository with connection string: " << connectionString << std::endl;


    boardCollection = mongoClient[databaseName][collectionName];
    // upsertBoard();

    cout << "MongoDB::BoardRepository databaseName: " << databaseName << " collectionName: " << collectionName << endl;
}

Prog3::Model::Board BoardRepository::getBoard()
{
    bsoncxx::stdx::optional<bsoncxx::document::value> wasBoardFound = boardCollection.find_one({document{} << "title" << boardTitle << finalize});
    if (! wasBoardFound)
    {
        throw std::runtime_error("no baord in database");
    }

    bsoncxx::document::view bsonBoard = wasBoardFound->view();
    // std::cout << bsoncxx::to_json(bsonBoard) << "\n";

    string boardTitle = getString(bsonBoard["title"]);
    Model::Board board(boardTitle);

    if (isArray(bsonBoard["columns"]))
    {
        for (const bsoncxx::array::element & bsonColumn : bsonBoard["columns"].get_array().value )
        {

            Model::Column column = {0};
            column.id = getDouble(bsonColumn["id"]);
            column.name = getString(bsonColumn["name"]);
            column.position = getDouble(bsonColumn["position"]);

            if (isArray(bsonColumn["items"]))
            {
                vector<string> items;
                for (const bsoncxx::array::element & bsonItems : bsonColumn["items"].get_array().value)
                {
                    items.push_back(getString(bsonItems));
                }

                column.items = items;
            }

            board.addColumn(column);
        }
    }
    return board;
}

void BoardRepository::upsertBoard(std::string title)
{
    boardTitle = title;
    mongocxx::options::update upsertOption;
    upsertOption.upsert(true);

    boardCollection.update_one(
        document{} << "title" << title << finalize,
        document{} << "$set" << open_document << "title" << title << close_document << finalize,
        upsertOption);
}
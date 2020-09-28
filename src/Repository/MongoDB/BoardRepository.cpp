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
const std::string BoardRepository::boardName = "Jira Board";

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
    bsoncxx::stdx::optional<bsoncxx::document::value> wasBoardFound = boardCollection.find_one({document{} << "title" << boardName << finalize});
    if(wasBoardFound) 
    {
        bsoncxx::document::view bsonBoard = wasBoardFound->view();
        // std::cout << bsoncxx::to_json(bsonBoard) << "\n";

        string boardTitle = toString(bsonBoard["title"]);
        Model::Board board(boardTitle);

        if (bsonBoard["columns"].type() == bsoncxx::type::k_array)
        {
            vector<Model::Column> columns;
            for (const bsoncxx::array::element & bsonColumn : bsonBoard["columns"].get_array().value )
            {
                if (bsonColumn["items"].type() == bsoncxx::type::k_array)
                {
                    vector<string> items;
                    for (const bsoncxx::array::element & item : bsonColumn["items"].get_array().value)
                    {
                        // std::cout << item.get_utf8().value.to_string() << std::endl;
                        items.push_back(toString(item));
                    }
                }
                Model::Column column = {0};
                if (bsonColumn["id"].type() == bsoncxx::type::k_double)
                {
                    column.id = bsonColumn["id"].get_double().value;
                    cout << "column id is: " << column.id << endl;
                }
            }

        }

        
        // std::cout << bsoncxx::to_json(bsonBoard["title"].get_value()) << std::endl;
        // std::cout << bsonBoard["title"].get_utf8().value.to_string() << std::endl;


    }

    Model::Board board("implementing ...");

    return board;
}
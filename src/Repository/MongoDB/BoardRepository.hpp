#pragma once

#include "Repository/RepositoryIf.hpp"

#include <mongocxx/client.hpp>

namespace Prog3 { namespace Repository { namespace MongoDB {
class BoardRepository : public Prog3::Repository::RepositoryIf
{
private:
    mongocxx::client mongoClient;
    mongocxx::collection boardCollection;

    std::string toString(bsoncxx::document::element element)
    {
        return element.get_utf8().value.to_string();
    }
    std::string toString(bsoncxx::array::element element)
    {
        return element.get_utf8().value.to_string();
    }

public:
    BoardRepository(std::string connectionString);
    ~BoardRepository() {};

    virtual Prog3::Model::Board getBoard();

    static const std::string databaseName;
    static const std::string collectionName;
    static const std::string boardName;

};

}}}

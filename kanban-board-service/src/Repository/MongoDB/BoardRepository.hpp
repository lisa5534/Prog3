#pragma once

#include "Repository/RepositoryIf.hpp"

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

namespace Prog3 {
namespace Repository {
namespace MongoDB {
class BoardRepository : public Prog3::Repository::RepositoryIf {
  private:
    mongocxx::instance mongoDriverInstance;
    mongocxx::client mongoClient;
    mongocxx::collection boardCollection;
    std::string boardTitle = "";

    std::string getString(const bsoncxx::document::element &element) {
        if (element.type() == bsoncxx::type::k_utf8) {
            return element.get_utf8().value.to_string();
        } else {
            return "";
        }
    }
    std::string getString(const bsoncxx::array::element &element) {
        if (element.type() == bsoncxx::type::k_utf8) {
            return element.get_utf8().value.to_string();
        } else {
            return "";
        }
    }

    double getDouble(const bsoncxx::document::element &element) {
        if (element.type() == bsoncxx::type::k_double) {
            return element.get_double().value;
        } else {
            return 0.0;
        }
    }

    bool isArray(const bsoncxx::document::element &element) {
        bool isArray = false;
        if (element) {
            isArray = element.type() == bsoncxx::type::k_array;
        }
        return isArray;
    }

  public:
    BoardRepository(std::string connectionString);
    ~BoardRepository(){};

    virtual Prog3::Model::Board getBoard();
    virtual void upsertBoard(std::string title);

    static const std::string databaseName;
    static const std::string collectionName;
};

} // namespace MongoDB
} // namespace Repository
} // namespace Prog3

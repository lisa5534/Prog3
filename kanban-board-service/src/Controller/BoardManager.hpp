#pragma once

#include "Repository/RepositoryIf.hpp"
#include "rapidjson/document.h"
#include <list>

namespace Prog3 {
namespace Controller {
class BoardManager {
  private:
    Prog3::Repository::RepositoryIf &repository;

    rapidjson::Value getJson(std::vector<std::string> givenItems, rapidjson::Document::AllocatorType &allocator);
    rapidjson::Value getJson(std::vector<Prog3::Model::Column> givenColumns, rapidjson::Document::AllocatorType &allocator);

  public:
    BoardManager(Prog3::Repository::RepositoryIf &givenRepository);
    ~BoardManager();

    std::string getBoard();
};
} // namespace Controller
} // namespace Prog3
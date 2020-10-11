#include <iostream>
#include <string>

#include "crow.h"
#include "Api/Endpoint.hpp"
#include "Controller/BoardManager.hpp"
#include "Repository/DatabaseMock/BoardRepository.hpp"
#include "Repository/MongoDB/BoardRepository.hpp"

const bool useDatabaseMock = false;
const std::string databaseConnectionString = "mongodb://localhost:27017";
const std::string boardTitle = "Kanban Board";

int main()
{
  crow::SimpleApp crowApplication;
  Prog3::Repository::RepositoryIf *repository = nullptr;

  if (useDatabaseMock)
  {
    repository = new Prog3::Repository::DatabaseMock::BoardRepository();
  }
  else
  {
    repository = new Prog3::Repository::MongoDB::BoardRepository(databaseConnectionString);
  }
  repository->upsertBoard(boardTitle);

  Prog3::Controller::BoardManager boardManager(*repository);
  Prog3::Api::Endpoint endpoint(crowApplication, boardManager);

  crowApplication.port(8080)
      //        .multithreaded()
      .run();
}

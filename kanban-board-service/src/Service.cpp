#include <iostream>
#include <string>

#include "Api/Endpoint.hpp"
#include "Controller/BoardManager.hpp"
#include "Repository/DatabaseMock/BoardRepository.hpp"
#include "Repository/SQLite/BoardRepository.hpp"
#include "crow.h"

const bool useDatabaseMock = false;

int main() {
    crow::SimpleApp crowApplication;
    Prog3::Repository::RepositoryIf *repository = nullptr;

    if (useDatabaseMock) {
        repository = new Prog3::Repository::DatabaseMock::BoardRepository();
    } else {
        repository = new Prog3::Repository::SQLite::BoardRepository();
    }
    repository->initialize();

    Prog3::Controller::BoardManager boardManager(*repository);
    Prog3::Api::Endpoint endpoint(crowApplication, boardManager);

    crowApplication.port(8080)
        //        .multithreaded()
        .run();
}

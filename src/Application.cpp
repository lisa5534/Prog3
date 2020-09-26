#include <iostream>
#include <vector>
#include <string>

#include "crow.h"
#include "Controller/Endpoint.hpp"
#include "BusinessLogic/BoardManager.hpp"
#include "Repository/FakeDatabase/BoardDataAccess.hpp"

using namespace std;

int main()
{
    crow::SimpleApp crowApplication;


    Prog3::Repository::RepositoryIf * repository = new Prog3::Repository::FakeDatabase::BoardDataAccess();
    Prog3::BusinessLogic::BoardManager boardManager(*repository);
    Prog3::Controller::Endpoint endpoint(crowApplication, boardManager);


    crowApplication.port(18080)
//        .multithreaded()
        .run();
}
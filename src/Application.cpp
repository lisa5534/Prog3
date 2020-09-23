#include <iostream>
#include <vector>
#include <string>

#include "crow.h"
#include "Controller/Endpoint.hpp"
#include "BusinessLogic/BoardManager.hpp"
#include "Repository/BoardDataAccess.hpp"

using namespace std;

int main()
{
    crow::SimpleApp crowApplication;


    Prog3::Repository::DataAccessIf * dataAccess = new Prog3::Repository::BoardDataAccess();
    Prog3::BusinessLogic::BoardManager boardManager(*dataAccess);
    Prog3::Controller::Endpoint endpoint(crowApplication, boardManager);


    crowApplication.port(18080)
//        .multithreaded()
        .run();
}
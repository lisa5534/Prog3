#pragma once

#include "crow.h"
#include "Controller/BoardManager.hpp"

namespace Prog3 { namespace Api {

class Endpoint
{
public:
    Endpoint(crow::SimpleApp& givenApp, Prog3::Controller::BoardManager& givenBoardManager);
    ~Endpoint();

    void registerRoutes();

private:
    crow::SimpleApp & app;
    Prog3::Controller::BoardManager & boardManager;

};


}}

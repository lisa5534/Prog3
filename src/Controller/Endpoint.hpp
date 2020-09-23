#pragma once

#include "crow.h"
#include "BusinessLogic/BoardManager.hpp"

namespace Prog3 { namespace Controller {

class Endpoint
{
public:
    Endpoint(crow::SimpleApp& givenApp, Prog3::BusinessLogic::BoardManager& givenBoardManager);
    Endpoint(Endpoint &&) = default;
    Endpoint(const Endpoint &) = default;
    Endpoint &operator=(Endpoint &&) = default;
    Endpoint &operator=(const Endpoint &) = default;
    ~Endpoint();

    void registerRoutes();

private:
    crow::SimpleApp & app;
    Prog3::BusinessLogic::BoardManager & boardManager;

};


}}

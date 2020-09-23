#pragma once

#include "crow.h"

namespace Prog3 { namespace Controller {

class Endpoint
{
public:
    Endpoint(crow::SimpleApp& givenApp);
    Endpoint(Endpoint &&) = default;
    Endpoint(const Endpoint &) = default;
    Endpoint &operator=(Endpoint &&) = default;
    Endpoint &operator=(const Endpoint &) = default;
    ~Endpoint();

    void registerRoutes();

private:
    crow::SimpleApp & app;

};


}}

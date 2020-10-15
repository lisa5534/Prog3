#pragma once

#include "Controller/BoardManager.hpp"
#include "crow.h"

namespace Prog3 {
namespace Api {

class Endpoint {
  public:
    Endpoint(crow::SimpleApp &givenApp, Prog3::Controller::BoardManager &givenBoardManager);
    ~Endpoint();

    void registerRoutes();

  private:
    crow::SimpleApp &app;
    Prog3::Controller::BoardManager &boardManager;
};

} // namespace Api
} // namespace Prog3

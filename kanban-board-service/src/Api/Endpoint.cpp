#include "Endpoint.hpp"
#include <iostream>

using namespace Prog3::Api;
using namespace Prog3::Controller;
using namespace crow;
using namespace std;

Endpoint::Endpoint(SimpleApp &givenApp, BoardManager &givenBoardManager) : app(givenApp),
                                                                           boardManager(givenBoardManager) {
    registerRoutes();
}

Endpoint::~Endpoint() {
}

void Endpoint::registerRoutes() {

    CROW_ROUTE(app, "/api/board")
    ([this](const request &req, response &res) {
        std::string boardAsJson = boardManager.getBoard();
        res.write(boardAsJson);
        res.end();
    });

    CROW_ROUTE(app, "/api/board/columns/<int>")
        .methods("GET"_method, "POST"_method, "PUT"_method, "DELETE"_method)([](const request &req, response &res, int id) {
            cout << "/api/board/columns/" << id << endl;
            cout << "Method: " << method_name(req.method) << endl;

            res.end();
        });
}
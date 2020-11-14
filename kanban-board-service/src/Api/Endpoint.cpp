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
        .methods("GET"_method, "POST"_method, "PUT"_method, "DELETE"_method)([this](const request &req, response &res, int id) {
            switch (req.method) {
            case HTTPMethod::Get:
                cout << "case HTTPMethod::Get" << endl;
                break;
            case HTTPMethod::Post:
                cout << "case HTTPMethod::Post" << endl;
                break;
            case HTTPMethod::Put:
                cout << "case HTTPMethod::Put" << endl;
                break;
            case HTTPMethod::Delete:
                cout << "case HTTPMethod::Delete" << endl;
                break;
            }

            cout << "Method: " << method_name(req.method) << endl;
            cout << "/api/board/columns/" << id << endl;

            res.end();
        });

    CROW_ROUTE(app, "/api/board/badrequest")
        .methods("GET"_method)([this](const request &req, response &res) {
            int const badRequest = 400;
            res.code = badRequest;
            res.end();
        });
}

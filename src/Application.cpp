#include <iostream>
#include <vector>
#include <string>

#include "crow.h"
#include "Controller/Endpoint.hpp"

using namespace std;

int main()
{
    crow::SimpleApp crowApplication;

    Prog3::Controller::Endpoint controller(crowApplication);


    crowApplication.port(18080)
//        .multithreaded()
        .run();
}
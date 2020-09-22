#include <iostream>
#include <vector>
#include <string>

#include "crow.h"

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    // msg
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    cout << "my c++ version is: " << __cplusplus << endl;

    crow::SimpleApp app;

    CROW_ROUTE(app, "/json")
    ([]{
        crow::json::wvalue x;
        x["message"] = "Hello, World!";
        return x;
    });

    app.port(18080).multithreaded().run();

}
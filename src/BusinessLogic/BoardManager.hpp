#pragma once

#include "Repository/DataAccessIf.hpp"

namespace Prog3 { namespace BusinessLogic {
class BoardManager
{
private:
    Prog3::Repository::DataAccessIf & dataAccess;

public:
    BoardManager(Prog3::Repository::DataAccessIf & givenDataAccess);
    ~BoardManager();

    std::string getBoard();
};
}}
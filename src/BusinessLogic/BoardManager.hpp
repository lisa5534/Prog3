#pragma once

#include "Repository/Repository.hpp"

namespace Prog3 { namespace BusinessLogic {
class BoardManager
{
private:
    Prog3::Repository::RepositoryIf & repository;

public:
    BoardManager(Prog3::Repository::RepositoryIf & givenRepository);
    ~BoardManager();

    std::string getBoard();
};
}}
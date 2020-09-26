#pragma once

#include "Repository/Repository.hpp"

namespace Prog3 { namespace Repository { namespace FakeDatabase {
class BoardDataAccess : public Prog3::Repository::RepositoryIf
{
private:

public:
    BoardDataAccess() {};
    ~BoardDataAccess() {};

    virtual Prog3::Model::Board getBoard();

};

}}}

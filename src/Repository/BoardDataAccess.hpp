#pragma once

#include "DataAccessIf.hpp"

namespace Prog3 { namespace Repository {
class BoardDataAccess : public Prog3::Repository::DataAccessIf
{
private:

public:
    BoardDataAccess() {};
    ~BoardDataAccess() {};

    virtual Prog3::Repository::Model::Board getBoard();

};

}}

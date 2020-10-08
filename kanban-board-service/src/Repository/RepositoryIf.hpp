#pragma once

#include "Model/Board.hpp"

namespace Prog3 { namespace Repository {
class RepositoryIf
{
public:
    ~RepositoryIf() {}

    virtual Prog3::Model::Board getBoard()          =   0;
    virtual void upsertBoard(std::string title)     =   0;

};

}}
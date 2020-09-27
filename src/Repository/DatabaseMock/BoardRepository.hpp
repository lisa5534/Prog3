#pragma once

#include "Repository/RepositoryIf.hpp"

namespace Prog3 { namespace Repository { namespace DatabaseMock {
class BoardRepository : public Prog3::Repository::RepositoryIf
{
private:

public:
    BoardRepository() {};
    ~BoardRepository() {};

    virtual Prog3::Model::Board getBoard();

};

}}}

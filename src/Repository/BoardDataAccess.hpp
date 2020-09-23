#include "DataAccessIf.hpp"

class BoardDataAccess : public Prog3::Repository::DataAccessIf
{
private:

public:
    BoardDataAccess();
    ~BoardDataAccess() {}

    virtual Prog3::Repository::Model::Board getBoard();

};



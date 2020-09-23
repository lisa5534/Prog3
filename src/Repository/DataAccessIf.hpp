
#include "Model/Board.hpp"

namespace Prog3 { namespace Repository {
class DataAccessIf
{
public:
    ~DataAccessIf() {}

    virtual Prog3::Repository::Model::Board getBoard() = 0;

};

}}
#include "BoardManager.hpp"

using namespace Prog3::BusinessLogic;
using namespace Prog3::Repository;

BoardManager::BoardManager(DataAccessIf & givenDataAccess):
    dataAccess(givenDataAccess)
{
}

BoardManager::~BoardManager()
{
}

std::string BoardManager::getBoard()
{
    Model::Board board = dataAccess.getBoard();
    return "\"board\": \"name\"";
}
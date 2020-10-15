#pragma once

#include "Repository/RepositoryIf.hpp"

namespace Prog3 {
namespace Repository {
namespace DatabaseMock {
class BoardRepository : public Prog3::Repository::RepositoryIf {
  private:
    Prog3::Model::Board *board = nullptr;

  public:
    BoardRepository(){};
    ~BoardRepository(){};

    virtual Prog3::Model::Board getBoard();
    virtual void initialize();
};

} // namespace DatabaseMock
} // namespace Repository
} // namespace Prog3

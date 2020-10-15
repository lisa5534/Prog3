#pragma once

#include "Model/Board.hpp"

namespace Prog3 {
namespace Repository {
class RepositoryIf {
  public:
    virtual ~RepositoryIf() {}

    virtual Prog3::Model::Board getBoard() = 0;
    virtual void initialize() = 0;
};

} // namespace Repository
} // namespace Prog3

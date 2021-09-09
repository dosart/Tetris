#ifndef TETRIS_INCLUDE_POSITION_T_H_
#define TETRIS_INCLUDE_POSITION_T_H_

#include <vector>

#include "point_t.h"

class position_t
{
 public:
  position_t();

  const std::vector<point_t>& get_positions();
 private:
  std::vector<point_t> m_pints;
};

#endif //TETRIS_INCLUDE_POSITION_T_H_

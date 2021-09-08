

#ifndef TETRIS_INCLUDE_TETRAMINO_H_
#define TETRIS_INCLUDE_TETRAMINO_H_

#include  <random>
#include  <iterator>
#include "array"

namespace game {

enum class tetromino_t { I = 0, Z, S, T, L, J, O };

tetromino_t make_tetramino() {
  return tetromino_t(rand()%7);
}

unsigned int to_int(tetromino_t tetramino) {
  switch (tetramino) {
    case tetromino_t::I: return 0;
    case tetromino_t::Z: return 1;
    case tetromino_t::S: return 2;
    case tetromino_t::T: return 3;
    case tetromino_t::L: return 4;
    case tetromino_t::O: return 5;
    case tetromino_t::J: return 6;
    default: return 0;
  }
}

#endif //TETRIS_INCLUDE_TETRAMINO_H_
}
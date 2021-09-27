#include "tetris.h"

namespace game {

tetris_t::tetris_t(sf::Texture *texture) : m_texture{texture},
                                           m_sprite(*m_texture),
                                           m_tetramino{make_tetromino(&m_sprite)} {
  m_sprite.setTextureRect(sf::IntRect(0, 0, 18, 18));
}

tetromino_t &tetris_t::current_tetramino() {
  return m_tetramino;
}

void tetris_t::move_tetramino(game::Direction direction) {
  switch (direction) {
    case Direction::LEFT:m_tetramino.move_x(-1);
      break;
    case Direction::RIGHT:m_tetramino.move_x(1);
      break;
    case Direction::DOWN:m_tetramino.move_x(5);
      break;
    case Direction::UP:m_tetramino.rotate();
      break;
  }
}
}

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

void tetris_t::move_tetramino(const sf::Event::KeyEvent &event) {
  switch (event.code) {
    case sf::Keyboard::Left:m_tetramino.move_x(-1);
      break;
    case sf::Keyboard::Right:m_tetramino.move_x(1);
      break;
    case sf::Keyboard::Down:m_tetramino.move_y(1);
      break;
    case sf::Keyboard::Up:m_tetramino.rotate();
      break;
    default:break;
  }
}

void tetris_t::move_down() {
  m_tetramino.move_y(1);
}
}

#ifndef TETRIS_INCLUDE_GAME_H_
#define TETRIS_INCLUDE_GAME_H_

#include <SFML/Window.hpp>
#include "tetromino.h"

namespace game {

class tetris_t {
 public:
  tetris_t(sf::Texture* texture);
  ~tetris_t() = default;

  tetromino_t& current_tetramino();

  void move_tetramino(const sf::Event::KeyEvent& event);

 private:
  sf::Texture* m_texture;
  sf::Sprite m_sprite;
  tetromino_t m_tetramino;
};
}

#endif


#ifndef TETRIS_INCLUDE_TETRAMINO_H_
#define TETRIS_INCLUDE_TETRAMINO_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "point.h"

namespace game {

class tetromino_t final {
 public:
  tetromino_t(std::vector<sf::Vector2f> const *positions, sf::Sprite const *sprite) : m_positions{positions},
                                                                                      m_sprite{sprite} {};
  ~tetromino_t() = default;

  std::vector<sf::Vector2f> const *get_position() const { return m_positions; };
  sf::Sprite const *get_sprite() const { return m_sprite; };

 private:
  std::vector<sf::Vector2f> const *m_positions;
  sf::Sprite const *m_sprite;
};

tetromino_t make_tetromino();
}
#endif //TETRIS_INCLUDE_TETRAMINO_H_

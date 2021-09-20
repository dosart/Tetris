#ifndef TETRIS_INCLUDE_TETRAMINO_H_
#define TETRIS_INCLUDE_TETRAMINO_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "tetromino.h"

namespace game {

class tetromino_t final {
 public:
  tetromino_t(std::vector<sf::Vector2f> const *positions, sf::Sprite *sprite) : m_positions{positions},
                                                                                m_sprite{sprite} {};
  ~tetromino_t() = default;

  std::vector<sf::Vector2f> const *get_position() const { return m_positions; };
  sf::Sprite const *get_sprite() const { return m_sprite; };

  void draw(sf::RenderTarget &target, sf::RenderStates states);

 private:
  std::vector<sf::Vector2f> const *m_positions;
  sf::Sprite *m_sprite;
};

tetromino_t make_tetromino(sf::Sprite *sprite);
}
#endif //TETRIS_INCLUDE_TETRAMINO_H_

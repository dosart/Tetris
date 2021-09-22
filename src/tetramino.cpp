#include "tetromino.h"

namespace game {

// global array coordinates of tetromino
static const std::vector<std::vector<sf::Vector2f>> tetrominos =
    {
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}}, // I
        {{0, 1}, {0, 2}, {1, 2}, {1, 3}}, // Z
        {{1, 1}, {1, 2}, {0, 2}, {0, 3}}, // S
        {{1, 1}, {1, 2}, {0, 2}, {1, 3}}, // T
        {{0, 1}, {1, 1}, {1, 2}, {1, 3}}, // L
        {{1, 1}, {1, 2}, {1, 3}, {0, 3}}, // J
        {{0, 1}, {1, 1}, {0, 2}, {1, 2}}, // o
    };

tetromino_t make_tetromino(sf::Sprite *sprite) {
  return tetromino_t(&tetrominos[5], sprite);
}

void tetromino_t::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (const auto &position: *m_positions) {
    m_sprite->setPosition(position.x*18, position.y*18);
    target.draw(*m_sprite, states);
  }
}

}
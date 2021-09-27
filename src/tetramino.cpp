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

tetromino_t::tetromino_t(const std::vector<sf::Vector2f> *positions, sf::Sprite *sprite) : m_sprite{sprite} {
  std::copy(std::cbegin(*positions), std::cend(*positions), std::back_inserter(m_positions));
}

void tetromino_t::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (const auto &position: m_positions) {
    m_sprite->setPosition(position.x*18, position.y*18);
    target.draw(*m_sprite, states);
  }
}

void tetromino_t::move_y(float dy) {
  std::for_each(std::begin(m_positions), std::end(m_positions), [&dy](sf::Vector2f &position) { position.y += dy; });
}

void tetromino_t::move_x(float dx) {
  std::for_each(std::begin(m_positions), std::end(m_positions), [&dx](sf::Vector2f &position) { position.x += dx; });
}

void tetromino_t::rotate() {
  auto center_of_rotation = m_positions[1];
  for (auto &position: m_positions) {
    auto x = position.y - center_of_rotation.y;
    auto y = position.x - center_of_rotation.x;

    position.x = center_of_rotation.x - x;
    position.y = center_of_rotation.y - y;
  }
}

}
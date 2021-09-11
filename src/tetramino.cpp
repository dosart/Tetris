#include "tetromino.h"

#include <array>

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

tetromino_t make_tetromino() {
  return tetromino_t(&tetrominos[0], nullptr);
}
}
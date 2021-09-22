#include <tetromino.h>
#include "render.h"

namespace game {
render_t::render_t(tetris_t *tetris, sf::Font *font)
    : m_tetris{tetris}, m_font{font} {
  _init();
}

void render_t::_init() {
  m_window.create(sf::VideoMode(320, 480), "The Tetris clone!");
  m_window.setFramerateLimit(60);
  m_text = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Shapes", *m_font, 14);
  m_text.setFillColor(sf::Color::Black);
  m_text.setPosition(5.f, 5.f);
}

sf::RenderWindow &render_t::window() {
  return m_window;
}

void render_t::render() {
  m_window.clear(sf::Color::White);
  m_window.draw(m_text);
  m_window.draw(*this);
  m_window.display();
}

void render_t::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  auto tetramino = m_tetris->current_tetramino();
  target.draw(tetramino, states);

  target.draw(tetramino, states);

}
}
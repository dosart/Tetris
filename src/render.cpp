#include "render.h"

namespace game {
render_t::render_t(sf::Font font)
    : m_font{font} {
  _init();
}

void render_t::_init() {
  m_window.create(sf::VideoMode(320, 480), "The Tetris clone!");
  m_window.setFramerateLimit(60);
  m_text = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Shapes", m_font, 14);
  m_text.setFillColor(sf::Color::Cyan);
  m_text.setPosition(5.f, 5.f);
}

sf::RenderWindow &render_t::window() {
  return m_window;
}

void render_t::render() {
  m_window.clear();
  m_window.draw(m_text);
  m_window.display();
}
}

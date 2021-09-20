#include <tetromino.h>
#include "render.h"

namespace game {
render_t::render_t(sf::Font* font, sf::Texture* texture)
    : m_font{font}, m_texture{texture} {
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
  sf::Sprite sprite(*m_texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 18, 18));

  auto tetramino = make_tetromino(&sprite);
  tetramino.draw(target, states);
  
}
}
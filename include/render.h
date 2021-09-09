#ifndef TETRIS_INCLUDE_RENDER_H_
#define TETRIS_INCLUDE_RENDER_H_

#include <SFML/Graphics.hpp>

class render_t
{
 public:
  render_t(sf::Font m_font);

 private:
  void _init();

  sf::RenderWindow m_window;

  sf::Font m_font;
  sf::Text m_text;
};

#endif //TETRIS_INCLUDE_RENDER_H_

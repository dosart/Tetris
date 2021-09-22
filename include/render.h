#ifndef TETRIS_INCLUDE_RENDER_H_
#define TETRIS_INCLUDE_RENDER_H_

#include <SFML/Graphics.hpp>
#include "tetris.h"

namespace game {

class render_t : public sf::Drawable, public sf::Transformable {
 public:
  render_t(tetris_t *tetris, sf::Font *font);

  sf::RenderWindow &window();
  void render();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

 private:
  void _init();

  sf::RenderWindow m_window;

  tetris_t *m_tetris;
  sf::Font *m_font;
  sf::Text m_text;
};
}

#endif //TETRIS_INCLUDE_RENDER_H_

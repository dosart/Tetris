#ifndef TETRIS_INCLUDE_RENDER_H_
#define TETRIS_INCLUDE_RENDER_H_

#include <SFML/Graphics.hpp>

namespace game {

class render_t : public sf::Drawable, public sf::Transformable {
 public:
  render_t(sf::Font* font, sf::Texture* texture);

  sf::RenderWindow &window();
  void render();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

 private:
  void _init();

  sf::RenderWindow m_window;

  sf::Font* m_font;
  sf::Text m_text;
  sf::Texture* m_texture;
};
}

#endif //TETRIS_INCLUDE_RENDER_H_

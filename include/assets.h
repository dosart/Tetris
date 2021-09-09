#ifndef TETRIS_INCLUDE_ASSETS_H_
#define TETRIS_INCLUDE_ASSETS_H_

#include <string>
#include <optional>

namespace game{
/**
 * @brief Load font from resources
 *
 * @param fontName Name of font for load
 *
 * @return SFML format font
 */
inline std::optional<sf::Font> load_font(std::string fontName) {
  sf::Font font;
  if (!font.loadFromFile(fontName))
    return {};
  return font;
}
}

#endif //TETRIS_INCLUDE_ASSETS_H_

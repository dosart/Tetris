#ifndef TETRIS_INCLUDE_ASSETS_H_
#define TETRIS_INCLUDE_ASSETS_H_

#include <string>
#include <optional>

namespace game {
/**
 * @brief Load font from resources
 *
 * @param fontName Name of font for load
 *
 * @return SFML format font
 */
inline std::optional<sf::Font> load_font(std::string file_path) {
  sf::Font font;
  if (!font.loadFromFile(file_path))
    return {};
  return font;
}

inline std::optional<sf::Texture> load_texture(std::string file_path) {
  sf::Texture texture;
  if (!texture.loadFromFile(file_path))
    return {};
  return texture;
}
}

#endif //TETRIS_INCLUDE_ASSETS_H_

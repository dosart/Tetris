#include "render.h"
#include "controller.h"
#include "AssetsLoader.hpp"

int main() {

  ::Loader::AssetsLoader<sf::Texture> texture_loader;
  texture_loader.setSupportedFormats("png", "[]");
  texture_loader.loadAssets("../resources", [](auto &item, auto path) { item.loadFromFile(path.string()); });

  ::Loader::AssetsLoader<sf::Font> font_loader;
  font_loader.setSupportedFormats("ttf", "[]");
  font_loader.loadAssets("../resources", [](auto &item, auto path) { item.loadFromFile(path.string()); });

  ::game::tetris_t tetris(texture_loader.getPtr("tiles"));
  ::game::render_t render(&tetris, font_loader.getPtr("calibri"));

  ::game::controller controller(&render, &tetris);
  controller.run();

  return 0;
}


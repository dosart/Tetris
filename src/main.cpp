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

  game::render_t render(font_loader.getPtr("calibri"), texture_loader.getPtr("tiles"));
  game::controller controller(&render);
  controller.run();

  return 0;
}


#include "render.h"
#include "controller.h"
#include "assets.h"

int main() {

  if (auto font = game::load_font("../resources/calibri.ttf"); font.has_value()) {

    if (auto texture = game::load_texture("../resources/tiles.png"); texture.has_value()) {
      game::render_t render(std::move(font.value()), std::move(texture.value()));
      game::controller controller(&render);

      controller.run();
    }
  }

  return 0;
}


#include "render.h"
#include "controller.h"
#include "assets.h"

int main() {

  auto font = game::load_font("../resources/calibri.ttf");
  if (!font.has_value())
    return -1;

  auto texture = game::load_texture("../resources/tiles.png");
  if (!texture.has_value())
    return -1;

  game::render_t render(std::move(font.value()), std::move(texture.value()));
  game::controller controller(&render);
  controller.run();

  return 0;
}


#ifndef TETRIS_INCLUDE_CONTROLLER_H_
#define TETRIS_INCLUDE_CONTROLLER_H_

#include "render.h"

namespace game {

class controller final {

 public:
  explicit controller(render_t *render);
  ~controller() = default;

  void run();

 private:
  void handle_events(sf::RenderWindow &window);

  render_t *m_render;
};

}

#endif //TETRIS_INCLUDE_CONTROLLER_H_

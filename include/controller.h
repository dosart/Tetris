#ifndef TETRIS_INCLUDE_CONTROLLER_H_
#define TETRIS_INCLUDE_CONTROLLER_H_

#include "render.h"
#include "tetris.h"

namespace game {

class controller final {

 public:
  explicit controller(render_t *render, tetris_t *tetris);
  ~controller() = default;

  void run();

 private:
  void handle_events(sf::RenderWindow &window);

  render_t *m_render;
  tetris_t *m_tetris;
};

}

#endif //TETRIS_INCLUDE_CONTROLLER_H_

#include "controller.h"

namespace game {

controller::controller(render_t *render, tetris_t *tetris)
    : m_render{render}, m_tetris{tetris} {

}

void controller::run() {
  while (m_render->window().isOpen()) {
    handle_events(m_render->window());
    m_render->render();
  }
}

void controller::handle_events(sf::RenderWindow &window) {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type==sf::Event::Closed) {
      window.close();
    }
  }
}
}


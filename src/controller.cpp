#include "controller.h"

namespace game {

controller::controller(render_t *render, tetris_t *tetris)
    : m_render{render}, m_tetris{tetris}, m_clock(), timer{0} {

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
    if (event.type==sf::Event::KeyPressed) {
      m_tetris->move_tetramino(event.key);
    }

    float time = m_clock.getElapsedTime().asSeconds();
    m_clock.restart();
    timer += time;

    if (timer > 0.3f) {
      m_tetris->move_down();
      timer = 0;
    }
  }
}

}
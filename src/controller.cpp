#include "controller.h"

namespace game {

controller::controller(render_t *render, tetris_t *tetris)
    : m_render{render}, m_tetris{tetris}, m_timer(), m_time_per_frame{0.3f} {

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

//    auto time_since_last_update = m_timer.getElapsedTime().asSeconds();
//    m_timer.restart();

    if (event.type==sf::Event::Closed) {
      window.close();
    }
    if (event.type==sf::Event::KeyPressed) {
      m_tetris->move_tetramino(event.key);
    }
  }
}

}
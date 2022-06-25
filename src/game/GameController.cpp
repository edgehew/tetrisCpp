#include "inc/GameController.hpp"

#include <iostream>

namespace game {

GameController::GameController(GameWindow &window)
    : window_(window) 
{
}

void GameController::handleEvents() {

    auto &window = window_.getRenderWindow();
    /* Keep Program Running as long as window is open */ 
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed) {
            window_.close();
        }

        if (e.type == Event::KeyPressed) {
            auto key = e.key.code;
            switch (key) {
                case Keyboard::Escape :
                    pauseGame();
                    std::cout << "Escape captured\n";
                    break;
                case Keyboard::Up :
                case Keyboard::Left :
                case Keyboard::Right : 
                case Keyboard::Down : 
                default:
                    break;
            }
        }
    }
}

void GameController::pauseGame() {
    window_.pauseGame();
    auto &window = window_.getRenderWindow();
    Event e;
    while (window_.isPaused()) {
        window.pollEvent(e);
        window_.renderPauseMenu();
        if (e.type == Event::Closed) {
            window_.close();
            return;
        }

        if (e.type == Event::KeyPressed) {
            auto key = e.key.code;
            switch (key) {
                case Keyboard::Q :
                    window_.close();
                    break;
                case Keyboard::C :
                    window_.resumeGame();
                    break;
                case Keyboard::R :
                    window_.resetGame();
                    break;
                default:
                    break;
            }
        }
    }
}


void GameController::runGame() {
    while(window_.isOpen()) {

        handleEvents();

        window_.renderGame();
    }
}

} // namespace game
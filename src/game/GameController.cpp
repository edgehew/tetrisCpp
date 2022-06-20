#include "inc/GameController.hpp"

namespace game {

GameController::GameController(GameWindow &window)
    : window_(window) 
    , isRunning_(false)
    , isQuitting_(false)
    
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
    while (window.pollEvent(e) && window_.isPaused()) {
        window_.renderPauseMenu();
        if (e.type == Event::Closed) {
            window_.close();
            return;
        }

        if (e.type == Event::KeyPressed) {
            auto key = e.key.code;
            switch (key) {
                case Keyboard::Q :
                    window_.quitGame();
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
    isRunning_ = true;
    while(isRunning_ && !isQuitting_) {

        handleEvents();
        window_.renderGame();
    }
}

} // namespace game
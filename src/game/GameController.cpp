#include "inc/GameController.hpp"

#include <iostream>

namespace game {

GameController::GameController(GameWindow &window)
    : window_(window) 
    , gameState_(GameState::INITIALIZING)
{
}

void GameController::runGame() {
    gameState_ = GameState::RUNNING;
    while(!isExiting()) {

        handleEvents();

        window_.renderGame();
    }

    window_.close();
}

void GameController::handleEvents() {

    auto &window = window_.getRenderWindow();
    /* Keep Program Running as long as window is open */ 
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed) {
            exitGame();
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
    gameState_ = GameState::PAUSED;
    auto &window = window_.getRenderWindow();
    Event e;
    while (gameState_ == GameState::PAUSED) {
        window.pollEvent(e);
        window_.renderPauseMenu();
        if (e.type == Event::Closed) {
            exitGame();
            return;
        }

        if (e.type == Event::KeyPressed) {
            auto key = e.key.code;
            switch (key) {
                case Keyboard::Q :
                    exitGame();
                    return;
                case Keyboard::C :
                    resumeGame();
                    break;
                case Keyboard::R :
                    resetGame();
                    break;
                default:
                    break;
            }
        }
    }
}

void GameController::resumeGame() {
    gameState_ = GameState::RUNNING;
}

void GameController::resetGame() {
    gameState_ = GameState::INITIALIZING;
}

void GameController::exitGame() {
    gameState_ = GameState::EXITING;
}

} // namespace game

#pragma once

#include "GameWindow.hpp"

#include <atomic>
#include <thread>
#include <SFML/Graphics.hpp>
#include <string>

namespace game {

enum class GameState : uint8_t {
    INITIALIZING = 0,
    RUNNING = 1,
    PAUSED = 2,
    GAME_OVER = 3,
    EXITING = 4,
};

class GameController {

private:
    GameWindow &window_;

    std::atomic<GameState> gameState_;

public:
    GameController(GameWindow &window);
    void runGame();

private:
    void handleEvents();
    void pauseGame();
    void resetGame();
    void resumeGame();
    void exitGame();
    bool isExiting() { return gameState_ == GameState::EXITING; }
};

} // namespace game

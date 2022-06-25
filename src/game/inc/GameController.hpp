#pragma once

#include "GameWindow.hpp"

#include <atomic>
#include <thread>
#include <SFML/Graphics.hpp>
#include <string>

namespace game {

class GameController {

private:
    GameWindow &window_;

public:
    GameController(GameWindow &window);
    void handleEvents();
    void pauseGame();
    void runGame();
};

} // namespace game
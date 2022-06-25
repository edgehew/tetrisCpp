#pragma once

#include <atomic>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

namespace game {

class GameWindow {
private:
    const std::string TETRIS_TITLE = "Tetris!";
    const std::string TILES_IMG = "tiles.png";
    const std::string BACKGROUND_IMG = "background.png";
    const std::string FRAME_IMG = "frame.png";

    uint width_;
    uint height_;
    RenderWindow window_;
    const std::string& fontPath_;
    const std::string& imgPath_;

    Font font_;
    Text endMessage_;
    Text restartMessage_;
    Text pauseMessage_;

    Texture tilesTexture_;
    Texture pauseTexture_;
    Texture backgroundTexture_;
    Texture frameTexture_;

    Sprite tilesSprite_;
    Sprite pauseSprite_;
    Sprite backgroundSprite_;
    Sprite frameSprite_;

public:
    GameWindow(
        const uint width, 
        const uint height, 
        const std::string& fontPath,
        const std::string& imgPath);

    void renderGame();
    void renderPauseMenu();
    void renderEndGame();
    bool isOpen() { return window_.isOpen(); }
    RenderWindow& getRenderWindow() { return window_; }
    void close() { return window_.close(); }
};

} // namespace game
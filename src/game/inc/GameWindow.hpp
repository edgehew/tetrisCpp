#pragma once


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

    int width_;
    int height_;
    const std::string& imgPath_;
    const std::string& fontPath_;
    Font font_;
    Text endMessage_;
    Text restartMessage_;

    Texture tilesTexture_;
    Texture backgroundTexture_;
    Texture frameTexture_;

    Sprite tilesSprite_;
    Sprite backgroundSprite_;
    Sprite frameSprite_;

public:
    GameWindow(
        const int width, 
        const int height, 
        const std::string& fontPath,
        const std::string& imgPath 
    );

    void startGame() {};
    void pauseGame() {};
    void resumeGame() {};
    bool quitGame() { return false; };
    void resetGame() {};
};

} // namespace game
#include "inc/GameWindow.hpp"

#include "Path.hpp"

#include <iostream>
#include <stdexcept>

namespace game {

GameWindow::GameWindow(
        const uint width, 
        const uint height, 
        const std::string& fontPath,
        const std::string& imgPath)
    : width_(width)
    , height_(height) 
    , window_({width_, height_}, TETRIS_TITLE)
    , fontPath_(fontPath)
    , imgPath_(imgPath)
{
    if (!font_.loadFromFile(fontPath_)) {
        std::string error = "Couldn't load font file! Path was: '" + fontPath_ + "' could not be loaded!";
        std::cout << error << std::endl;
        throw std::invalid_argument(error);
    } 

    endMessage_.setFont(font_);
    endMessage_.setString("GAME OVER!");
    endMessage_.setCharacterSize(30);
    endMessage_.setFillColor(Color::White);
    endMessage_.setStyle(Text::Bold);

    restartMessage_.setFont(font_);
    restartMessage_.setString("Press r to restart");
    restartMessage_.setCharacterSize(20);

    pauseMessage_.setFont(font_);
    pauseMessage_.setString("PAUSED!\n  Use 'C' to Continue\n  'R' to restart\n  'Q' to Quit");

    tilesTexture_.loadFromFile(helpers::Path::toString({imgPath, TILES_IMG}));
    tilesSprite_ = Sprite(tilesTexture_);

    backgroundTexture_.loadFromFile(helpers::Path::toString({imgPath, BACKGROUND_IMG}));
    backgroundSprite_ = Sprite(backgroundTexture_);

    frameTexture_.loadFromFile(helpers::Path::toString({imgPath, FRAME_IMG}));
    frameSprite_ = Sprite(frameTexture_);

    window_.setFramerateLimit(60);
}

void GameWindow::renderGame() {

    window_.clear(Color::White);
    window_.draw(backgroundSprite_);

    window_.draw(frameSprite_);
    window_.display();
}

void GameWindow::renderPauseMenu() {
    pauseMessage_.setPosition(30,400);
    pauseMessage_.setCharacterSize(14);
    window_.draw(pauseSprite_);
    window_.draw(pauseMessage_);
    window_.display();
}

void GameWindow::renderEndGame() {
    endMessage_.setPosition(50,400); 
    restartMessage_.setPosition(80,440); 
    window_.draw(endMessage_);
    window_.draw(restartMessage_);
}

} // namespace game

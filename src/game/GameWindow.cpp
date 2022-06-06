#include "GameWindow.cpp"

#include "Path.hpp"
#include <stdexcept>

namespace game {

GameWindow::GameWindow(
        const int width, 
        const int height, 
        const std::string& fontPath,
        const std::string& imgPath,
    );
    : width_(width)
    , height_(height) 
    , fontPath_(fontPath)
    , imgPath_(imgPath)
{
    Font font;
    if (!font.loadFromFile(fontPath)) {
        std::string error = "Couldn't load font file! Path was: '" + fontPath + "' could not be loaded!";
        std::cout << error << std::endl;
        throw std::invalid_argument(error);
    } 

    end_message_.setFont(font);
    end_message_.setString("GAME OVER!");
    end_message_.setCharacterSize(30);
    end_message_.setFillColor(Color::White);
    end_message_.setStyle(Text::Bold);

    restart_message_.setFont(font);
    restart_message_.setString("Press r to restart");
    restart_message_.setCharacterSize(20);

    // Declare window
    RenderWindow window(VideoMode(width_, height_), TETRIS_TITLE); 

    tilesTexture_.loadFromFile(helpers::Path::toString({imgPath, TILES_IMG}));
    tilesSprite_(tilesTexture_);

    backgroundTexture_.loadFromFile(helpers::Path::toString({imgPath, BACKGROUND_IMG}));
    backgroundSprite_(backgroundTexture_);

    frameTexture_.loadFromFile(helpers::Path::toString({imgPath, FRAME_IMG}));
    frameSprite_(framgeTexture_);
}

} // namespace game
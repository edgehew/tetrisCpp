// Matthew Edge

#include "GameController.hpp"
#include "GameWindow.hpp"

#include <chrono>
#include <iostream>
#include <time.h>
#include <thread>

/* Constant Variables
 */
const int WIDTH = 320;
const int HEIGHT = 480;

const std::string DEFAULT_FONT_FILE_PATH = "../share/fonts/Pacifico.ttf";
const std::string DEFAULT_IMG_FILE_PATH = "../share/images";

int main() {

    game::GameWindow window(
        WIDTH, 
        HEIGHT, 
        DEFAULT_FONT_FILE_PATH, 
        DEFAULT_IMG_FILE_PATH
    );

    game::GameController controller(window);
    controller.runGame();
    
    return 0;
}
#pragma once

namespace tetromino {

enum class Direction : uint8_t {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3, 
};

class Point {

private:
    int m_x;
    int m_y;

public:
    Point (int x, int y);

    const int& getX() {return m_x;}
    const int& getY() {return m_y;}

    Move(Direction d);
};

}
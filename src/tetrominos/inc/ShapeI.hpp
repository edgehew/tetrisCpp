#pragma once

namespace tetromino {

class ShapeI : public ITetromino {
private:
public:
    ShapeI()
        : m_shape({1, 3, 5, 7})
private:
};

} // namespace tetromino

#pragma once

namespace tetromino {

class ITetromino {
private:
public:
    ITetromino();
    virtual ~ITetromino() = 0;

    void Move(Direction d);

private:
    Point m_shape[4];
};

} // namespace tetromino
#include <cmath>

#include "ticker.h"

void Ticker::draw(QPainter & painter, int time) const {
    std::pair<int, int> vec = rotate_vec({0, 100}, get_angle(time));

    painter.drawLine(
                position.first,
                position.second,
                position.first + vec.first,
                position.second + vec.second 
    );
    painter.drawEllipse(
                position.first + vec.first - 10,
                position.second + vec.second - 10,
                20, 20
    );
}

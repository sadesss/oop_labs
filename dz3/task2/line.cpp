#include <QPainter>

#include <line.h>

void Line::draw(QPainter & painter, int time) const {
    std::pair<int, int> vec = rotate_vec({0, 100}, get_angle(time));

    painter.drawLine(
                position.first,
                position.second,
                position.first + vec.first, 
                position.second + vec.second
    );
}

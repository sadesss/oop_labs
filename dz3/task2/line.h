#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include <utility>

#include <figure.h>

class Line : public Figure {
public:
    Line(std::pair<int, int> position, double amplitude, double oscillation)
        : Figure(position, amplitude, oscillation) {};

    virtual void draw(QPainter & painter, int time) const override;
};

#endif // LINE_H 

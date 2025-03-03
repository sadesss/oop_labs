#ifndef TICKER_H
#define TICKER_H

#include <QPainter>
#include <utility>

#include <figure.h>

class Ticker : public Figure {
public:
    Ticker(std::pair<int, int> position, double amplitude, double oscillation)
        : Figure(position, amplitude, oscillation) {}; 

    virtual void draw(QPainter & painter, int time) const override;
};

#endif // TICKER_H

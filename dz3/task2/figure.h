#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <utility>

class Figure {
protected:
    std::pair<int, int> position;
    double amplitude;
    double oscillation;

    double get_angle(int time) const;
    std::pair<int, int> rotate_vec(const std::pair<int ,int> & vec, double angle) const;
public:
    Figure(std::pair<int, int> position, double amplitude, double oscillation)
        : position(position), amplitude(amplitude), oscillation(oscillation) {};

    virtual void draw(QPainter & painter, int time) const =0; 
    virtual ~Figure() {}
};
#endif // FIGURE_H

#include <cmath>

#include "figure.h"

double Figure::get_angle(int time) const {
    double pi = 3.14; 
    double alpha = 2 * pi * (time / oscillation);
    alpha = sin(alpha) * amplitude / 180 * pi;
    return alpha;
}

std::pair<int, int> Figure::rotate_vec(const std::pair<int, int> & vec, double alpha) const {
    return {
        static_cast<int>(+ cos(alpha)*vec.first + sin(alpha)*vec.second),
        static_cast<int>(- sin(alpha)*vec.first + cos(alpha)*vec.second)
    };
}

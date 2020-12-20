//
// Created by prota on 15.10.2020.
//

#ifndef OOP_EXERCISE_03_HEXAGON_H
#define OOP_EXERCISE_03_HEXAGON_H

#include "Figure.h"

class Hexagon: public Figure{
public:
    Hexagon(Cord center, double radius);
    double Area() override;
    void print() override;
};
#endif

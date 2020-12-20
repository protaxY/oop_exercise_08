//
// Created by prota on 15.10.2020.
//

#ifndef OOP_EXERCISE_03_OCTAGON_H
#define OOP_EXERCISE_03_OCTAGON_H

#include "Figure.h"

class Octagon: public Figure{
public:
    Octagon(Cord center, double radius);
    double Area() override;
    void print() override;
};

#endif
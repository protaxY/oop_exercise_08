//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольникб 8-ти угольник

#ifndef OOP_EXERCISE_03_PENTAGON_H
#define OOP_EXERCISE_03_PENTAGON_H

#include "Figure.h"

class Pentagon: public Figure{
public:
    Pentagon(Cord center, double radius);
    double Area() override;
    void print() override;
};
#endif

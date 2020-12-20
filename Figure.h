//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольникб 8-ти угольник

#ifndef OOP_EXERCISE_03_FIGURE_H
#define OOP_EXERCISE_03_FIGURE_H

#include "Cord.h"
#include <iostream>
#include <cmath>
#include <string>

const double PI = 3.14159265358979323846264338327950288419716939937510;

class Figure{
protected:
    Cord Center;
    double Radius = 0;
    std::string Type;
public:
    Figure(Cord center, double radius);
    Cord GetCenter();
    double GetRadius();
    std::string GetType();
    virtual double Area() = 0;
    virtual void print() = 0;
};
#endif
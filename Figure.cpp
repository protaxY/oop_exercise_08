//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольникб 8-ти угольник

#include "Figure.h"
#include "math.h"

Figure::Figure(Cord center, double radius){
    Center = center;
    Radius = radius;
}

Cord Figure::GetCenter(){
    return Center;
}

double Figure::GetRadius(){
    return Radius;
}

std::string Figure::GetType(){
    return Type;
}
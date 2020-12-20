//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольникб 8-ти угольник

#include "Pentagon.h"

Pentagon::Pentagon(Cord center, double radius):Figure(center,radius){
    Type = "Pentagon";
};

double Pentagon::Area(){
return 5 * 0.5 * sin((double) 72 / 180 * PI) * Radius * Radius;
}

void Pentagon::print(){
    for (int i = 0; i < 5; ++i){
        Cord radVector(Radius * sin((double) (i * 72) / 180 * PI), Radius * cos((double) (i * 72) / 180 * PI));
        if (i == 4) {
            std::cout << Center + radVector << ".";
        } else {
            std::cout << Center + radVector << ", ";
        }
    }
}
//
// Created by prota on 15.10.2020.
//

#include "Hexagon.h"

Hexagon::Hexagon(Cord center, double radius):Figure(center,radius){
    Type = "Hexagon";
};

double Hexagon::Area(){
    return 6 * 0.5 * sin((double) 60 / 180 * PI) * Radius * Radius;
}

void Hexagon::print(){
    for (int i = 0; i < 6; ++i){
        Cord radVector(Radius * sin((double) (i * 60) / 180 * PI), Radius * cos((double) (i * 60) / 180 * PI));
        if (i == 5) {
            std::cout << Center + radVector << ".";
        } else {
            std::cout << Center + radVector << ", ";
        }
    }
}
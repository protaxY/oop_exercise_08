//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольник 8-ти угольник

#ifndef OOP_LP7_FACTORY_H
#define OOP_LP7_FACTORY_H

#include <memory>

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

template <class T>
struct Factory{
    std::shared_ptr<Figure> CreateFigure(std::string &type){
        std::shared_ptr<Figure> result;
        if (type == "Pentagon"){
            std::cout << "enter pentagon center cords and radius:";
            Cord center;
            double radius;
            std::cin >> center.X >> center.Y >> radius;
            if (radius < 0){
                throw std::invalid_argument("incorrect radius");
            }
            Pentagon* pentagon = new Pentagon(center, radius);
            result = std::shared_ptr<Figure>(pentagon);
        } else if (type == "Hexagon"){
            std::cout << "enter hexagon center cords and radius:";
            Cord center;
            double radius;
            std::cin >> center.X >> center.Y >> radius;
            if (radius < 0){
                throw std::invalid_argument("incorrect radius");
            }
            Hexagon* hexagon = new Hexagon(center, radius);
            result = std::shared_ptr<Figure>(hexagon);
        } else if (type == "Octagon"){
            std::cout << "enter octagon center cords and radius:";
            Cord center;
            double radius;
            std::cin >> center.X >> center.Y >> radius;
            if (radius < 0){
                throw std::invalid_argument("incorrect radius");
            }
            Octagon* octagon = new Octagon(center, radius);
            result = std::shared_ptr<Figure>(octagon);
        } else {
            throw std::invalid_argument("unknown figure type");
        }
        return result;
    }
};

#endif //OOP_LP7_FACTORY_H

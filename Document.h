//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольник 8-ти угольник

#ifndef OOP_LP7_DOCUMENT_H
#define OOP_LP7_DOCUMENT_H

#include <stack>
#include <list>
#include <exception>
#include <algorithm>
#include <utility>
#include <fstream>

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Factory.h"

struct Event{
    virtual void Undo(std::list<std::shared_ptr<Figure>>&) = 0;
};

struct AddEvent: public Event{
    size_t pos;
    std::shared_ptr<Figure> FigureToAdd;
    AddEvent(size_t pos, std::shared_ptr<Figure> FigureToAdd): pos(pos), FigureToAdd(std::move(FigureToAdd)) {}
    void Undo(std::list<std::shared_ptr<Figure>> &Data) override{
        auto iter = Data.begin();
        while (pos--){
            iter++;
        }
        Data.erase(iter);
    }
};

struct DeleteEvent: public Event{
    int pos;
    std::shared_ptr<Figure> FigureToDelete;
    DeleteEvent(size_t pos, std::shared_ptr<Figure> FigureToDelete): pos(pos), FigureToDelete(std::move(FigureToDelete)) {}
    void Undo(std::list<std::shared_ptr<Figure>> &Data) override{
        auto iter = Data.begin();
        while (pos--){
            iter++;
        }
        Data.insert(iter, FigureToDelete);
    }
};

class Document{
private:
    std::stack<std::shared_ptr<Event>> History;
    std::list<std::shared_ptr<Figure>> Data;
    Factory<Figure> factory;
public:
    size_t GetSize(){
        return Data.size();
    }
    void Create(){
        Data.clear();
        while(!History.empty()){
            History.pop();
        }
        std::cout << "document created\n";
    }
    void Add(size_t pos, std::string &type){
        std::shared_ptr<Figure> figure = factory.CreateFigure(type);
        AddEvent event(pos, figure);
        History.push(std::shared_ptr<Event>(new AddEvent(pos, figure)));
        auto iter = Data.begin();
        while (pos--){
            iter++;
        }
        Data.insert(iter, figure);
        std::cout << "ok\n";
    }
    void Delete(int pos){
        auto iter = Data.begin();
        while (pos--){
            iter++;
        }
        History.push(std::shared_ptr<Event>(new DeleteEvent(pos, *iter)));
        Data.erase(iter);
        std::cout << "ok\n";
    }
    void Undo(){
        if (!History.empty()){
            History.top() -> Undo(Data);
            History.pop();
            std::cout << "undo\n";
        } else {
            std::cout << "nothing to undo\n";
        }
    };
    void Print(){
        auto iter = Data.begin();
        for (int i = 0; i < Data.size(); ++i){
            iter -> get() -> print();
            std::cout << "\n";
            iter++;
        }
    }
    void Save(std::string &fileName){
        std::ofstream fout(fileName);
        if (fout.fail()) {
            throw std::runtime_error("Error opening file");
        }
        fout << Data.size() << "\n";
        auto iter = Data.begin();
        for (int i = 0; i < Data.size(); ++i){
            fout << iter -> get() -> GetType() << " " << iter -> get() -> GetCenter().X << " " <<
            iter -> get() -> GetCenter().Y << " " << iter -> get() -> GetRadius() << "\n";
            iter++;
        }
        fout.close();
        std::cout << "saved\n";
    }
    void Load(std::string &fileName){
        Data.clear();
        while (!History.empty()){
            History.pop();
        }
        std::ifstream fin(fileName);
        if (fin.fail()) {
            throw std::runtime_error("Error opening file");
        }
        size_t size;
        fin >> size;
        std::string type;
        Cord center;
        double radius;
        for (int i = 0; i < size; ++i){
            fin >> type >> center.X >> center.Y >> radius;
            if (type == "Pentagon"){
                auto pentagon = new Pentagon(center, radius);
                std::shared_ptr<Figure> figure(pentagon);
                Data.push_back(figure);
            } else if (type == "Hexagon"){
                auto hexagon = new Hexagon(center, radius);
                std::shared_ptr<Figure> figure(hexagon);
                Data.push_back(figure);
            } else if (type == "Octagon"){
                auto octagon = new Octagon(center, radius);
                std::shared_ptr<Figure> figure(octagon);
                Data.push_back(figure);
            }
        }
        fin.close();
        std::cout << "loaded\n";
    }
};

#endif //OOP_LP7_DOCUMENT_H

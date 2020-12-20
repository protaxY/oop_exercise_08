//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольник 8-ти угольник

#include <iostream>

#include "Document.h"

int main() {
    Document doc;
    doc.Create();
    char function;
    while (std::cin >> function){
        try{
            if (function == '+'){
                std::cout << "enter position for insert:";
                int pos;
                std::cin >> pos;
                if (pos < 0 || pos > doc.GetSize()){
                    throw std::invalid_argument("invalid position to insert");
                }
                std::cout << "enter type of figure:";
                std::string type;
                std::cin >> type;
                doc.Add(pos, type);
            }
            if (function == '-'){
                std::cout << "enter position for delete:";
                int pos;
                std::cin >> pos;
                if (pos < 0 || pos > doc.GetSize()){
                    throw std::invalid_argument("invalid position to delete");
                }
                doc.Delete(pos);
            }
            if (function == 's'){
                doc.Print();
            }
            if (function == '.'){
                doc.Undo();
            }
            if (function == 'S'){
                std::cout << "enter file name to save:";
                std::string fileName;
                std::cin >> fileName;
                doc.Save(fileName);
            }
            if (function == 'L'){
                std::cout << "enter file name to load:";
                std::string fileName;
                std::cin >> fileName;
                doc.Load(fileName);
            }
        }
        catch (std::exception &e){
            std::cout << e.what();
        }
    }
    return 0;
}


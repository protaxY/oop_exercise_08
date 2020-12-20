//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольник 8-ти угольник

#include <iostream>
#include <ctime>
#include <functional>
#include <thread>
#include <vector>

#include "Figure.h"
#include "Factory.h"
#include "PubSub.h"

FILE* file = nullptr;
PubSub<std::vector<std::shared_ptr<Figure>>> messageQueue;

int cnt = 0;
std::string RandFileName(size_t n) {
    ++cnt;
    std::string res = std::to_string(cnt);
    return res;
}

void ThreadFunction() {
    std::function<void(std::shared_ptr<Figure> figure)> Print = [](const std::shared_ptr<Figure>& figure) {
        figure->print();
        std::cout << "\n";
    };
    std::function<void(std::shared_ptr<Figure> figure)> SaveToFIle = [](const std::shared_ptr<Figure>& figure) {
        fprintf(file, "%s %lf %lf %lf\n",
                figure->GetType().c_str(), figure->GetCenter().X, figure->GetCenter().Y, figure->GetRadius());
    };
    std::vector<std::function<void(std::shared_ptr<Figure> figure)>> functions({Print, SaveToFIle});
    while (true) {
        if (!messageQueue.Empty()) {
            std::vector<std::shared_ptr<Figure>> message = messageQueue.Front();
            if (message.empty()) {
                break;
            }
            file = fopen((RandFileName(16)).c_str(), "w");
            while (!message.empty()) {
                std::shared_ptr<Figure> figPtr = message.back();
                message.pop_back();
                for (const auto& function : functions) {
                    function(figPtr);
                }
            }
            fclose(file);
            std::cout << "saved\n";
            messageQueue.Pop();
        }
    }
}

int main(int argc, char *argv[]) {
    size_t maxBufferSize;
    try {
        if (argc < 2) {
            throw std::invalid_argument("Buffer size expected");
        }
        maxBufferSize = std::strtoull(argv[1], nullptr, 10);
        if (maxBufferSize == 0) {
            throw std::invalid_argument("Invalid buffer size");
        }
    }
    catch (std::exception &e){
        std::cout << e.what();
    }

    std::thread thread(ThreadFunction);
    Factory factory;
    std::vector<std::shared_ptr<Figure>> buffer;
    std::string type;
    std::cout << "enter type of figure to add:";
    try {
        while (std::cin >> type){
            buffer.push_back(factory.CreateFigure(type));
            if (buffer.size() == maxBufferSize){
                messageQueue.Push(buffer);
                bool ThreadWorkFinishFlag = false;
                while (!ThreadWorkFinishFlag) {
                    if (messageQueue.Empty()) {
                        ThreadWorkFinishFlag = true;
                    }
                }
                buffer.clear();
            }
            std::cout << "enter type of figure to add:";
        }
    }
    catch (std::exception &e){
        std::cout << e.what();
    }
    messageQueue.Push(buffer);
    buffer.clear();
    messageQueue.Push(buffer);
    thread.join();
    return 0;
}


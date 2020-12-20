//Федоров Антон Сергеевич М8О-207Б-19
//вариант 30: 5-ти угольник, 6-ти угольник 8-ти угольник

#ifndef OOP_LP8_PUBSUB_H
#define OOP_LP8_PUBSUB_H

#include <mutex>
#include <queue>

template<class T>
class PubSub {
private:
    std::queue<T> MessageQueue;
    std::mutex Mutex;
public:
    explicit PubSub() noexcept : MessageQueue(), Mutex() {}
    ~PubSub() {}

    bool Empty() {
        Mutex.lock();
        bool res = MessageQueue.empty();
        Mutex.unlock();
        return res;
    }

    T Front() {
        Mutex.lock();
        T elem = MessageQueue.front();
        Mutex.unlock();
        return elem;
    }

    void Pop() {
        Mutex.lock();
        MessageQueue.pop();
        Mutex.unlock();
    }

    void Push(const T & message) {
        Mutex.lock();
        MessageQueue.push(message);
        Mutex.unlock();
    }
};

#endif //OOP_LP8_PUBSUB_H

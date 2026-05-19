#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    T* data;
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    Queue(int cap = 100) {
        capacity = cap;
        data = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        if(rearIndex == capacity - 1) return;
        data[++rearIndex] = value;
    }

    T dequeue() {
        return data[frontIndex++];
    }

    T front() {
        return data[frontIndex];
    }

    bool empty() {
        return frontIndex > rearIndex;
    }

    int size() {
        return rearIndex - frontIndex + 1;
    }
};
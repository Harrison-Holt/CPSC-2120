/**
  Name: Harrison S. Holt
  Date: 2-15-23
  Assignment: Queue Implementation Using a Circular Array
*/

#pragma once

#include <iostream>

using namespace std;

// IntegerArrayQueue is a fixed-size queue of integers, implemented
// using a circular array. The array is dynamically allocated but remains
// constant in size throughout the object's lifespan. Do not modify the class definition.

class IntegerArrayQueue {
    private:
        int* array; // Pointer to array of integers
        int front;  // Index of item to dequeue
        int back;   // Index of item to enqueue
        int size;

    public:
        IntegerArrayQueue() : array(new int[10]), front(0), back(9), size(10) {
            for (int i = 0; i < 10; i++) array[i] = 0;
        }
        IntegerArrayQueue(int size) : array(new int[size]), front(0), back(size-1), size(size) {
            for (int i = 0; i < size; i++) array[i] = 0;
        }
        ~IntegerArrayQueue() { delete[] array; }

        void printArrayQueue() {
            for (int i = 0; i < size; i++) cout << array[i] << " ";
            cout << endl << "front: " << front << endl << "back: " << back << endl << "size: " << size << endl;
        }

        // Enqueue function: If space is available, enqueue the value and return true. Otherwise, return false.
        bool enqueue(int value);

        // Dequeue function: If there is a value at the front of the queue, return and remove it. Otherwise, return 0.
        int dequeue();
};


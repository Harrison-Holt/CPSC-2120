/**
  Name: Harrison S. Holt
  Date: 2-15-23
  Assignment: Queue Implementation Using a Circular Array
*/

#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value) {
    if (front == (back + 2) % size) return false; // Queue is full

    back = (back + 1) % size;
    array[back] = value;
    return true; // Value enqueued successfully
}

int IntegerArrayQueue::dequeue() {
    if (front == (back + 1) % size) return 0; // Queue is empty

    int value = array[front];
    front = (front + 1) % size;
    return value; // Return dequeued value
}

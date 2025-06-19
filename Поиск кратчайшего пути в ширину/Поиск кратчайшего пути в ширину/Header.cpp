#include "Header.h"

Queue::Queue() : front(0), rear(0) {}

bool Queue::empty() {
    return front == rear;
}

void Queue::push(int val) {
    data[rear++] = val;
}

int Queue::pop() {
    return data[front++];
}
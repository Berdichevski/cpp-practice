#pragma once

struct Queue 
{
    int data[1000];
    int front, rear;

    Queue();
    bool empty();
    void push(int val);
    int pop();
};

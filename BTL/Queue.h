#pragma once
#include <string>

using namespace std;

struct QueueNode {
    string maSV;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

void initQueue(Queue& q);
void pushQueue(Queue& q, string maSV);
string popQueue(Queue& q);
bool isEmpty(Queue q);
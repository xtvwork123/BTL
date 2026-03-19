#include "Queue.h"
#include <iostream>
using namespace std;

void initQueue(Queue& q) {
    q.front = NULL;
    q.rear = NULL;
}

QueueNode* taoNodeQueue(string maSV) {
    QueueNode* p = new QueueNode;
    if (p == NULL) {
        cout << "Loi: Khong du bo nho de cap phat!" << endl;
        return NULL;
    }
    p->maSV = maSV;
    p->next = NULL;
    return p;
}

void pushQueue(Queue& q, string maSV) {
    QueueNode* p = taoNodeQueue(maSV);
    if (p == NULL) return; 

    // TH1: Neu hang doi dang rong
    if (q.front == NULL) {
        q.front = p;
        q.rear = p;
    }
    // TH2: Da co sinh vien trong hang doi
    else {
        q.rear->next = p; 
        q.rear = p;      
    }
}

string popQueue(Queue& q) {
    
    if (q.front == NULL) {
        return ""; 
    }

    QueueNode* p = q.front;       
    string maSV_layRa = p->maSV;  

    q.front = q.front->next;      
    
    if (q.front == NULL) {
        q.rear = NULL;
    }

    delete p;  

    return maSV_layRa; 
}

bool isEmpty(Queue q) {
    return (q.front == NULL);
}
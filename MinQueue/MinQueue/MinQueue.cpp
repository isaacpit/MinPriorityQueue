// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include "MinQueue.h"
#include <stdexcept>
#include <time.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int MinQueue::min() {
    int min = first();
    DListNode *p = getFirst();
    for (int i = 0; i < size(); ++i) {
        if (p->obj < min) {
            min = p->obj;
        }
        else {
            // do nothing
        }
        p = p->next;
    }


    return min;
}
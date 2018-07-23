// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include "MinQueue.h"
#include "DoublyLinkedList.h"
#include <iostream>
// #pragma once

using namespace std;
int main () {
  /*
  MinQueue mq;
  cout << "MinQueue: " << mq << endl;
  mq.insertFirst(11);
  cout << "MinQueue.insertFirst(11): " << mq << endl;
  mq.enqueue(12);
  cout << "MinQueue.enqueue(12): " << mq << endl;
  cout << "MinQueue.min(); " << mq.min() << endl;

  cout << "MinQueue.dequeue(): " << mq.dequeue() << endl;
  cout << "Minqueue after: " << mq << endl;

  cout << "Minqueue.size(): " << mq.size() << endl;
  cout << "mq.dequeue(): " << mq.dequeue() << endl;
  cout << "mq.isEmpty(): " << mq.isEmpty() << endl;
  */

  // Construct a linked list with header & trailer
  cout << "Create a new queue" << endl;
  MinQueue mq; 
  cout << "queue:\n" << mq << endl << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100 " <<
  "using enqueue\nqueue:\n";
  for (int i=10;i<=100;i+=10) {
    mq.enqueue(i);
  }
  cout << mq;
  cout << "queue.min():\n" << mq.min() << endl << endl;
  
  // Copy to a new queue
  cout << "Copy to a new queue" << endl;
  MinQueue mq2(mq);
  cout << "queue2:\n" << mq2 << endl;
  
  // Assign to another new queue
  cout << "Assign to another new queue" << endl;
  MinQueue mq3;
  mq3 = mq;
  cout << "queue3:\n" << mq3 << endl;

  // Assignment to list with existing elements
  cout << "Assignment to existing queue" << endl;
  MinQueue mq4;
  mq4.insertFirst(1);
  mq4.insertFirst(2);
  cout << "queue4 before:\n" << mq4;
  mq4=mq;
  cout << "queue4 after, queue4 = queue:\n" << mq4 << endl;
  
  // dequeue first 5 elements
  cout << "Dequeue first five elements" << endl;
  for (int i=0;i<5;i++) {
    cout << mq.dequeue() << " ";
  }
  cout << "\nqueue after five dequeues:\n" << mq;
  cout << "queue.min():\n" << mq.min() << endl;
  
  // Check the other two lists
  cout << "Make sure the other two queues are not affected." << endl;
  cout << "queue2:\n" << mq2;
  cout << "queue3:\n" << mq3 << endl;
  cout << "queue4:\n" << mq4 << endl;

  return 0;
}

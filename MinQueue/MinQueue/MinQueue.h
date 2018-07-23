// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include "DoublyLinkedList.h"

class MinQueue : public DoublyLinkedList {
  
public: 
  void enqueue(int obj) { insertLast(obj); }
  int dequeue() { return removeFirst(); } 
  int size() { DoublyLinkedListLength(*this); }
  bool isEmpty() { DoublyLinkedList::isEmpty(); }
  int min(); 
  
};
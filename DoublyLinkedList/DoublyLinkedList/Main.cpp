// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;
int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList dll; 
  cout << "list:\n" << dll << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertLast(i);
  }
  cout << "list:\n" << dll << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertFirst(i);
  }
  cout << "list:\n" << dll << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList dll2(dll);
  cout << "list2:\n" << dll2 << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList dll3;
  dll3=dll;
  cout << "list3:\n" << dll3 << endl;

  // Assignment to list with existing elements
  cout << "Assignment to existing list" << endl;
  DoublyLinkedList dll4;
  dll4.insertFirst(1);
  dll4.insertFirst(2);
  cout << "list4 before:\n" << dll4;
  dll4=dll;
  cout << "list4 after:\n" << dll3 << endl;
  
  // // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list:\n" << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2:\n" << dll2 << endl;
  cout << "list3:\n" << dll3 << endl;

  // more testing...
  // add tests for DoublyLinkedListLength
  DoublyLinkedList test;
  test.insertFirst(3);
  test.insertFirst(2);
  test.insertFirst(1);
  test.insertLast(4);
  test.insertLast(5);
  cout << "test: " << test;
  cout << "test.first() = " << test.first() << endl;
  cout << "test.last()  = " << test.last() << endl;
  cout << "test.length() = " << DoublyLinkedListLength(test) << endl << endl;

  //
  DoublyLinkedList emptyList;
  cout << "emptyList:\n" << emptyList;
  cout << "\nDoublyLinkedListLength(emptyList) = " << DoublyLinkedListLength(emptyList) << endl << endl;

  // add tests for insertAfter, insertBefore
  DListNode *insAfter = test.getFirst()->next;
  cout << "*insAfter: " << insAfter->obj << endl;
  cout << "test:\n" << test;
  test.insertAfter(*insAfter, 100);
  cout << "test.insertAfter(*insAfter, 100):\n" << test << endl;

  DListNode *insBefore = test.getFirst()->next->next;
  cout << "*insBefore: " << insBefore->obj << endl;
  cout << "test:\n" << test;
  test.insertBefore(*insBefore, 99);
  cout << "test.insertBefore(*insBefore, 99):\n" << test << endl;

  // add tests for removeAfter, removeBefore
  DListNode *delAfter = test.getAfterLast()->prev->prev->prev;
  cout << "*delAfter: " << delAfter->obj << endl;
  cout << "test:\n" << test;
  cout << "show trailer: " << test.getAfterLast()->obj << endl;
  test.removeAfter(*delAfter);
  cout << "test.removeAfter(*delAfter):\n" << test << endl;


  cout << "Trying to delete trailer case: " << endl;
  DListNode *lastItem = test.getAfterLast()->prev;
  cout << "*lastItem: " << lastItem->obj << endl;
  cout << "test:\n" << test;
  test.removeAfter(*lastItem);
  cout << "test.removeAfter(*lastItem):\n" << test << endl;


  cout << "Trying to delete item before trailer: " << endl;
  DListNode *secondLast= test.getAfterLast()->prev->prev;
  cout << "*secondLast: " << secondLast->obj << endl;
  cout << "test:\n" << test;
  test.removeAfter(*secondLast);
  cout << "test.removeAfter(*secondLast):\n" << test;

  cout << "\nTrying to delete header: " << endl;
  DListNode *firstElem = test.getFirst();
  cout << "*firstElem: " << firstElem->obj << endl;
  cout << "test:\n" << test;
  test.removeBefore(*firstElem);
  cout << "test.removeBefore(*firstElem):\n" << test;

  cout << "\nTrying to delete a valid item: " << endl;
  DListNode *anElem = test.getFirst()->next->next->next;
  cout << "*anElem: " <<  anElem->obj << endl;
  cout << "test:\n" << test;
  test.removeBefore(*anElem);
  cout << "test.removeBefore(*anElem):\n" << test;

  return 0;
}

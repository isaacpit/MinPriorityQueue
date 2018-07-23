// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;

  TemplateLinkedList<string> dll ;
  cout << "list<string>: " << dll << endl << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  cout << "list<string>: " << dll << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  cout << "list<string>: " << dll << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  TemplateLinkedList<string> dll2(dll);
  cout << "list2<string>: " << dll2 << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  TemplateLinkedList<string> dll3;
  dll3=dll;
  cout << "list3<string>: " << dll3 << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list<string>: " << dll << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list<string>: " << dll << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2<string>: " << dll2;
  cout << "list3<string>: " << dll3;

  // more testing...
  // add tests for insertAfter, insertBefore
  cout << "\nTests for insertAfter:\n";
  cout << "list2<string>:\n" << dll2;
  string s = "newItem";
  DListNode<string> *p = dll2.getFirst()->next->next;
  cout << "*p: " << p->obj << endl;
  dll2.insertAfter(*p, s);
  cout << "list2<string>.insertAfter(*p, s):\n" << dll2;

  cout << "\nTest for insertBefore:\n";
  cout << "list2<string>:\n" << dll2;
  string s2 = "newItemB4";
  DListNode<string> *p2 = dll2.getFirst()->next->next;
  cout << "*p: " << p->obj << endl;
  dll2.insertBefore(*p2, s2);
  cout << "list2<string>.insertAfter(*p, s):\n" << dll2;

  // add tests for removeAfter, removeBefore
  cout << "\nTest for removeAfter:\n";
  cout << "list2<string>:\n" << dll2;
  cout << "*p: " << p->obj << endl;
  dll2.removeAfter(*p);
  cout << "list2<string>.removeAfter(*p):\n" << dll2;

  cout << "\nTest for removeBefore:\n";
  cout << "list2<string>:\n" << dll2;
  cout << "*p: " << p->obj << endl;
  dll2.removeBefore(*p);
  cout << "list2<string>.removeBefore(*p):\n" << dll2;

  // add tests for TemplateLinkedListLength
  int sz = TemplateLinkedListLength(dll2);
  cout << "TemplateLinkedListLength(list2):\n" << sz;
  return 0;
}

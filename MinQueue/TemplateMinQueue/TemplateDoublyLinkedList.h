// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <time.h>
#include <iostream>
#include <unistd.h>
#pragma once

using namespace std;

// list node
template <typename T> 
struct DListNode {
  T obj;
  DListNode<T> *prev, *next;
  DListNode<T>(T e = {}, DListNode<T> *p = NULL, DListNode<T> *n = NULL)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list

template <typename T>
class TemplateLinkedList {
private:
  DListNode<T> header, trailer;
public:
  TemplateLinkedList() {
      header = {}; 
      trailer = {}; // constructor
      header.next = &trailer; 
      trailer.prev = &header; 
      }
  TemplateLinkedList(const TemplateLinkedList& dll); // copy constructor
  ~TemplateLinkedList(); // destructor
  TemplateLinkedList& operator=(const TemplateLinkedList& dll); // assignment operator
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; } 
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }
  // return if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  void removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  void removeLast(); // remove the last node
  void insertAfter(DListNode<T> &p, T newobj);
  void insertBefore(DListNode<T> &p, T newobj);
  void removeAfter(DListNode<T> &p);
  void removeBefore(DListNode<T> &p);
};

// output operator
template <typename T> 
ostream& operator<<(ostream& out, const TemplateLinkedList<T>& dll);

// return the list length
template <typename T> 
int TemplateLinkedListLength(const TemplateLinkedList<T>& dll);

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
template <typename T> 
TemplateLinkedList<T>::TemplateLinkedList(const TemplateLinkedList<T>& dll)
{
    // Initialize the list
    header.next = &trailer; trailer.prev = &header;
    /* Complete this function */
    if (dll.isEmpty()) {
        
    }
    else {
        DListNode<T> *pOrigin = dll.getFirst();
        T item = {};
        item = pOrigin->obj;
        int size = TemplateLinkedListLength(dll);
        for (int i = 0; i < size; ++i) {
            this->insertFirst(item);
            pOrigin = pOrigin->next;
            item = pOrigin->obj;
        }
    }

}

// assignment operator
template <typename T> 
TemplateLinkedList<T>& TemplateLinkedList<T>::operator=(const TemplateLinkedList<T>& dll)
{
    // Delete the whole list
    /* Complete this function */
    int size = TemplateLinkedListLength(*this);
    DListNode<T> *p = this->getFirst()->next;
    for (int i = 0; i < size; ++i) {
        p->prev = &header;
        delete this->getFirst();
        header.next = p;
    }

    if (dll.isEmpty()) {
        
    }
    else {
        DListNode<T> *pOrigin = dll.getFirst();
        T item = {};
        item = pOrigin->obj;
        size = TemplateLinkedListLength(dll);
        for (int i = 0; i < size; ++i) {
        this->insertFirst(item);
        pOrigin = pOrigin->next;
        item = pOrigin->obj;
    }
    }
    // debug:
    // cout << this;
}

// insert the new object as the first one
template <typename T> 
void TemplateLinkedList<T>::insertFirst(T newobj)
{ 
    /* Complete this function */

    DListNode<T> *tempNode = new DListNode<T>(newobj, &header, header.next);
    // cout << (*tempNode).obj;
    header.next->prev = tempNode;
    header.next = tempNode;
    // cout << header.next->obj;
    // trailer.prev = tempNode.next;
}

// insert the new object as the last one
template <typename T> 
void TemplateLinkedList<T>::insertLast(T newobj)
{
    /* Complete this function */
    DListNode<T> *tempNode = new DListNode<T>(newobj, trailer.prev, &trailer);
    trailer.prev->next = tempNode;
    trailer.prev = tempNode;
}

// remove the first object from the list
template <typename T> 
void TemplateLinkedList<T>::removeFirst()
{ 
    /* Complete this function */
    DListNode<T> *newFirst = this->getFirst()->next;
    newFirst->prev = &header;
    delete this->getFirst();
    header.next = newFirst;
}

// remove the last object from the list
template <typename T> 
void TemplateLinkedList<T>::removeLast()
{
    /* Complete this function */
    DListNode<T> *newLast = this->getAfterLast()->prev->prev;
    newLast->next = &trailer;
    delete trailer.prev;
    trailer.prev = newLast;
}

// destructor
template <typename T> 
TemplateLinkedList<T>::~TemplateLinkedList()
{
    /* Complete this function */
    for (int i = 0; i < TemplateLinkedListLength(*this); ++i) {
        removeFirst();
    }

}

// return the first object
template <typename T> 
T TemplateLinkedList<T>::first() const
{ 
    /* Complete this function */
    T firstObj = header.next->obj;
    return firstObj;
}

// return the last object
template <typename T> 
T TemplateLinkedList<T>::last() const
{
    /* Complete this function */

    return trailer.prev->obj;
}

// insert the new object after the node p
template <typename T> 
void TemplateLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
    /* Complete this function */
    DListNode<T> *newNode = new DListNode<T>(newobj, &p, p.next);
    p.next->prev = newNode;
    p.next = newNode;
}

// insert the new object before the node p
template <typename T> 
void TemplateLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
    /* Complete this function */
    // debug
    // cout << "p.obj: " << p.obj << endl;
    // cout << "p.prev->obj: " << p.prev->obj << endl;
    // cout << "p.next->obj: " << p.next->obj << endl;
    DListNode<T> *newNode = new DListNode<T>(newobj, p.prev, &p);
    // debug
    // cout << "nN->prev->obj: " << newNode->prev->obj << endl;
    // cout << "nN->next->obj: " << newNode->next->obj << endl;
    p.prev->next = newNode;
    p.prev = newNode;
}

// remove the node after the node p
template <typename T> 
void TemplateLinkedList<T>::removeAfter(DListNode<T> &p)
{
    /* Complete this function */
    // debug
    // cout << "p: " << &p << endl;
    // cout << p.obj << endl;
    // cout << "p.prev: " << p.prev << endl;
    // cout << p.prev->obj << endl;
    // cout << "p.next: " << p.next << endl;
    // cout << p.next->obj << endl;
    // cout << "trailer: " << this->getAfterLast() << endl;
    if (p.next == this->getAfterLast()) {
        cout << "Error: trying to delete trailer!" << endl;
    }
    else {
        DListNode<T> *deleteMe = p.next;
        // debug
        // cout << "deleteMe->obj  = " << deleteMe->obj << endl;
        // cout << "deleteMe->prev->obj = " << deleteMe->prev->obj << endl;
        // cout << "deleteMe->next->obj = " << deleteMe->next->obj << endl;
        p.next = deleteMe->next;
        deleteMe->next->prev = &p;
        // p.next->next->prev = &p;
        // p.next = p.next->next;
        delete deleteMe;
    }

}

// remove the node before the node p
template <typename T> 
void TemplateLinkedList<T>::removeBefore(DListNode<T> &p)
{
    /* Complete this function */
    // cout << "obj: " << this->getFirst()->prev << endl;
    // cout << "p.prev: " << p.prev << endl;
    DListNode<T> *deleteMe = p.prev;
    if (p.prev == this->getFirst()->prev) {
        cout << "Error: trying to delete header!" << endl;
    }
    else {
        deleteMe->prev->next = &p;
        delete p.prev;
        p.prev = deleteMe->prev;
    }
}

// return the list length
template <typename T> 
int TemplateLinkedListLength(const TemplateLinkedList<T>& dll)
{
    /* Complete this function */
    int i = 0;
    DListNode<T> *p = dll.getFirst();
    // cout << "last address: " << dll.getAfterLast() << endl;
    // int t = 1000000;
    // usleep(t);
    if (dll.isEmpty()) {
        // cout << "Error! List is empty." << endl;
        // throw (EmptyDLinkedListException("Error: Empty Linked List"));
        return i;
    }
    else {
        while (p != dll.getAfterLast()->prev) {
            // usleep(t);
            // cout << "p = " << p << endl;
            // cout << "*p = " << p->obj << endl;
            p = p->next;
            ++i;
        }
        ++i;
        return i;
    }

}

// output operator
template <typename T> 
ostream& operator<<(ostream& out, const TemplateLinkedList<T>& dll)
{
    
    /* Complete this function */
    
    if (dll.isEmpty()) {
        out << "List is empty, cannot put to ostream";
        return out;
    }
    DListNode<T> *p = dll.getFirst();
    while (p != dll.getAfterLast()->prev) {
        // out << "i: " << i << "\t" << p << endl;
        // out << "\tcontents: " << p->obj << endl;
        out << p->obj << " ";
        p = p->next;
    }
    out << p->obj << endl;
    p = p->next;

    // debug
    // out << "i: " << i << "\t" << p << endl;
    // out << "\tcontents: " << p->obj << endl;



    //debug 
    // p = dll.getFirst();
    // while (p != dll.getAfterLast()) {
    //     out << "p->obj: " << p->obj << "\tp->prev->obj: " << p->prev->obj
    //     << "\tp->next->obj: " << p->next->obj << endl; 
    //     p = p->next;
    //     ++i;
    // }
    return out;
}

// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include <stdexcept>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include "DoublyLinkedList.h"

using namespace std;

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
    // Initialize the list
    header.next = &trailer; trailer.prev = &header;
    /* Complete this function */
    if (dll.isEmpty()) {
        
    }
    else {
        DListNode *pOrigin = dll.getFirst();
        int item = 0;
        item = pOrigin->obj;
        int size = DoublyLinkedListLength(dll);
        for (int i = 0; i < size; ++i) {
            this->insertFirst(item);
            pOrigin = pOrigin->next;
            item = pOrigin->obj;
        }
    }

}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
    // Delete the whole list
    /* Complete this function */
    int size = DoublyLinkedListLength(*this);
    DListNode *p = this->getFirst()->next;
    for (int i = 0; i < size; ++i) {
        p->prev = &header;
        delete this->getFirst();
        header.next = p;
    }

    if (dll.isEmpty()) {
        
    }
    else {
        DListNode *pOrigin = dll.getFirst();
        int item = 0;
        item = pOrigin->obj;
        size = DoublyLinkedListLength(dll);
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
void DoublyLinkedList::insertFirst(int newobj)
{ 
    /* Complete this function */

    DListNode *tempNode = new DListNode(newobj, &header, header.next);
    // cout << (*tempNode).obj;
    header.next->prev = tempNode;
    header.next = tempNode;
    // cout << header.next->obj;
    // trailer.prev = tempNode.next;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
    /* Complete this function */
    DListNode *tempNode = new DListNode(newobj, trailer.prev, &trailer);
    trailer.prev->next = tempNode;
    trailer.prev = tempNode;
}

// remove the first object from the list
int DoublyLinkedList::removeFirst()
{ 
    /* Complete this function */
    int temp; 
    DListNode *newFirst = this->getFirst()->next;
    newFirst->prev = &header;
    temp = this->getFirst()->obj;
    delete this->getFirst();
    header.next = newFirst;
    return temp;
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
    /* Complete this function */
    int temp; 
    DListNode *newLast = this->getAfterLast()->prev->prev;
    newLast->next = &trailer;
    temp = this->getAfterLast()->prev->obj;
    delete trailer.prev;
    trailer.prev = newLast;
    return temp;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    /* Complete this function */
    for (int i = 0; i < DoublyLinkedListLength(*this); ++i) {
        removeFirst();
    }

}

// return the first object
int DoublyLinkedList::first() const
{ 
    /* Complete this function */
    int firstInt = header.next->obj;
    return firstInt;
}

// return the last object
int DoublyLinkedList::last() const
{
    /* Complete this function */

    return trailer.prev->obj;
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(DListNode &p, int newobj)
{
    /* Complete this function */
    DListNode *newNode = new DListNode(newobj, &p, p.next);
    p.next->prev = newNode;
    p.next = newNode;
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(DListNode &p, int newobj)
{
    /* Complete this function */
    // debug
    // cout << "p.obj: " << p.obj << endl;
    // cout << "p.prev->obj: " << p.prev->obj << endl;
    // cout << "p.next->obj: " << p.next->obj << endl;
    DListNode *newNode = new DListNode(newobj, p.prev, &p);
    // debug
    // cout << "nN->prev->obj: " << newNode->prev->obj << endl;
    // cout << "nN->next->obj: " << newNode->next->obj << endl;
    p.prev->next = newNode;
    p.prev = newNode;
}

// remove the node after the node p
void DoublyLinkedList::removeAfter(DListNode &p)
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
        DListNode *deleteMe = p.next;
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
void DoublyLinkedList::removeBefore(DListNode &p)
{
    /* Complete this function */
    // cout << "obj: " << this->getFirst()->prev << endl;
    // cout << "p.prev: " << p.prev << endl;
    DListNode *deleteMe = p.prev;
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
int DoublyLinkedListLength(const DoublyLinkedList& dll)
{
    /* Complete this function */
    int i = 0;
    DListNode *p = dll.getFirst();
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
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
    
    /* Complete this function */
    
    int i = 0;
    if (dll.isEmpty()) {
        out << "List is empty, cannot put to ostream";
        return out;
    }
    DListNode *p = dll.getFirst();
    while (p != dll.getAfterLast()->prev) {
        // out << "i: " << i << "\t" << p << endl;
        // out << "\tcontents: " << p->obj << endl;
        out << p->obj << " ";
        p = p->next;
        ++i;
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

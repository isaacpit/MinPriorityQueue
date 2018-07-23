// Isaac Pitblado
// UIN: 524009756
// CSCE 221-512
// Programming Assignment 3
// 7 March 2018

#include "TemplateDoublyLinkedList.h"

template <typename T>
class TemplateMinQueue : public TemplateLinkedList<T> {
public: 
  void enqueue(T obj) { TemplateLinkedList<T>::insertLast(obj); }
  T dequeue();
  int size() { TemplateLinkedListLength(*this); }
  bool isEmpty() { TemplateLinkedList<T>::isEmpty(); }
  T min(); 
  
};

template<typename T>
T TemplateMinQueue<T>::dequeue() {
  T temp = {};
  temp = TemplateLinkedList<T>::first();
  TemplateLinkedList<T>::removeFirst();
  return temp;
}

template<typename T>
T TemplateMinQueue<T>::min() {
    T min = TemplateLinkedList<T>::first();
    DListNode<T> *p = TemplateLinkedList<T>::getFirst();
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
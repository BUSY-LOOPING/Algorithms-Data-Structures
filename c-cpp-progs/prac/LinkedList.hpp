#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>
#include <string> 
#include <cstring> 
#include <bits/stdc++.h> 
 
 
using namespace std; 
 
 
template <class T> 
class Node 
{ 
public: 
  T data; 
  Node<T> *next; 
}; 
 
 
template <class T> 
void print(Node<T> *head) 
{
  Node<T> *temp = new Node<T>();
  temp = head; 
 
 
  while (temp != nullptr) 
  { 
    cout << temp->data << endl; 
    temp = temp->next; 
  } 
} 
 
 
template <class T> 
class LinkedList 
{ 
private: 
  Node<T> *head; 
  int size; 
 
 
public: 
  LinkedList<T>(); 
  LinkedList<T>(const LinkedList<T> &newlist); 
  void insert(T data); 
  void insertionSort();
  void print(); 
  int getSize(); 
  LinkedList<T> getCommonList(LinkedList<T> B); 
  LinkedList<T> getIntersectionList(LinkedList<T> B); 
  bool contains(T data); 
  LinkedList<T> combine(const LinkedList<T> B); 
}; 
 
 
class MyIndexOutOfBoundsException : public exception 
{ 
private: 
  int index; 
  int size; 
 
 
public: 
  MyIndexOutOfBoundsException(int index, int size) 
  { 
    this->index = index; 
    this->size = size; 
  } 
  const char *what() const throw() 
  { 
    return "Index out of bound exception."; 
  } 
}; 
 
 
template <class T> 
LinkedList<T>::LinkedList() 
{ 
  head = nullptr; 
  size = 0; 
} 
 
 
template <class T> 
LinkedList<T>::LinkedList(const LinkedList<T> &newlist) 
{ 
  this->size = newlist.size; 
  this->head = newlist.head; 
} 
 
 
// template <class T> 
// void LinkedList<T>::insert(T data) 
// { 
//   size++; 
//   Node<T> *temp = new Node<T>(); 
//   temp->data = data; 
//   if (head == nullptr) 
//   { 
//     head = temp; 
//   } 
//   else 
//   { 
//     Node<T> *current = new Node<T>(); 
//     current = head; 
//     while (current != nullptr) 
//     { 
//       if (current->next == nullptr) 
//       { 
//         current->next = temp; 
//         break; 
//       } 
//       current = current->next; 
//     } 
//   } 
//   temp->next = nullptr; 
// } 
 
template <class T> 
void LinkedList<T>::insert(T data) {
    size++;
    Node<T>* temp = new Node<T>();
    temp -> data = data;
    temp -> next = nullptr;
    if (head == nullptr) {
        head = temp;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current -> next = temp;
    }
}

template <class T> 
void LinkedList<T>:: insertionSort() {
    if (head != nullptr) {
        Node<T>* current = head;
        Node<T>* prev = new Node<T>();
        prev -> next = current;
        while (current) {
            if (current -> next && (current -> next -> data < current -> data)) {
                //Insertion 
                while (prev -> next && (prev -> next -> data < current -> next -> data)) {
                    prev = prev -> next;
                }
                Node<T>* temp = current -> next;
                prev -> next = current -> next;
                current -> next = current -> next -> next;
                prev -> next -> next = temp;
                prev = head;
            } else {
                current = current->next;
            }
        }
    }
} 
 
template <class T> 
void LinkedList<T>::print() 
{ 
  ::print(head); //:: means look in global scope 
} 
 
 
template <class T> 
int LinkedList<T>::getSize() 
{ 
  return size; 
} 
 
 
template <class T> 
LinkedList<T> LinkedList<T>::getCommonList(LinkedList<T> B) 
{ 
  LinkedList<T> C; 
  Node<T> *temp = head; 
 
 
  while (temp != nullptr) 
  { 
    Node<T> *temp2 = B.head; 
    while (temp2 != nullptr) 
    { 
      if (temp->data == temp2->data) 
      { 
        if (!C.contains(temp->data)) 
        { 
          C.insert(temp->data); 
        } 
      } 
      temp2 = temp2->next; 
    } 
 
 
    temp = temp->next; 
  } 
 
 
  return C; 
} 
 
 
template <class T> 
LinkedList<T> LinkedList<T>::getIntersectionList(LinkedList<T> B) { 
  LinkedList<T> D; 
  if (size > B.size) { 
    D = *this; 
    Node<T> * temp = B.head; 
    while (temp != nullptr) { 
      if (!D.contains(temp->data)) { 
        D.insert(temp->data); 
      } 
      temp = temp->next; 
    } 
  } else { 
    D = B; 
    Node<T> * temp = head; 
    while (temp != nullptr) { 
      if (!D.contains(temp->data)) { 
        D.insert(temp->data); 
      } 
      temp = temp->next; 
    } 
  } 
  return D; 
} 
 
 
template <class T> 
bool LinkedList<T> :: contains(T data) 
{ 
  Node<T> *temp = new Node<T>(); 
  temp = head; 
  while (temp != nullptr) 
  { 
    if (temp->data == data) 
    { 
      return true; 
    } 
    temp = temp->next; 
  } 
  return false; 
}
 
template <class T> 
LinkedList<T> LinkedList<T> :: combine(const LinkedList<T> list) { 
  LinkedList<T> result; 
  int current = 0; 
  Node<T>* temp1 = head; 
  Node<T>* temp2 = list.head; 
  while (current < size + list.size) { 
    if ((current % 2) == 0) { 
      result.insert(temp1 -> data); 
      temp1 = temp1->next; 
    } else { 
      result.insert(temp2 -> data); 
      temp2 = temp2->next; 
    } 
    current++; 
  } 
 
 
  return result; 
}

#endif
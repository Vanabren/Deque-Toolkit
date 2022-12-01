/**
 * @file deque.h
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-11-29
 * @brief Header file for Deque class
 * 
 * Declaration of Deque methods and members
 */

#ifndef DEQUE_H
#define DEQUE_H

struct Index;

class Deque {
 private:
  int** blockmap; // pointer to map of arrays
  int size; // How many entries in Deque
  int mapSize; // How many rows in blockMap / data blocks
  int elementsPerBlock; // How many elements per data block
  int first_block; // location where data starts
  int first_element; // index of where first element is in deque
  void resize();
  Index findIndex(int element);
  
 public:
  Deque();
  ~Deque();
  void push_front(int value);
  int pop_front();
  void push_back(int value);
  int pop_back();
  int front();
  int back();
  bool isEmpty();
  int getSize();
  int& operator[](int indexOne);
};  
  

#endif //DEQUE_H

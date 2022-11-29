/**
 * @file deque.h
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-11-29
 * @brief Header file for Deque class
 * 
 * Declaration of Deque methods and members
 */

class Deque {
 private:
  int** blockmap;
  int size;

 public:
  Deque();
  ~Deque();
  void push_front(int value);
  int pop_front();
  int front();
  int back();
  bool isEmpty();
  int size();
};  
  

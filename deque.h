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
  int size; // How many entries in Deque
  int mapSize; // How many rows per block of data
  const static int blockSize;
  int first_block; // location where data starts
  int first_element; // index of where first element is in deque
  

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
  

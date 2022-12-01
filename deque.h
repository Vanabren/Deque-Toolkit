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
  int** blockmap; // pointer to map of arrays
  int size; // How many entries in Deque
  int mapSize; // How many rows in blockMap / data blocks
  int elementsPerBlock; // How many elements per data block
  const static int blockSize;
  int first_block; // location where data starts
  int first_element; // index of where first element is in deque
  void resize();
  struct index {
    int row; // datablock number in blockmap
    int col; // which column the element we want is on
  };
  
  index findIndex(int element);
  

 public:
  Deque();
  ~Deque();
  void push_front(int value);
  int pop_front();
  int front();
  int back();
  bool isEmpty();
  int size();
  int& operator[](unsigned int indexOne);
};  
  

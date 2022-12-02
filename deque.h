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

/**
 * Resizes Deque to twice its initial size
 *
 * @return Nothing - Resizes Deque to twice its initial size
 * @post Deque has been expanded and the first_block and first_element value set in the middle
 * 
 */
  void resize();

/**
 * Returns a struct of (row, col) pointing to a searched for element.
 *
 * @param int element Index to be searched for
 * @return Index Struct containing (row, col) of searched for Index is returned
 * 
 */
  Index findIndex(int element);
  
 public:

/**
 * Default constructor for Deque object.
 *
 * @post Object of Deque type is created and ready for use
 * 
 */
  Deque();

/**
 * Destructor for Deque object
 *
 * @pre Deque goes out of scope or is called by delete[]
 * @post Memory used by Deque object is freed
 * 
 */
  ~Deque();

/**
 * Pushes an argued value to front of Deque
 *
 * @param int value Value to be pushed into front of Deque
 * @return Nothing - New element is added to Deque
 * @post Size is incremented and first_element and potentially first_block changed
 * 
 */
  void push_front(int value);

/**
 * Pops front (first_element) of Deque and returns its value. 
 *
 * @return int Returns popped value from Deque
 * @post Size decreases by one and first_element and first_block may be changed
 * 
 */
  int pop_front();

/**
 * Pushes argued value to back of Deque
 *
 * @param int value Value to be pushed to back of Deque
 * @return Nothing - Element is added to Deque
 * @post Size increases by one
 * 
 */
  void push_back(int value);

/**
 * Last element of Deque is popped and returned
 *
 * @return int Returns popped value of Deque
 * @post Size is decreased by one
 * 
 */
  int pop_back();

/**
 * Looks at first element in Deque and returns value
 *
 * @return int Returns first value in Deque 
 * @post Nothing changes
 * 
 */
  int front();

/**
 * Looks at last element in Deque and returns value
 *
 * @return int Returns last value in Deque
 * @post Nothing changes
 * 
 */
  int back();

/**
 * Returns True if Deque is empty, False if at least one element is present in Deque
 *
 * @return bool Returns True if Deque is empty, False if at least one element is present in Deque
 * 
 */
  bool isEmpty();

/**
 * Returns size of Deque. Useful for looping through Deque
 *
 * @return int Number of elements present in Deque
 * 
 */
  int getSize();

/**
 * Overloaded [] operators for accessing an element at a certain index. Returns last element in array if index is too big, or -1 if no elements present
 *
 * @param int indexOne Index whose value is to be accessed and returned
 * @return int& Returns value of argued index
 * 
 */
  int& operator[](int indexOne);
};  
  

#endif //DEQUE_H

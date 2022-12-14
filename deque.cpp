/**
 * @file deque.cpp
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-11-29
 * @brief Code file for Deque class
 * 
 * Implementation of Deque's methods and members
 */

#include "deque.h"
#include <iostream>

using namespace std;

Deque::Deque() {
  size = 0; // num elements in array
  mapSize = 3; // initial size of the blockmap array
  elementsPerBlock = 8;
  blockmap = new int*[mapSize];
  for(int i = 0; i < mapSize; i++) {
    blockmap[i] = new int[elementsPerBlock];
  }
  first_block = 1; // index of the first to-be occupied array in blockmap
  first_element = 0; // index of the first to-be occupied position in the first block
}

Deque::~Deque() {
  // delete all arrays in blockmap
  for(int i = 0; i < mapSize; i++) {
    delete[] blockmap[i];
  }
  // delete blockmap array itself
  delete[] blockmap;
}

struct Index {
  int row;
  int col;
};

void Deque::resize() { // doubles mapblock size
  // create new resized() array
  int** expandedMap = new int*[2 * mapSize];
  // set each array pointer in the new map to a point in memory
  for(int i = 0; i < (2 * mapSize); i++) {
    expandedMap[i] = new int[elementsPerBlock];
  }
  // Copy original array to middle of new resized array
  copy(blockmap + first_block, blockmap + mapSize, expandedMap + (mapSize / 2));

  /*
  // delete old blockmap (and its internal array pointers) to prevent memory leaks
  for(int i = 0; i < mapSize; i++) {
    delete[] blockmap[i];
  }
  */
  delete[] blockmap;
  

  // Point blockmap to new array pointer and adjust variables
  blockmap = expandedMap;
  first_block = mapSize / 2;
  mapSize = mapSize * 2;
}

Index Deque::findIndex(int element) { // for use in [] overload
  Index ix;
  
  ix.row = first_block;
  if(element < elementsPerBlock - first_element) {
    ix.col = element + first_element;
  }
  else {
    element -= (elementsPerBlock - first_element);
    ix.row++;
    int x = element / elementsPerBlock;
    ix.row += x;
    ix.col = element - (x * elementsPerBlock);
  }

  return ix;
}

void Deque::push_front(int value) {
  if(size == (elementsPerBlock * mapSize)) {
    resize();
  }
  if(first_element == 0 && first_block == 0) {
    resize();
  }
  if(isEmpty()) { // empty deque so add first element
    blockmap[first_block][first_element] = value;
  }
  else if(first_element > 0) { // shouldn't be anything behind first element
    blockmap[first_block][first_element - 1] = value;
    first_element -= 1;
  }
  else { // first_element is at 0, so need to back up to a previous datablock
    first_element = 7; // final position in a previous datablock
    first_block -= 1; // go back one datablock
    blockmap[first_block][first_element] = value;
  }  
  
  size++;  
}

int Deque::pop_front() {
  if(isEmpty())
    return -1;
  
  int front = blockmap[first_block][first_element];
  blockmap[first_block][first_element] = -1;
  
  if(first_element < 7) { // just move element up one
    first_element++;
  }
  else { // f_e is 7 (last ele in block) so move forward a block and set f_e to 0
    first_block++;
    first_element = 0;
  }
  
  size--;
  return front;
}

int Deque::front() {
  return blockmap[first_block][first_element];
}

void Deque::push_back(int value) {
  if(size == (elementsPerBlock * mapSize)) { // safety catch in-case deque becomes full
    resize();
  }
  
  if(isEmpty()) { // empty deque so set to first element
    blockmap[first_block][first_element] = value;
    size++;
    return;
  }
  
  Index last = findIndex(size - 1); // gets index of last element in deque (so something exists there)
  // safety catch just-in-case we're at end of Deque
  if(mapSize - 1 == last.row && last.col == 7) { 
    resize();
  }
  
  if(last.col < 7) { // last element in data block isn't filled
    blockmap[last.row][last.col + 1] = value;
    size++;
  }
  else { // last element in data block is filled, so forward another block
    blockmap[last.row + 1][0] = value;
    size++;
  }
}

int Deque::pop_back() {
  if(isEmpty()) // return -1 cause empty
    return -1;
  
  Index last = findIndex(size - 1); // find index of last element in deque
  
  int lastE = blockmap[last.row][last.col]; // grab element data
  
  blockmap[last.row][last.col] = -1; // set element to -1 just-in-case
  
  size--;
  return lastE;
}

int Deque::back() {
  Index ix = findIndex(size - 1);
  return blockmap[ix.row][ix.col];
}

bool Deque::isEmpty() {
  if(size == 0)
    return true;
  else
    return false;
}

int Deque::getSize() {
  return size;
}

int& Deque::operator[](int i) { 
  Index ix;
  // if size == 0, cannot return local variable so set unused first element to -1 and return
  // shouldn't cause problems because size isn't incrememented, and push_x() functions still work as intended
  if(size == 0) { 
    blockmap[first_block][first_element] = -1;
    return blockmap[first_block][first_element];
  }
  if(i > size) {// i is too big for the amount of elements in it, so return last element
    ix = findIndex(size - 1);
    return blockmap[ix.row][ix.col];
  }
  
  ix = findIndex(i);
  return blockmap[ix.row][ix.col]; // returns element at index i
}

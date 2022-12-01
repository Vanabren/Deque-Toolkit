/**
 * @file deque.cpp
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-11-29
 * @brief Code file for Deque class
 * 
 * Implementation of Deque's methods and members
 */

#include "Deque.h"
#include <iostream>

using namespace std;

Deque::Deque() {
  size = 0; // num elements in array
  mapSize = 1; // initial size of the blockmap array
  blockmap = new int*[mapSize];
  elementsPerBlock = 8;
  blockSize = 4096; 
  first_block = 0; // index of the first occupied array in blockmap
  first_element = 0; // index of the first occupied position in the first block
  index.row = 0; // for use in findIndex()
  index.col = 0; // for use in findIndex()
}

Deque::~Deque() {
  for(int i = 0; i < mapSize; i++) {
    delete[] blockmap[i];
  }
  delete[] blockmap;
  numBlocks = 0;
  size = 0;
  first_block = 0;
  first_element = 0;
}

void Deque::resize() { // doubles mapblock size
  int** expandedMap = new int*[2 * mapSize];
  
  copy(blockmap + first_block, blockmap + mapSize, expandedMap + (mapSize / 2));
  delete[] blockmap;
  blockmap = expandedMap;
  firstBlock = mapSize / 2;
  mapSize = mapSize * 2;
}

index Deque::findIndex(int element) { // for use in [] overload
  index ix;
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
  if(size == 0) { // empty deque so add first element
    blockmap[first_block][first_element] = value;
  }
  else if(first_element != 0) { // shouldn't be anything behind first element
    blockmap[first_block][first_element - 1] = value;
    first_element -= 1;
  }
  else { // need to back up to a previous datablock
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
  
  if(first_element < 7) { // just move element up one
    first_element++;
  }
  else { // f_e is 7 (last ele in block) so move forward a block and set f_e to 0
    first_block++;
    first_element = 0;
  }

  return front;
}

int Deque::front() {
  return blockmap[first_block][first_element];
}

int Deque::back() {
  index ix = findIndex(size - 1);
  return blockmap[ix.row][ix.col];
}

bool Deque::isEmpty() {
  if(size == 0)
    return true;
  else
    return false;
}

int Deque::size() {
  return size;
}

int& Deque::operator[](int i) {
  index ix = findIndex(i);
  return blockmap[ix.row][ix.col];
}

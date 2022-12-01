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
  mapSize = 8; // size of the blockmap array
  blockmap = new int*[mapSize];
  elementsPerBlock = 8;
  blockSize = 4096; 
  first_block = 0; // index of the first occupied array in blockmap
  first_element = 0; // index of the first occupied position in the first block
  index.row = 0;
  index.col = 0;
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
  
  for(int i = 0; i < mapSize * 2; i++) {
    for(int j = 0; j < elementsPerBlock; j++) {
      expandedMap[i][j] = blockmap[i][j];
    }
  }
  delete[] blockmap;
  blockmap = expandedMap;
  firstBlock = mapSize / 2; // not sure if this will work
  mapSize = mapSize * 2;
}

index Deque::findIndex(int element) {
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
  if(blockmap == nullptr)
    resize();
  if(size == (elementsPerBlock * mapSize)
     resize();
}

int Deque::pop_front() {

}

int Deque::front() {
  if(blockmap == nullptr)
    return 0;
  return blockmap[first_block][first_element];
}

int Deque::back() {
  if(blockmap == nullptr)
    return 0;
  index ix = findIndex(size - 1);
  return blockmap[ix.row][ix.col];
}

bool Deque::isEmpty() {
  if(blockmap == nullptr)
    return true;
  if(size == 0)
    return true;
  else
    return false;
}

int Deque::size() {
  return size;
}

int& Deque::operator[](int i) {
  if(blockmap == nullptr)
    return 0;
  index ix = findIndex(i);
  return blockmap[ix.row][ix.col];
}

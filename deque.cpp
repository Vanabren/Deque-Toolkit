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
  blockmap = nullptr; // new int*[numBlocks];
  size = 0; // num elements in array
  mapSize = 8; // size of the blockmap array
  elementsPerBlock = 8;
  blockSize = 4096; 
  first_block = 0; // index of the first occupied array in blockmap
  first_element = 0; // index of the first occupied position in the first block
  index.row = 0;
  index.col = 0;
}

Deque::~Deque() {
  for(int i = 0; i < mapSize; i++) {
    delete[] mapSize[i];
  }
  delete[] blockmap;
  numBlocks = 0;
  size = 0;
  first_block = 0;
  first_element = 0;
}

void Deque::resize() { // doubles mapblock size
  
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

}

int Deque::pop_front() {

}

int Deque::front() {
  if(blockmap == nullptr)
    return 0;
  return blockmap[first_block][first_element];
}

int Deque::back() {
  
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
  index ix = findIndex(i);
  return blockmap[ix.row][ix.col];
}

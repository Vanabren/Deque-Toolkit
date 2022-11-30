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
}

Deque::~Deque() {
  for(int i = 0; i < numBlocks; i++) {
    delete[] blockmap[i];
  }
  delete[] blockmap;
  numBlocks = 0;
  size = 0;
  first_block = 0;
  first_element = 0;
}

void Deque::push_front(int value) {

}

int Deque::pop_front() {

}

int Deque::front() {

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

int& Deque::operator[](unsigned int index) {
  int row = first_block + (first_element + index) / blockSize;
  int col = 0;
}

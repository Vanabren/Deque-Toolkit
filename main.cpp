/**
 * @file main.cpp
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-11-29
 * @brief Driver for Deque class
 * 
 * Runs a series of tests on the Deque class to properly ensure functionality
 */


#include <iostream>
#include <string>
#include "deque.h"

using namespace std;

// Coordinated Tests
void regPushFront(Deque &d, int value);
void regPushBack(Deque &d, int value);
void regPopFront(Deque &d);
void regPopBack(Deque &d);
void accessFront(Deque &d);
void accessBack(Deque &d);

// Stress-Test Tests
void thousandPushFront(Deque &d);
void thousandPushBack(Deque &d);
void thousandPopFront(Deque &d);
void thousandPopBack(Deque &d);
void hundredPushFront(Deque &d);
void hundredPushBack(Deque &d);
void hundredPopFront(Deque &d);
void hundredPopBack(Deque &d);

void accessorTest(Deque &d);

void stressTest();
void coordTest();

int main() {
  // stressTest(); // commented out initially for readability
  coordTest();
  
  return 0;
}

void stressTest() {
  /*  Deque d;
  cout << "Stress tests begin: \n\n";
  // Stress tests
  thousandPushFront(d); // push a bunch from the front
  accessorTest(d); // access a bunch
  thousandPopFront(d); // pop a bunch from the front
  accessFront(d);
  accessBack(d);
  // empty
  thousandPopBack(d); // try to pop nonexistent elements (should return only -1s)
  hundredPushBack(d);
  thousandPopFront(d); // should return 100 - 0, then -1s for the last 900
  // empty
  thousandPushBack(d); // push a bunch of elements
  thousandPopBack(d); // pop all added elements
  accessorTest(d); // try to access deleted elements (should return only -1s)
  */
  cout << "\nStress tests over... \n\n";
}

void coordTest() {
  Deque d;
  cout << "Coordinated tests begin: \n\n";
  // Tests
  regPopFront(d);
  regPushFront(d, 3);
  regPopBack(d);
}

void regPushFront(Deque &d, int value) {
  cout << "Pushing " << value << " to the front:" << endl;
  d.push_front(value);
  cout << endl;
}

void regPushBack(Deque &d, int value) {
  cout << "Pushing " << value << " to the back:" << endl;
  d.push_back(value);
  cout << endl;
}
void regPopFront(Deque &d) {
  cout << "Pop Front: " << d.pop_front() << endl;
}

void regPopBack(Deque &d) {
  cout << "Pop Back: " << d.pop_back() << endl;
}

void accessFront(Deque &d) {
  cout << "Access Front: " << d.front() << endl;
}

void accessBack(Deque &d) {
  cout << "Access Back: " << d.back() << endl;
}

void thousandPushFront(Deque &d) {
  return;
}

void thousandPushBack(Deque &d) {
  return;
}

void thousandPopFront(Deque &d) {
  return;
}

void thousandPopBack(Deque &d) {
  return;
}

void hundredPushFront(Deque &d) {
  return;
}

void hundredPushBack(Deque &d) {
  return;
}

void hundredPopFront(Deque &d) {
  return;
}

void hundredPopBack(Deque &d) {
  return;
}

void accessorTest(Deque &d, int index) {
  cout << "Accessing [" << index << "]: " << d[index] << endl;
}

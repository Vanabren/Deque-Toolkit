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

/**
 * Pushes specified value to front of Deque
 *
 * @param Deque &d Deque to push value to front of
 * @param int value Value to push into array
 * 
 */
void regPushFront(Deque &d, int value);

/**
 * Pushes specified value to back of Deque
 *
 * @param Deque &d Deque to push value to back of
 * @param int value Value to be pushed into Deque 
 * 
 */
void regPushBack(Deque &d, int value);

/**
 * Pops front element of Deque and prints to screen
 *
 * @param Deque &d Deque to be popped from
 * 
 */
void regPopFront(Deque &d);

/**
 * Pops back element of Deque and prints to screen
 *
 * @param Deque &d Deque to be popped from
 * 
 */
void regPopBack(Deque &d);

/**
 * Used front() method to print first element in Deque to console
 *
 * @param Deque &d Deque to check front of
 * 
 */
void accessFront(Deque &d);

/**
 * Uses back() method to print last element in Deque to console
 *
 * @param Deque &d Deque to check back of
 * 
 */
void accessBack(Deque &d);

/**
 * Pushes thousand elements to front of Deque (0 - 999) and prints only first and last push
 *
 * @param Deque &d Deque to push a thousand elements into
 * 
 */
void thousandPushFront(Deque &d);

/**
 * Pushes thousand elements to back of Deque (0 - 999) and prints only first and last push
 *
 * @param Deque &d Deque to push a thousand elements into
 * 
 */
void thousandPushBack(Deque &d);

/**
 * Pops a thousand elements from the front of the Deque and prints each pop to console
 *
 * @param Deque &d Deque to pop a thousand elements from
 * 
 */
void thousandPopFront(Deque &d);

/**
 * Pops a thousand elements from the back of the Deque and prints each pop to console
 *
 * @param Deque &d Deque to pop a thousand elements from
 * 
 */
void thousandPopBack(Deque &d);

/**
 * Pushes a hundred elements (0 - 99) to front of Deque and prints each push
 *
 * @param Deque &d Deque to push a hundred elements into
 * 
 */
void hundredPushFront(Deque &d);

/**
 * Pushes a hundred elements (0 - 99) to back of Deque and prints each push
 *
 * @param Deque &d Deque to push a hundred elements into
 * 
 */
void hundredPushBack(Deque &d);

/**
 * Pops a hundred elements from front of Deque and prints each pop to console
 *
 * @param Deque &d Deque to pop a hundred elements from
 * 
 */
void hundredPopFront(Deque &d);

/**
 * Pops a hundred elements from back of Deque and prints each pop to console
 *
 * @param Deque &d Deque to pop a hundred elements from
 * 
 */
void hundredPopBack(Deque &d);

/**
 * Tests Deque [] functionality by returning and printing index's value to console
 *
 * @param Deque &d Deque to access from
 * @param int index Index of element User wants returned
 * 
 */
void accessorTest(Deque &d, int index);


/**
 * Runs a series of tests ranging from coordinated single pushes and pops to hundreds/thousands of pushes and pops
 *
 * @return void Prints lots of results from tests to screen. Will cause clutter.
 * 
 */
void coordTest();

int main() {
   coordTest();
  
  return 0;
}

void coordTest() {
  Deque d;
  cout << "Coordinated tests begin: \n\n";
  
  // Simple Tests (for Precision)

  regPopFront(d); // -1
  regPushFront(d, 3); // [3]
  regPushBack(d, 9); // [3][9]
  regPopFront(d); // 3
  regPushBack(d, 5); // [9][5]
  regPopFront(d); // 9
  regPushFront(d, 6); //[6][5]
  accessFront(d); // 6
  accessBack(d); // 5
  regPopFront(d); // 6
  regPopBack(d); // 5
  
  // Stress Tests (for resizing())
  
  hundredPushFront(d); // 100 in (100 remaining)
  hundredPopFront(d); // 100 out (0 remaining)
  hundredPushBack(d); // 100 in (100 remaining)
  hundredPopBack(d);  // 100 out (0 remaining)
  
  thousandPushFront(d);
  thousandPushBack(d);
  thousandPushFront(d);
  thousandPushBack(d); // 4,000 elements added
  accessFront(d); // 1000
  accessBack(d); // 1000
  thousandPopBack(d); // 3000 er
  thousandPopBack(d); // 2000 er
  thousandPopFront(d); // 1000 er
  thousandPopFront(d); // 0 er
  regPopFront(d); // -1
  regPopBack(d); // -1
  accessFront(d); // -1
  accessBack(d); // -1

  Deque ac; // new deque for continued resizing tests
  hundredPushFront(d);
  for(int i = 0; i < d.getSize(); i += 2) {
    accessorTest(d, i);
  }
}

void regPushFront(Deque &d, int value) {
  cout << "Pushing " << value << " to the front:" << endl;
  d.push_front(value);
}

void regPushBack(Deque &d, int value) {
  cout << "Pushing " << value << " to the back:" << endl;
  d.push_back(value);
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
  cout << endl;
  for(int i = 0; i < 1000; i++) {
    if(i == 0 || i == 999) 
      cout << "Pushing Thousand Front (i): " << i << endl;
    d.push_front(i);
  }
}

void thousandPushBack(Deque &d) {
  cout << endl;
  for(int i = 0; i < 1000; i++) {
    if(i == 0 || i == 999)
      cout << "Pushing Thousand Back (i): " << i << endl;
    d.push_back(i);
  }
}

void thousandPopFront(Deque &d) {
  for(int i = 0; i < 1000; i++) {
    cout << "Popping Thousand Front (i): " << d.pop_front() << endl;
  }
}

void thousandPopBack(Deque &d) {
  for(int i = 0; i < 1000; i++) {
    cout << "Pop Thousand Back (i): " << d.pop_back() << endl;
  }
}

void hundredPushFront(Deque &d) {
  cout << endl;
  for(int i = 0; i < 100; i++) {
    cout << "Pushing Hundred (i): " << i << endl;
    d.push_front(i);
  }
}

void hundredPushBack(Deque &d) {
  for(int i = 0; i < 100; i++) {
    cout << "Pushing Hundred Back (i): " << i << endl;
    d.push_back(i);
  }
}

void hundredPopFront(Deque &d) {
  for(int i = 0; i < 100; i++) {
    cout << "Pop Hundred Front (i): " << d.pop_front() << endl;
  }
}

void hundredPopBack(Deque &d) {
  for(int i = 0; i < 100; i++) {
    cout << "Popping Hundred Back (i): " << d.pop_back() << endl;
  }
}

void accessorTest(Deque &d, int index) {
  cout << "Accessing [" << index << "]: " << d[index] << endl;
}

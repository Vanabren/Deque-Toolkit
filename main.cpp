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
    cout << "Pushing Thousand Front (i): " << i << endl;
    d.push_front(i);
  }
}

void thousandPushBack(Deque &d) {
  cout << endl;
  for(int i = 0; i < 1000; i++) {
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

# Deque Toolkit:
### Required Files:
- deque.h/.cpp
  - The headerfile and implementation of the Deque class
- main.cpp
  - The driver for the automatic testing of the Deque class and its various methods
- Makefile
  - Utility used to compile Deque program from the source code listed above. Runs a series of tests without user input.
-------
### Compilation Instructions:
- To compile, just use the *make* command within the Linux terminal (or Ubuntu) from the working directory where you placed all the source files. Creates an executable called *deque*. 
-------
### How to Run the Program + Notes:
- Use the *deque* executable with ./deque
- The driver for the program repeatedly calls push() methods that are outputted to the screen each time they do it. This will cause a lot of screen clutter, so be warned. Also, every method is tested but some calls might be hidden among the output clutter. 
-------
# Member Functions (Public):
- (constructor) - Constructs Deque container
- (destructor) - Deque destructor

## Capacity:
- getSize() - Returns number of elements present in Deque
- isEmpty() - Bool that returns True if Deque is empty (0 size) or False otherwise

## Element Access:
- operator[] - Accesses element at selected index and returns value. 
  - If attempting to access out-of-bounds of Deque: 
   - Returns -1 if size == 0 (e.g. no elements present in Deque)
   - Returns last element in Deque (e.g. if even a single element in present in Deque)
- front() - Returns a copy of the element at the front of the Deque (first element)
- back() - Returns a copy of the element at the end of the deque (last element)

## Modifiers:
- push_front() - Adds element at the beginning of the Deque
- push_back() - Adds element at the end of the Deque
- pop_front() - Deletes and returns first element in Deque
- pop_back() - Deletes and returns last element in Deque
-------
# Design Decisions:
 - For the resize() method, I chose to double the size of the Deque each time which is inefficient if only pushing small amounts of elements in at a time, but for bulk data seems to work well. Every time a resize() takes place, the location of the first block and element is pointed to the middle of the newly-sized blockmap.
 
 - Added a struct named Index for use in finding the index of certain elements.
 
 - For the Bracket overload (e.g deque[i]), if "i" is too big for the amount of elements the Deque is sized to (or had present within it), a -1 is returned to the user by setting the first element to -1 and returning that (because it has to be the reference to an int within the Deque, not a local variable that is returned). This works fine because size is not incremented, and actual data will be mapped to that spot in memory when actually pushed.
    - Specifically: 
    - If there is at least one element present in the Deque, the last element in the Deque is returned when the index is too large. 
    - If no elements exist at all, *then* the first element is initialized to -1 and returned, but that data will be overwritten by actual data when data is pushed into the Deque, so existing data isn't accidentally overwritten to -1 during use.

- I didn't include a variable/pointer to keep track of the last element in the Deque as the getIndex() works fine for getting its location. The calculations don't loop or anything, so constant-time ( O(1) ) should still be present, though they may end up slightly slower than just returning a value from a helper variable.
-------
### Challenges: 
 - I got segmentation faults on the push_front(), push_back(), and resize() methods when starting testing that threw me for a loop for a few hours. However, I eventually discovered that my push_front() method had faulty bounds checking, my resize() function had an extra unnecessary delete[] thrown in that would cause a segmentation fault after a few resizes, and my push_back() method also had bounds checking issues that made it access a point in memory it shouldn't have had access to (I used this : [mapSize][first_element] instead of the correct version: [mapSize - 1][first_element]) After correcting them, the segmentation faults disappeared and I was able to push thousands of elements from front and back without issues.
 
 - Initially my Index struct was causing problems as well as it was declared (AND initialized) in the headerfile for the Deque class, but after moving the implementation to the Deque.cpp file, issues were resolved
 

//
//  DynamicArray.h
//
//  This file defines a Dynamic Array class.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef dynamicarray_hpp
#define dynamicarray_hpp

#include <algorithm>  // for copy(), min(), move_backward
                      // for assert()

#include "Collection.h"
#include "MemoryLeakDetector.h"

#define DEFAULT_CAPACITY 10

using namespace std;

namespace csi281 {
  template <typename T> class DynamicArray : public Collection<T> {
  public:
    // Initialize the dynamic array with a starting capacity
    DynamicArray(int cap = DEFAULT_CAPACITY) {
      capacity = cap;
      backingStore = new T[capacity];
    }

    // Erase the dynamic array
    ~DynamicArray() { delete[] backingStore; }

    // Find the index of a particular item
    // Return -1 if it is not found>
    int find(const T &item) {
      // YOUR CODE HERE
    }

    // Get the item at a particular index
    T &get(int index) {
      // YOUR CODE HERE
    }

    // Insert at the beginning of the collection
    // Using setCapacity() if we are too small before
    // inserting
    // Hint: May want to use moveDownFrom()
    void insertAtBeginning(const T &item) {
      // YOUR CODE HERE
    }

    // Insert at the end of the collection
    // Using setCapacity() if we are too small before
    // inserting
    void insertAtEnd(const T &item) {
      // YOUR CODE HERE
    }

    // Insert at a specific index
    // Using setCapacity() if we are too small before
    // inserting
    // Hint: May want to use moveDownFrom()
    void insert(const T &item, int index) {
      // YOUR CODE HERE
    }

    // Remove the item at the beginning of the collection
    void removeAtBeginning() {
      // YOUR CODE HERE
    }

    // Remove the item at the end of the collection
    // Hint: This might be very simple.
    void removeAtEnd() {
      // YOUR CODE HERE
    }

    // Remove the item at a specific index
    // Hint: Can be done by a combination of moving items
    // down and removing the starting beginning element
    void removeAt(int index) {
      // YOUR CODE HERE
    }

    // Change the capacity of the dynamic array
    // If it becomes less than count, just discard excess
    void setCapacity(int cap) {
      assert(cap >= 0);  // can't have negative capacity
      // don't do anything if we're already correct
      if (cap == capacity) {
        return;
      }

      int numberToCopy = min(cap, count);

      T *destination = new T[cap];

      copy(backingStore, backingStore + numberToCopy, destination);
      delete[] backingStore;
      backingStore = destination;
      capacity = cap;
      if (capacity < count) {
        count = capacity;
      }
    }

    // Return the current capacity
    int getCapacity() { return capacity; }

  protected:
    using Collection<T>::count;

  private:
    int capacity;
    int growthFactor = 2;
    T *backingStore;

    // Shift all of the items in backingStore starting at
    // index down by 1 place
    // Make sure you have capacity available to do this before
    // running this method
    void moveDownFrom(int index) {
      move_backward(backingStore + index, backingStore + count, backingStore + count + 1);
    }
  };

}  // namespace csi281

#endif /* dynamicarray_hpp */

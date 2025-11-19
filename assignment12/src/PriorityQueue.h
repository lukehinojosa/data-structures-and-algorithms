//
//  PriorityQueue.h
//
//  Defines a binary heap based priority queue class.
//  It is a max-heap.
//  You SHOULD modify this file.
//
//  IMPORTANT NOTE: For this particular assignment you may not add
//  any additional utility functions.
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

#ifndef pq_hpp
#define pq_hpp

#include <algorithm>  // for swap()
#include <iostream>
#include <random>
#include <vector>

#include "MemoryLeakDetector.h"

using namespace std;

// Convenience macros; Note that we are using -1, +1, and +2 as modifiers here
// versus the pseudocode in Introduction to Algorithms Chapter 6 to allow
// our heap to start at location 0
#define parent(i) ((i - 1) / 2)
#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)

namespace csi281 {

  template <typename T> class PriorityQueue {
  public:
    // What is the maximum value in the priority queue?
    // In other words, what is the next value that would be popped?
    // TIP: See pseudocode in Introduction to Algorithm Chapter 6 page 163
    // for HEAP-MAXIMUM()
    // NOTE: Our heap starts at 0, not 1
    T peek() {
      // In a max-heap, the largest element is always at the root (index 0).
      return heap[0];
    }

    // Remove the next element (max element) in the heap and return it
    // TIP: See pseudocode in Introduction to Algorithm Chapter 6 page 163
    // for HEAP-EXTRACT-MAX()
    // NOTE: Our heap starts at 0, not 1
    // NOTE: Do not worry about contracting the size of the backing vector
    // after a pop.
    T pop() {
      // The max element is at the root of the heap.
      T max = heap[0];
      // Move the last element in the heap to the root.
      heap[0] = heap[heapSize - 1];
      // Decrease the heap size.
      heapSize--;
      // Restore the max-heap property by running maxHeapify on the root.
      maxHeapify(0);
      // Return the original max element.
      return max;
    }

    // Put a new element into the priority queue
    // TIP: A combination of HEAP-INCREASE-KEY() and MAX-HEAP-INSERT()
    // in Intro to Algorithms Chapter 6; they set the last element to
    // -infinity; we will set our last element to *key*, and then float it up
    // as is done in HEAP-INCREASE-KEY()
    // NOTE: macro parent() is defined at the top of this file
    // NOTE: our last element is at heapSize after being push_back()ed onto
    // the end of the vector heap
    void push(T key) {
      // Place the new key at the end of the heap.
      // If the heap has grown to the capacity of the vector, expand the vector.
      // Otherwise, reuse the space at the end of the vector.
      if (heapSize == heap.size()) {
          heap.push_back(key);
      } else {
          heap[heapSize] = key;
      }
      // Increment the heap size.
      heapSize++;
      
      // Get the index of the new element.
      int i = heapSize - 1;
      
      // Move the new element up the heap to its correct position to maintain the max-heap property.
      // While the current node is not the root and is greater than its parent, swap it with its parent.
      while (i > 0 && heap[parent(i)] < heap[i]) {
          swap(heap[i], heap[parent(i)]);
          i = parent(i);
      }
    }

    // How many items are in the priority queue?
    int getCount() { return heapSize; }

    // A debut print ouf of the contents of the heap
    void debugPrint() {
      for (auto item : heap) {
        cout << item << " ";
      }
      cout << endl;
    }

  private:
    // Push down the element at *i* to maintain the max-heap property
    // TIP: See pseudocode in Introduction to Algorithm Chapter 6 page 154
    // NOTE: Macros left() and right() are defined at the top of this file
    void maxHeapify(int i) {
      // Get the indices of the left and right children.
      int l = left(i);
      int r = right(i);
      int largest = i;
      
      // Find the largest among the node and its children.
      // Check if the left child exists and is greater than the current largest.
      if (l < heapSize && heap[l] > heap[largest]) {
          largest = l;
      }
      
      // Check if the right child exists and is greater than the current largest.
      if (r < heapSize && heap[r] > heap[largest]) {
          largest = r;
      }
      
      // If the largest element is not the current node, swap them.
      if (largest != i) {
          swap(heap[i], heap[largest]);
          // Recursively call maxHeapify on the affected subtree.
          maxHeapify(largest);
      }
    }

    vector<T> heap;
    int heapSize = 0;
  };

}  // namespace csi281

#endif /* pq_hpp */

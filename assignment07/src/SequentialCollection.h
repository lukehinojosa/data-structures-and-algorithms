//
//  SequentialCollection.h
//
//  Defines the abstract base class for all sequential collections.
//  You should NOT modify this file.
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

#ifndef sequential_collections_hpp
#define sequential_collections_hpp

#include <iostream>
#include <list>

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  template <typename T> class SequentialCollection {
  public:
    // Put a new element in the collection
    virtual void push(const T &item) = 0;
    // Remove and return the next element from the collection
    virtual T pop() = 0;
    // Access the next element in the collection
    virtual T &peek() = 0;
    // Remove all ocurrences of *item* from the collection
    virtual void remove(const T &item) { backingStore.remove(item); };
    // Return the number of items in the collection
    int getCount() { return backingStore.size(); }
    // Debug print out the contents of the collection
    void debugPrint() {
      for (auto const &p : backingStore) {
        cout << " -> (" << p << ")";
      }
      cout << endl;
    }

  protected:
    list<T> backingStore = list<T>();
  };
}  // namespace csi281

#endif /* sequential_collections_hpp */

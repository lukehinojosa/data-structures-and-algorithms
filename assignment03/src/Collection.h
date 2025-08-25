//
//  Collection.h
//
//  Defines the base class for all collections.
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

#ifndef collections_hpp
#define collections_hpp

#include "MemoryLeakDetector.h"

namespace csi281 {

  template <typename T> class Collection {
  public:
    // Find the index of a particular item
    // Return -1 if it is not found
    virtual int find(const T &item) = 0;
    // Check if the collection contains item
    bool contains(const T &item) {
      if (find(item) != -1) {
        return true;
      }
      return false;
    }
    // Get the item at a particular index
    virtual T &get(int index) = 0;
    // Get an item at a particular index
    T &operator[](int index) { return get(index); }
    // Insert at the beginning of the collection
    virtual void insertAtBeginning(const T &item) = 0;
    // Insert at the end of the collection
    virtual void insertAtEnd(const T &item) = 0;
    // Insert at a specific index
    virtual void insert(const T &item, int index) = 0;
    // Remove the item at the beginning of the collection
    virtual void removeAtBeginning() = 0;
    // Remove the item at the end of the collection
    virtual void removeAtEnd() = 0;
    // Remove the item at a specific index
    virtual void removeAt(int index) = 0;
    // Remove a specific item
    void remove(const T &item) {
      int location = find(item);
      if (location != -1) {
        removeAt(location);
      }
    }
    // Return the number of items in the collection
    int getCount() { return count; }

  protected:
    int count = 0;
  };
}  // namespace csi281

#endif /* collections_hpp */

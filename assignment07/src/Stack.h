//
//  Stack.h
//
//  This file defines a Stack class.
//  You SHOULD modify this file.
//  You may not add any instance variables to this class.
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

#ifndef stack_hpp
#define stack_hpp

#include "SequentialCollection.h"
#include <stdexcept>

using namespace std;

namespace csi281 {
  template <typename T> class Stack : public SequentialCollection<T> {
  public:
    // In a stack, push to the back and pop from the back (LIFO)
    // Adds an item to the top of the stack.
    void push(const T &item) override {
        this->backingStore.push_back(item);
    }

    // Removes and returns the top item from the stack.
    T pop() override {
        // Throw an error if the stack is empty.
        if (this->backingStore.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        T item = this->backingStore.back();
        this->backingStore.pop_back();
        return item;
    }

    // Returns the top item from the stack without removing it.
    T &peek() override {
        // Throw an error if the stack is empty.
        if (this->backingStore.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return this->backingStore.back();
    }
  protected:
    using SequentialCollection<T>::backingStore;
  };
}  // namespace csi281

#endif /* stack_hpp */

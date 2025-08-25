//
//  timing.h
//
//  Tests the speed of PriorityQueue.pop() vs equivalent vector methods
//  You should NOT modify this file.
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

#ifndef timing_hpp
#define timing_hpp

#include <array>
#include <chrono>  // for microseconds
#include <random>
#include <vector>

#include "MemoryLeakDetector.h"
#include "PriorityQueue.h"

using namespace std;
using namespace std::chrono;

namespace csi281 {

  // Finds the speed of pop() vs equivalent vector methods
  static array<long long, 2> popSpeed(const int length) {
    // Generate Random Data Structures
    vector<int> testVector;
    PriorityQueue<int> pq = PriorityQueue<int>();

    // initialize random number generator in range min to max
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(0, length);

    // fill data structures with random data
    for (int i = 0; i < length; i++) {
      int num = uni(rng);
      testVector.push_back(num);
      pq.push(num);
    }

    // test vector speed
    using namespace std::chrono;
    auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    for (int i = 0; i < length; i++) {
      auto throwaway1 = max_element(begin(testVector), end(testVector));
      testVector.erase(throwaway1);
    }
    auto end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

    long long vectorTime = (end - start);

    // test pq speed
    start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    for (int i = 0; i < length; i++) {
      int throwaway2 = pq.pop();
    }
    end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

    long long pqTime = end - start;

    return {pqTime, vectorTime};
  }
}  // namespace csi281

#endif /* timing_hpp */

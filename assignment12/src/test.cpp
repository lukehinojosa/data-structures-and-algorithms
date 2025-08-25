//
//  test.cpp
//
//  Tests to prove your code works.
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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)
using doctest::Approx;

#include <algorithm>  // for equal(), sort(), copy()
#include <chrono>     // for microseconds
#include <iostream>
#include <iterator>  // for begin() and end()
#include <random>
#include <string>

#include "PriorityQueue.h"
#include "timing.h"

using namespace std;
using namespace csi281;

template <typename T, int length> void printArray(T (&a)[length]) {
  copy(begin(a), end(a), ostream_iterator<T>(cout, " "));
  cout << endl;
}

template <typename T> void printArray(T *a, int length) {
  copy(a, a + length, ostream_iterator<T>(cout, " "));
  cout << endl;
}

TEST_CASE("PriorityQueue<int> test", "[PriorityQueue<int>]") {
  // setup
  const int length = 11;
  int sampleIntArray1[length] = {23, -3, -2, 4, 11, 4, 7, 8, 0, 0, -3};

  PriorityQueue<int> pq = PriorityQueue<int>();

  for (auto i : sampleIntArray1) {
    pq.push(i);
  }
  pq.debugPrint();
  REQUIRE(pq.getCount() == length);
  REQUIRE(pq.peek() == *max_element(begin(sampleIntArray1), end(sampleIntArray1)));

  // sort in descending order
  sort(begin(sampleIntArray1), end(sampleIntArray1), greater<int>());

  // print both versions
  cout << endl;
  cout << "original array sorted" << endl;
  printArray(sampleIntArray1);

  cout << "popped contents of pq" << endl;
  for (auto i : sampleIntArray1) {
    auto poppedElement = pq.pop();
    cout << poppedElement << " ";
    REQUIRE(i == poppedElement);
  }
  cout << endl;
}

TEST_CASE("PriorityQueue<string> test", "[PriorityQueue<string>]") {
  // setup
  const int length = 12;
  string sampleStringArray1[length] = {"h", "a", "z", "j", "k", "b", "d", "r", "s", "l", "n", "m"};

  PriorityQueue<string> pq = PriorityQueue<string>();

  for (auto i : sampleStringArray1) {
    pq.push(i);
  }

  REQUIRE(pq.getCount() == length);
  REQUIRE(pq.peek() == *max_element(begin(sampleStringArray1), end(sampleStringArray1)));

  // sort in descending order
  sort(begin(sampleStringArray1), end(sampleStringArray1), greater<string>());

  // print both versions
  cout << endl;
  cout << "original array sorted" << endl;
  printArray(sampleStringArray1);

  cout << "popped contents of pq" << endl;
  for (auto i : sampleStringArray1) {
    auto poppedElement = pq.pop();
    cout << poppedElement << " ";
    REQUIRE(i == poppedElement);
  }
  cout << endl;
}

TEST_CASE("random PriorityQueue<int> test", "[rand PriorityQueue<int>]") {
  // setup
  const int length = 20;
  int *sampleIntArray1 = new int[length];
  // initialize random number generator in range min to max
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(0, length);
  for (int i = 0; i < length; i++) {
    int num = uni(rng);
    sampleIntArray1[i] = num;
  }

  PriorityQueue<int> pq = PriorityQueue<int>();

  for (int j = 0; j < length; j++) {
    int i = sampleIntArray1[j];
    pq.push(i);
  }

  REQUIRE(pq.getCount() == length);
  REQUIRE(pq.peek() == *max_element(sampleIntArray1, sampleIntArray1 + length));

  // sort in descending order
  sort(sampleIntArray1, sampleIntArray1 + length, greater<int>());

  // print both versions
  cout << endl;
  cout << "original array sorted" << endl;
  printArray(sampleIntArray1, length);

  cout << "popped contents of pq" << endl;
  for (int j = 0; j < length; j++) {
    int i = sampleIntArray1[j];
    auto poppedElement = pq.pop();
    cout << poppedElement << " ";
    REQUIRE(i == poppedElement);
  }
  cout << endl;
}

TEST_CASE("PriorityQueue<int> timing test", "[time PriorityQueue<int>]") {
  // setup
  const int length = 2048;
  array<long long, 2> speeds = popSpeed(length);
  // speed of bst.contains() should be less than std::find()
  REQUIRE(speeds[0] < speeds[1]);
}

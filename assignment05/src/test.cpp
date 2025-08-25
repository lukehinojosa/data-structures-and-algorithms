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

#include "sort.h"

using namespace std;
using namespace csi281;

template <typename T, int length> void printArray(T (&a)[length]) {
  copy(begin(a), end(a), ostream_iterator<T>(cout, " "));
  cout << endl;
}

TEST_CASE("Merge Sort", "[Merge]") {
  SECTION("int Test") {
    // setup
    const int length = 11;
    int sampleIntArray1[length] = {23, -3, -2, 4, 11, 4, 7, 8, 0, 0, -3};
    int sampleIntArray2[length];
    copy(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2));
    // sort
    mergeSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "mergeSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("Random int Test") {
    // setup
    const int length = 100;
    int sampleIntArray1[length];
    int sampleIntArray2[length];
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(-length, length);
    for (int i = 0; i < length; i++) {
      int num = uni(rng);
      sampleIntArray1[i] = num;
      sampleIntArray2[i] = num;
    }
    // sort
    mergeSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "mergeSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("string Test") {
    // setup
    const int length = 8;
    string sampleStringArray1[length]
        = {"dog", "man", "jen", "aaa", "frisbee", "$%", "  9  ", "dog"};
    string sampleStringArray2[length];
    copy(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2));
    // sort
    mergeSort(sampleStringArray1, 0, length - 1);
    sort(begin(sampleStringArray2), end(sampleStringArray2));
    // print arrays
    cout << endl;
    cout << "mergeSort" << endl;
    printArray(sampleStringArray1);
    cout << "std::sort" << endl;
    printArray(sampleStringArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2)));
  }
}

TEST_CASE("Quicksort", "[Quick]") {
  SECTION("int Test") {
    // setup
    const int length = 11;
    int sampleIntArray1[length] = {23, -3, -2, 4, 11, 4, 7, 8, 0, 0, -3};
    int sampleIntArray2[length];
    copy(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2));
    // sort
    quickSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "quickSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("Random int Test") {
    // setup
    const int length = 100;
    int sampleIntArray1[length];
    int sampleIntArray2[length];
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(-length, length);
    for (int i = 0; i < length; i++) {
      int num = uni(rng);
      sampleIntArray1[i] = num;
      sampleIntArray2[i] = num;
    }
    // sort
    quickSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "quickSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("string Test") {
    // setup
    const int length = 8;
    string sampleStringArray1[length]
        = {"dog", "man", "jen", "aaa", "frisbee", "$%", "  9  ", "dog"};
    string sampleStringArray2[length];
    copy(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2));
    // sort
    quickSort(sampleStringArray1, 0, length - 1);
    sort(begin(sampleStringArray2), end(sampleStringArray2));
    // print arrays
    cout << endl;
    cout << "quickSort" << endl;
    printArray(sampleStringArray1);
    cout << "std::sort" << endl;
    printArray(sampleStringArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2)));
  }
}

TEST_CASE("Insertion Sort", "[Insertion]") {
  SECTION("int Test") {
    // setup
    const int length = 11;
    int sampleIntArray1[length] = {23, -3, -2, 4, 11, 4, 7, 8, 0, 0, -3};
    int sampleIntArray2[length];
    copy(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2));
    // sort
    insertionSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "insertionSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("Random int Test") {
    // setup
    const int length = 100;
    int sampleIntArray1[length];
    int sampleIntArray2[length];
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(-length, length);
    for (int i = 0; i < length; i++) {
      int num = uni(rng);
      sampleIntArray1[i] = num;
      sampleIntArray2[i] = num;
    }
    // sort
    insertionSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "insertionSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("string Test") {
    // setup
    const int length = 8;
    string sampleStringArray1[length]
        = {"dog", "man", "jen", "aaa", "frisbee", "$%", "  9  ", "dog"};
    string sampleStringArray2[length];
    copy(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2));
    // sort
    insertionSort(sampleStringArray1, 0, length - 1);
    sort(begin(sampleStringArray2), end(sampleStringArray2));
    // print arrays
    cout << endl;
    cout << "insertionSort" << endl;
    printArray(sampleStringArray1);
    cout << "std::sort" << endl;
    printArray(sampleStringArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2)));
  }

  SECTION("Middle int Test") {
    // setup
    const int length = 11;
    int sampleIntArray3[length] = {5, -3, -2, 4, 11, 4, 7, 8, 0, 0, -3};
    // sort elements 2 to 6
    insertionSort(sampleIntArray3, 2, 6);
    // print arrays
    cout << endl;
    cout << "insertionSort of elements 2 to 6" << endl;
    printArray(sampleIntArray3);
    int correctIntArray3[length] = {5, -3, -2, 4, 4, 7, 11, 8, 0, 0, -3};
    cout << "expected output" << endl;
    printArray(correctIntArray3);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray3), end(sampleIntArray3), begin(correctIntArray3)));
  }
}

TEST_CASE("Hybrid Sort", "[Hybrid]") {
  SECTION("int Test") {
    // setup
    const int length = 11;
    int sampleIntArray1[length] = {23, -3, -2, 4, 11, 4, 7, 8, 0, 0, -3};
    int sampleIntArray2[length];
    copy(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2));
    // sort
    hybridSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "hybridSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("Random int Test") {
    // setup
    const int length = 100;
    int sampleIntArray1[length];
    int sampleIntArray2[length];
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(-length, length);
    for (int i = 0; i < length; i++) {
      int num = uni(rng);
      sampleIntArray1[i] = num;
      sampleIntArray2[i] = num;
    }
    // sort
    hybridSort(sampleIntArray1, 0, length - 1);
    sort(begin(sampleIntArray2), end(sampleIntArray2));
    // print arrays
    cout << endl;
    cout << "hybridSort" << endl;
    printArray(sampleIntArray1);
    cout << "std::sort" << endl;
    printArray(sampleIntArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleIntArray1), end(sampleIntArray1), begin(sampleIntArray2)));
  }

  SECTION("string Test") {
    // setup
    const int length = 8;
    string sampleStringArray1[length]
        = {"dog", "man", "jen", "aaa", "frisbee", "$%", "  9  ", "dog"};
    string sampleStringArray2[length];
    copy(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2));
    // sort
    hybridSort(sampleStringArray1, 0, length - 1);
    sort(begin(sampleStringArray2), end(sampleStringArray2));
    // print arrays
    cout << endl;
    cout << "hybridSort" << endl;
    printArray(sampleStringArray1);
    cout << "std::sort" << endl;
    printArray(sampleStringArray2);
    // check they are the same
    REQUIRE(equal(begin(sampleStringArray1), end(sampleStringArray1), begin(sampleStringArray2)));
  }
}

TEST_CASE("Speed Comparison", "[Speed]") {
  const int length = 2048;

  // Generate Random Data Structures
  int *testArray1 = new int[length];
  int *testArray2 = new int[length];
  int *testArray3 = new int[length];
  int *testArray4 = new int[length];

  // initialize random number generator in range min to max
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(0, length);

  // fill data structures with random data
  for (int i = 0; i < length; i++) {
    int num = uni(rng);
    testArray1[i] = num;
    testArray2[i] = num;
    testArray3[i] = num;
    testArray4[i] = num;
  }

  // test bubble sort
  using namespace std::chrono;
  auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  mergeSort(testArray1, 0, length - 1);
  auto end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long mergeSortTime = (end - start);

  // test selection sort
  start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  quickSort(testArray2, 0, length - 1);
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long quickSortTime = end - start;

  // test insertion sort
  start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  insertionSort(testArray3, 0, length - 1);
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long insertionSortTime = end - start;

  // test hybridSort
  start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  hybridSort(testArray4, 0, length - 1);
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long hybridSortTime = end - start;

  delete[] testArray1;
  delete[] testArray2;
  delete[] testArray3;
  delete[] testArray4;

  // everything should be faster than insertion sort
  // hybrid sort should be faster than merge sort
  REQUIRE(mergeSortTime < insertionSortTime);
  REQUIRE(quickSortTime < insertionSortTime);
  REQUIRE(hybridSortTime < insertionSortTime);
  REQUIRE(hybridSortTime < mergeSortTime);
}

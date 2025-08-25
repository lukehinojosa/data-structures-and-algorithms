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

#include "search.h"
#include "util.h"

// using namespace std;
using namespace csi281;

TEST_CASE("Linear Search", "[Linear]") {
  SECTION("int Test") {
    int sampleIntArray1[6] = {23, 4, 11, 4, 7, 8};
    REQUIRE(linearSearch(sampleIntArray1, 6, 7) == 4);
  }

  SECTION("float Test") {
    float sampleFloatArray1[4] = {23.1f, 4.0f, 11.5f, 7.1f};
    REQUIRE(linearSearch(sampleFloatArray1, 4, 7.1f) == 3);
  }

  SECTION("char Test") {
    char sampleCharArray1[4] = {'r', ' ', '!', '3'};
    REQUIRE(linearSearch(sampleCharArray1, 4, 'r') == 0);
  }

  SECTION("not found Test") {
    int sampleIntArray2[7] = {23, 4, 11, 4, 7, 45, 82};
    REQUIRE(linearSearch(sampleIntArray2, 7, 345) == -1);
  }
}

TEST_CASE("Binary Search", "[Binary]") {
  SECTION("int Test") {
    int sampleIntArray3[5] = {4, 4, 7, 72, 84};
    REQUIRE(binarySearch(sampleIntArray3, 5, 72) == 3);
  }

  SECTION("float Test") {
    float sampleFloatArray2[4] = {2.1f, 4.0f, 11.5f, 17.1f};
    REQUIRE(binarySearch(sampleFloatArray2, 4, 17.1f) == 3);
  }

  SECTION("char Test") {
    char sampleCharArray2[4] = {'a', 'c', 'f', 'r'};
    REQUIRE(binarySearch(sampleCharArray2, 4, 'r') == 3);
  }

  SECTION("not found Test") {
    int sampleIntArray2[7] = {5, 45, 112, 422, 743, 45234, 822342};
    REQUIRE(binarySearch(sampleIntArray2, 7, 345) == -1);
  }
}

TEST_CASE("Random Int Array", "[Random]") {
  const int N = 10000;
  const int MIN = 0;
  const int MAX = 1000;
  int *randArray = randomIntArray(N, MIN, MAX);

  SECTION("Nothing below MIN") {
    bool nothingBelowMin = true;
    for (int i = 0; i < N; i++) {
      if (randArray[i] < MIN) {
        nothingBelowMin = false;
        break;
      }
    }
    REQUIRE(nothingBelowMin);
  }

  SECTION("Nothing above MAX") {
    bool nothingAboveMax = true;
    for (int i = 0; i < N; i++) {
      if (randArray[i] > MAX) {
        nothingAboveMax = false;
        break;
      }
    }
    REQUIRE(nothingAboveMax);
  }

  SECTION("Not All the Same") {
    bool allSame = true;
    for (int i = 1; i < N; i++) {
      if (randArray[i] != randArray[i - 1]) {
        allSame = false;
        break;
      }
    }
    REQUIRE_FALSE(allSame);
  }

  SECTION("Dispersed at Edges Top") {
    bool somethingInTop = false;
    for (int i = 1; i < N; i++) {
      if (randArray[i] > 900) {
        somethingInTop = true;
        break;
      }
    }
    REQUIRE(somethingInTop);
  }

  SECTION("Dispersed at Edges Bottom") {
    bool somethingInBottom = false;
    for (int i = 1; i < N; i++) {
      if (randArray[i] < 100) {
        somethingInBottom = true;
        break;
      }
    }
    REQUIRE(somethingInBottom);
  }
}

TEST_CASE("Array Search Speed", "[Speed]") {
  const int N = 100000;
  const int NUM_TESTS = 1000;
  auto speeds = arraySearchSpeed(N, NUM_TESTS);
  // linear search should be slower than binary search
  SECTION("Linear Search Slower than Binary Search") {
    REQUIRE(speeds.first.count() > speeds.second.count());
  }
}

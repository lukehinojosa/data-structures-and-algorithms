//
//  test.cpp
//
//  Tests to prove your code works.
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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)
using doctest::Approx;

#include <string>
#include <stdexcept>

#include "Queue.h"
#include "Stack.h"

using namespace std;
using namespace csi281;

TEST_CASE("Queue Tests", "[queue]") {
  SECTION("Queue w/ int tests") {
    Queue<int> q1 = Queue<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // Push items and verify count.
    q1.push(10);
    q1.push(20);
    q1.push(30);
    REQUIRE(q1.getCount() == 3);
    // Peek and pop, verifying FIFO order.
    REQUIRE(q1.peek() == 10);
    REQUIRE(q1.pop() == 10);
    REQUIRE(q1.getCount() == 2);
    REQUIRE(q1.peek() == 20);
    // Push again and test remove.
    q1.push(40);
    REQUIRE(q1.getCount() == 3);
    q1.remove(20);
    REQUIRE(q1.getCount() == 2);
    // Pop remaining items and check final count.
    REQUIRE(q1.pop() == 30);
    REQUIRE(q1.pop() == 40);
    REQUIRE(q1.getCount() == 0);
    // Test empty exceptions.
    REQUIRE_THROWS_AS(q1.pop(), std::runtime_error);
    REQUIRE_THROWS_AS(q1.peek(), std::runtime_error);
  }

  SECTION("Queue w/ string tests") {
    Queue<string> q2 = Queue<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // Push items and verify count.
    q2.push("hello");
    q2.push("world");
    REQUIRE(q2.getCount() == 2);
    // Peek and pop, verifying FIFO order.
    REQUIRE(q2.peek() == "hello");
    REQUIRE(q2.pop() == "hello");
    REQUIRE(q2.getCount() == 1);
    // Push again and test remove.
    q2.push("again");
    q2.remove("world");
    REQUIRE(q2.getCount() == 1);
    // Pop remaining items and check final count.
    REQUIRE(q2.peek() == "again");
    REQUIRE(q2.pop() == "again");
    REQUIRE(q2.getCount() == 0);
    // Test empty exceptions.
    REQUIRE_THROWS_AS(q2.pop(), std::runtime_error);
    REQUIRE_THROWS_AS(q2.peek(), std::runtime_error);
  }
}

TEST_CASE("Stack Tests", "[stack]") {
  SECTION("Stack w/ int tests") {
    Stack<int> s1 = Stack<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // Push items and verify count.
    s1.push(10);
    s1.push(20);
    s1.push(30);
    REQUIRE(s1.getCount() == 3);
    // Peek and pop, verifying LIFO order.
    REQUIRE(s1.peek() == 30);
    REQUIRE(s1.pop() == 30);
    REQUIRE(s1.getCount() == 2);
    REQUIRE(s1.peek() == 20);
    // Push again and test remove.
    s1.push(40);
    REQUIRE(s1.getCount() == 3);
    s1.remove(20);
    REQUIRE(s1.getCount() == 2);
    // Pop remaining items and check final count.
    REQUIRE(s1.pop() == 40);
    REQUIRE(s1.pop() == 10);
    REQUIRE(s1.getCount() == 0);
    // Test empty exceptions.
    REQUIRE_THROWS_AS(s1.pop(), std::runtime_error);
    REQUIRE_THROWS_AS(s1.peek(), std::runtime_error);
  }

  SECTION("Stack w/ string tests") {
    Stack<string> s2 = Stack<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // Push items and verify count.
    s2.push("hello");
    s2.push("world");
    REQUIRE(s2.getCount() == 2);
    // Peek and pop, verifying LIFO order.
    REQUIRE(s2.peek() == "world");
    REQUIRE(s2.pop() == "world");
    REQUIRE(s2.getCount() == 1);
    // Push again and test remove.
    s2.push("again");
    s2.remove("hello");
    REQUIRE(s2.getCount() == 1);
    // Pop remaining items and check final count.
    REQUIRE(s2.peek() == "again");
    REQUIRE(s2.pop() == "again");
    REQUIRE(s2.getCount() == 0);
    // Test empty exceptions.
    REQUIRE_THROWS_AS(s2.pop(), std::runtime_error);
    REQUIRE_THROWS_AS(s2.peek(), std::runtime_error);
  }
}

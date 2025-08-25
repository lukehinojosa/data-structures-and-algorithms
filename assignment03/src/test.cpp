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

#include <string>

#include "DynamicArray.h"
#include "LinkedList.h"

using namespace std;
using namespace csi281;

class Person {
public:
  Person(string n, unsigned int a) : name(n), age(a){};
  bool operator==(const Person &other) const {
    return ((age == other.age) && (name == other.name));
  }
  string name = "";
  unsigned int age = 0;
};

TEST_CASE("Linked List", "[LL]") {
  SECTION("int Test") {
    LinkedList<int> ll = LinkedList<int>();
    int sampleIntArray1[6] = {23, 4, 11, 4, 7, 8};
    for (int &i : sampleIntArray1) {
      ll.insertAtEnd(i);
    }
    CHECK(ll.getCount() == 6);
    CHECK(ll.get(2) == 11);
    CHECK(ll.find(7) == 4);
    ll.removeAtBeginning();
    CHECK(ll.get(0) == 4);
    CHECK(ll.getCount() == 5);
    for (int i = 0; i < 100; i++) {
      ll.insert(i, 3);
    }
    CHECK(ll.get(1) == 11);
    CHECK(ll.get(3) == 99);
    CHECK(ll.get(102) == 0);
    CHECK(ll.getCount() == 105);
    ll.removeAtEnd();
    CHECK(ll.getCount() == 104);
    CHECK(ll.get(103) == 7);
    CHECK(ll.get(0) == 4);
    CHECK(ll.contains(50) == true);
    ll.remove(50);
    CHECK(ll.contains(50) == false);
    CHECK(ll.getCount() == 103);
    ll.insertAtBeginning(1023);
    ll.insertAtBeginning(4324);
    CHECK(ll.contains(4678) == false);
    CHECK(ll.contains(1023) == true);
    CHECK(ll.getCount() == 105);
    CHECK(ll.get(0) == 4324);
  }

  SECTION("string test") {
    LinkedList<string> ll = LinkedList<string>();
    string sampleStringArray1[6] = {"hi", "b", "d", "wo", "t", "e"};
    for (string &s : sampleStringArray1) {
      ll.insertAtEnd(s);
    }
    CHECK(ll.getCount() == 6);
    CHECK(ll.get(2) == "d");
    CHECK(ll.find("t") == 4);
    ll.removeAtBeginning();
    CHECK(ll.get(0) == "b");
    CHECK(ll.getCount() == 5);
    for (int i = 0; i < 100; i++) {
      ll.insert(string(i, 'A'), 3);
    }
    CHECK(ll.get(1) == "d");
    CHECK(ll.get(3) == string(99, 'A'));
    CHECK(ll.get(102) == "");
    CHECK(ll.getCount() == 105);
    ll.removeAtEnd();
    CHECK(ll.getCount() == 104);
    CHECK(ll.get(103) == "t");
    CHECK(ll.get(0) == "b");
    CHECK(ll.contains("AAAA") == true);
    ll.remove("AAAAAAA");
    CHECK(ll.contains("AAAAAAA") == false);
    CHECK(ll.getCount() == 103);
    ll.insertAtBeginning("Bob");
    ll.insertAtBeginning("Mary");
    CHECK(ll.contains("Sanford") == false);
    CHECK(ll.contains("Bob") == true);
    CHECK(ll.getCount() == 105);
    CHECK(ll.get(0) == "Mary");
  }

  SECTION("Person test") {
    LinkedList<Person> ll = LinkedList<Person>();
    Person samplePersonArray1[2] = {Person("Drew", 65), Person("Ellen", 66)};
    for (Person &p : samplePersonArray1) {
      ll.insertAtEnd(p);
    }
    CHECK(ll.getCount() == 2);
    CHECK(ll.get(1).age == 66);
    CHECK(ll.find(Person("Drew", 65)) == 0);
    ll.removeAtBeginning();
    CHECK(ll.get(0) == Person("Ellen", 66));
    CHECK(ll.getCount() == 1);
    for (int i = 0; i < 100; i++) {
      ll.insert(Person("Clone", 18), 1);
    }
    CHECK(ll.get(1).name == "Clone");
    CHECK(ll.get(3) == Person("Clone", 18));
    CHECK(ll.get(100) == Person("Clone", 18));
    CHECK(ll.getCount() == 101);
    ll.removeAtEnd();
    CHECK(ll.getCount() == 100);
    CHECK(ll.get(99) == Person("Clone", 18));
    CHECK(ll.get(0) == Person("Ellen", 66));
    CHECK(ll.contains(Person("Ellen", 66)) == true);
    CHECK(ll.contains(Person("Clone", 18)) == true);
    ll.remove(Person("Ellen", 66));
    CHECK(ll.contains(Person("Ellen", 66)) == false);
    CHECK(ll.getCount() == 99);
    ll.insertAtBeginning(Person("Matteo", 23));
    ll.insertAtBeginning(Person("Sarah", 33));
    CHECK(ll.contains(Person("Drew", 65)) == false);
    CHECK(ll.contains(Person("Matteo", 23)) == true);
    CHECK(ll.getCount() == 101);
    CHECK(ll.get(0) == Person("Sarah", 33));
  }
}

TEST_CASE("Dynamic Array", "[DA]") {
  SECTION("int Test") {
    DynamicArray<int> da = DynamicArray<int>();
    int sampleIntArray1[6] = {23, 4, 11, 4, 7, 8};
    for (int &i : sampleIntArray1) {
      da.insertAtEnd(i);
    }
    CHECK(da.getCount() == 6);
    CHECK(da.get(2) == 11);
    CHECK(da.find(7) == 4);
    da.removeAtBeginning();
    CHECK(da.get(0) == 4);
    CHECK(da.getCount() == 5);
    for (int i = 0; i < 100; i++) {
      da.insert(i, 3);
    }
    CHECK(da.get(1) == 11);
    CHECK(da.get(3) == 99);
    CHECK(da.get(102) == 0);
    CHECK(da.getCount() == 105);
    da.removeAtEnd();
    CHECK(da.getCount() == 104);
    CHECK(da.get(103) == 7);
    CHECK(da.get(0) == 4);
    CHECK(da.contains(50) == true);
    da.remove(50);
    CHECK(da.contains(50) == false);
    CHECK(da.getCount() == 103);
    da.insertAtBeginning(1023);
    da.insertAtBeginning(4324);
    CHECK(da.contains(4678) == false);
    CHECK(da.contains(1023) == true);
    CHECK(da.getCount() == 105);
    CHECK(da.get(0) == 4324);
  }

  SECTION("string test") {
    LinkedList<string> da = LinkedList<string>();
    string sampleStringArray1[6] = {"hi", "b", "d", "wo", "t", "e"};
    for (string &s : sampleStringArray1) {
      da.insertAtEnd(s);
    }
    CHECK(da.getCount() == 6);
    CHECK(da.get(2) == "d");
    CHECK(da.find("t") == 4);
    da.removeAtBeginning();
    CHECK(da.get(0) == "b");
    CHECK(da.getCount() == 5);
    for (int i = 0; i < 100; i++) {
      da.insert(string(i, 'A'), 3);
    }
    CHECK(da.get(1) == "d");
    CHECK(da.get(3) == string(99, 'A'));
    CHECK(da.get(102) == "");
    CHECK(da.getCount() == 105);
    da.removeAtEnd();
    CHECK(da.getCount() == 104);
    CHECK(da.get(103) == "t");
    CHECK(da.get(0) == "b");
    CHECK(da.contains("AAAA") == true);
    da.remove("AAAAAAA");
    CHECK(da.contains("AAAAAAA") == false);
    CHECK(da.getCount() == 103);
    da.insertAtBeginning("Bob");
    da.insertAtBeginning("Mary");
    CHECK(da.contains("Sanford") == false);
    CHECK(da.contains("Bob") == true);
    CHECK(da.getCount() == 105);
    CHECK(da.get(0) == "Mary");
  }

  SECTION("Person test") {
    LinkedList<Person> da = LinkedList<Person>();
    Person samplePersonArray1[2] = {Person("Drew", 65), Person("Ellen", 66)};
    for (Person &p : samplePersonArray1) {
      da.insertAtEnd(p);
    }
    CHECK(da.getCount() == 2);
    CHECK(da.get(1).age == 66);
    CHECK(da.find(Person("Drew", 65)) == 0);
    da.removeAtBeginning();
    CHECK(da.get(0) == Person("Ellen", 66));
    CHECK(da.getCount() == 1);
    for (int i = 0; i < 100; i++) {
      da.insert(Person("Clone", 18), 1);
    }
    CHECK(da.get(1).name == "Clone");
    CHECK(da.get(3) == Person("Clone", 18));
    CHECK(da.get(100) == Person("Clone", 18));
    CHECK(da.getCount() == 101);
    da.removeAtEnd();
    CHECK(da.getCount() == 100);
    CHECK(da.get(99) == Person("Clone", 18));
    CHECK(da.get(0) == Person("Ellen", 66));
    CHECK(da.contains(Person("Ellen", 66)) == true);
    CHECK(da.contains(Person("Clone", 18)) == true);
    da.remove(Person("Ellen", 66));
    CHECK(da.contains(Person("Ellen", 66)) == false);
    CHECK(da.getCount() == 99);
    da.insertAtBeginning(Person("Matteo", 23));
    da.insertAtBeginning(Person("Sarah", 33));
    CHECK(da.contains(Person("Drew", 65)) == false);
    CHECK(da.contains(Person("Matteo", 23)) == true);
    CHECK(da.getCount() == 101);
    CHECK(da.get(0) == Person("Sarah", 33));
  }

  SECTION("capacity test") {
    DynamicArray<int> da = DynamicArray<int>(5);
    CHECK(da.getCapacity() == 5);
    for (int i = 0; i < 10; i++) {
      da.insertAtEnd(i);
    }
    CHECK(da.getCapacity() == 10);
    da.insertAtEnd(10);
    CHECK(da.getCapacity() == 20);
    da.setCapacity(3);
    CHECK(da.getCapacity() == 3);
    CHECK(da.getCount() == 3);
    CHECK(da[2] == 2);
  }
}

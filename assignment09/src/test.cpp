//
//  test.cpp
//
//  Tests to prove your code works.
//  You SHOULD modify the end of this file, adding your own test case.
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

#include <iostream>
#include <list>
#include <string>

#include "WeightedGraph.h"

using namespace std;
using namespace csi281;

template <typename T> void printPath(list<T> &l) {
  for (auto &x : l) {
    if (x != l.back()) {
      cout << x << " -> ";
    } else {
      cout << x;
    }
  }
  cout << endl;
}

// DO NOT MODIFY THIS TEST CASE
TEST_CASE("dijkstra() cityGraph1 Test", "[dijksta]") {
  WeightedGraph<string, int> cityGraph1 = WeightedGraph<string, int>();
  cityGraph1.addEdge("Seattle", "Chicago", 2097);
  cityGraph1.addEdge("Seattle", "Denver", 1331);
  cityGraph1.addEdge("Seattle", "San Francisco", 807);
  cityGraph1.addEdge("San Francisco", "Denver", 1267);
  cityGraph1.addEdge("San Francisco", "Los Angeles", 381);
  cityGraph1.addEdge("Los Angeles", "Denver", 1015);
  cityGraph1.addEdge("Los Angeles", "Kansas City", 1663);
  cityGraph1.addEdge("Los Angeles", "Dallas", 1435);
  cityGraph1.addEdge("Denver", "Chicago", 1003);
  cityGraph1.addEdge("Denver", "Kansas City", 599);
  cityGraph1.addEdge("Kansas City", "Chicago", 533);
  cityGraph1.addEdge("Kansas City", "New York", 1260);
  cityGraph1.addEdge("Kansas City", "Atlanta", 864);
  cityGraph1.addEdge("Kansas City", "Dallas", 496);
  cityGraph1.addEdge("Chicago", "Boston", 983);
  cityGraph1.addEdge("Chicago", "New York", 787);
  cityGraph1.addEdge("Boston", "New York", 214);
  cityGraph1.addEdge("Atlanta", "New York", 888);
  cityGraph1.addEdge("Atlanta", "Dallas", 781);
  cityGraph1.addEdge("Atlanta", "Houston", 810);
  cityGraph1.addEdge("Atlanta", "Miami", 661);
  cityGraph1.addEdge("Houston", "Miami", 1187);
  cityGraph1.addEdge("Houston", "Dallas", 239);
  cout << "------cityGraph1------" << endl;
  cityGraph1.debugPrint();
  auto resultPair = cityGraph1.dijkstra("New York");
  auto parentResults = resultPair.first;
  auto weightResults = resultPair.second;
  // are the distances from New York correct?
  CHECK(weightResults["San Francisco"] == 3057);
  CHECK(weightResults["Los Angeles"] == 2805);
  CHECK(weightResults["Seattle"] == 2884);
  CHECK(weightResults["Denver"] == 1790);
  CHECK(weightResults["Kansas City"] == 1260);
  CHECK(weightResults["Chicago"] == 787);
  CHECK(weightResults["Boston"] == 214);
  CHECK(weightResults["Atlanta"] == 888);
  CHECK(weightResults["Miami"] == 1549);
  CHECK(weightResults["Dallas"] == 1669);
  CHECK(weightResults["Houston"] == 1698);
  CHECK(weightResults["San Francisco"] == 3057);
  auto path = cityGraph1.pathMapToPath(parentResults, "San Francisco");
  cout << "------cityGraph1 path------" << endl;
  printPath(path);
  // Shortest path should be
  // New York -> Chicago -> Denver -> San Francisco
  CHECK(path.size() == 4);
  CHECK(path.front() == "New York");
  CHECK(path.back() == "San Francisco");
  auto it = path.begin();
  auto last = path.front();
  for (unsigned long i = 1; i < path.size(); i++) {
    it++;
    auto current = *it;
    CHECK(cityGraph1.edgeExists(last, current));
    last = current;
  }
}

// DO NOT MODIFY THIS TEST CASE
TEST_CASE("dijkstra() cityGraph2 Test", "[dijksta]") {
  WeightedGraph<string, int> cityGraph2 = WeightedGraph<string, int>();
  cityGraph2.addEdge("Seattle", "Chicago", 1737);
  cityGraph2.addEdge("Seattle", "San Francisco", 678);
  cityGraph2.addEdge("San Francisco", "Riverside", 386);
  cityGraph2.addEdge("San Francisco", "Los Angeles", 348);
  cityGraph2.addEdge("Los Angeles", "Riverside", 50);
  cityGraph2.addEdge("Los Angeles", "Phoenix", 357);
  cityGraph2.addEdge("Riverside", "Phoenix", 307);
  cityGraph2.addEdge("Riverside", "Chicago", 1704);
  cityGraph2.addEdge("Phoenix", "Dallas", 887);
  cityGraph2.addEdge("Phoenix", "Houston", 1015);
  cityGraph2.addEdge("Dallas", "Chicago", 805);
  cityGraph2.addEdge("Dallas", "Atlanta", 721);
  cityGraph2.addEdge("Dallas", "Houston", 225);
  cityGraph2.addEdge("Houston", "Atlanta", 702);
  cityGraph2.addEdge("Houston", "Miami", 968);
  cityGraph2.addEdge("Atlanta", "Chicago", 588);
  cityGraph2.addEdge("Atlanta", "Washington", 543);
  cityGraph2.addEdge("Atlanta", "Miami", 604);
  cityGraph2.addEdge("Miami", "Washington", 923);
  cityGraph2.addEdge("Chicago", "Detroit", 238);
  cityGraph2.addEdge("Detroit", "Boston", 613);
  cityGraph2.addEdge("Detroit", "Washington", 396);
  cityGraph2.addEdge("Detroit", "New York", 482);
  cityGraph2.addEdge("Boston", "New York", 190);
  cityGraph2.addEdge("New York", "Philadelphia", 81);
  cityGraph2.addEdge("Philadelphia", "Washington", 123);
  cout << "------cityGraph2------" << endl;
  cityGraph2.debugPrint();
  auto resultPair = cityGraph2.dijkstra("Miami");
  auto parentResults = resultPair.first;
  auto weightResults = resultPair.second;
  // are the distances from Miami correct?
  CHECK(weightResults["Seattle"] == 2929);
  CHECK(weightResults["Chicago"] == 1192);
  CHECK(weightResults["Atlanta"] == 604);
  CHECK(weightResults["New York"] == 1127);
  auto path = cityGraph2.pathMapToPath(parentResults, "San Francisco");
  cout << "------cityGraph2 path------" << endl;
  printPath(path);
  // Shortest path should be
  // Miami -> Houston -> Phoenix -> Riverside -> San Francisco
  CHECK(path.size() == 5);
  CHECK(path.front() == "Miami");
  CHECK(path.back() == "San Francisco");
  auto it = path.begin();
  auto last = path.front();
  for (unsigned long i = 1; i < path.size(); i++) {
    it++;
    auto current = *it;
    CHECK(cityGraph2.edgeExists(last, current));
    last = current;
  }
}

TEST_CASE("dijkstra() myGraph Test", "[dijkstra]") {
    // Create a new weighted graph
    WeightedGraph<string, int> myGraph = WeightedGraph<string, int>();
    // Add edges to the graph
    myGraph.addEdge("A", "B", 1);
    myGraph.addEdge("A", "C", 4);
    myGraph.addEdge("B", "C", 2);
    myGraph.addEdge("B", "D", 5);
    myGraph.addEdge("C", "D", 1);

    cout << "------myGraph------" << endl;
    // Print the graph for debugging purposes
    myGraph.debugPrint();
    // Run Dijkstra's algorithm starting from vertex "A"
    auto resultPair = myGraph.dijkstra("A");
    auto parentResults = resultPair.first;
    auto weightResults = resultPair.second;

    // Check if the distances from "A" are correct
    CHECK(weightResults["B"] == 1);
    CHECK(weightResults["C"] == 3);
    CHECK(weightResults["D"] == 4);

    // Get the shortest path from "A" to "D"
    auto path = myGraph.pathMapToPath(parentResults, "D");
    cout << "------myGraph path------" << endl;
    // Print the path for debugging purposes
    printPath(path);
    // The shortest path should be A -> B -> C -> D
    CHECK(path.size() == 4);
    CHECK(path.front() == "A");
    CHECK(path.back() == "D");
    
    // Check the path contents
    auto it = path.begin();
    CHECK(*it == "A");
    it++;
    CHECK(*it == "B");
    it++;
    CHECK(*it == "C");
    it++;
    CHECK(*it == "D");

    // Check if the edges in the path exist
    it = path.begin();
    auto last = path.front();
    for (unsigned long i = 1; i < path.size(); i++) {
        it++;
        auto current = *it;
        CHECK(myGraph.edgeExists(last, current));
        last = current;
    }
}

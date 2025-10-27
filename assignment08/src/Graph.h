//
//  Graph.h
//
//  Defines the Graph class.
//  You SHOULD modify this file.
//  You should not add any additional methods to this class.
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

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include <list>
#include <optional>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  template <typename V> class Graph {
  public:
    // Add a vertex to the graph
    void addVertex(V vertex) { adjacencyList.emplace(vertex, unordered_set<V>()); }

    // Add an edge to the graph
    // *from* is the starting vertex
    // *to* is the ending vertex
    // *bidirectional* is whether the edge should be in both directions
    // If *from* and/or *to* do not exist, they are added as vertices
    void addEdge(V from, V to, bool bidirectional = true) {
      adjacencyList[from].emplace(to);
      if (bidirectional) {
        adjacencyList[to].emplace(from);
      } else {  // ensure the *to* vrtex is in the graph
        if (adjacencyList.find(to) == adjacencyList.end()) {
          addVertex(to);
        }
      }
    }

    // Return the neighbors (as an unordered_set) for a vertex
    const unordered_set<V> &neighbors(const V &vertex) {
      // ensure we actually have this vertex in the graph
      assert(adjacencyList.find(vertex) != adjacencyList.end());
      return adjacencyList[vertex];
    }

    // Determines whether there is an edge between *from* and *to*
    // if either is not in the graph, return false
    bool edgeExists(const V &from, const V &to) {
      // First, check if the 'from' vertex exists in the graph.
      // If it doesn't, an edge can't exist, so return false.
      if (adjacencyList.find(from) == adjacencyList.end()) {
        return false;
      }
      // If the 'from' vertex exists, check if its set of neighbors contains 'to'.
      // The 'count' method on unordered_set returns 1 if the element is present, and 0 otherwise.
      return adjacencyList[from].count(to) > 0;
    }

    using Path = list<V>;
    // Figure out a path from a goal node back to
    // a start node using a map keeping track of each node and the
    // node that got to it (your explored map)
    Path pathMapToPath(unordered_map<V, V> &previousMap, V &goal) {
      Path path = Path();
      V *current, *previous = nullptr;
      current = &goal;
      do {
        path.push_front(*current);
        previous = current;
        current = &previousMap[*current];
      } while (*current != *previous);
      return path;
    }

    // Perform a depth-first search from *start*, looking for *goal*
    // Return a path if one is found using pathMathToPath (with explored)
    // or return nullopt if no path is found
    optional<Path> dfs(const V &start, const V &goal) {
      // how did we get to each node, and which ones have already been visited (dual purpose)
      unordered_map<V, V> explored = unordered_map<V, V>();
      // the start node came from nowhere, so we mark its parent as itself
      explored[start] = start;

      // The frontier is a stack for DFS, representing nodes to visit.
      stack<V> frontier;
      // Start the search from the 'start' node.
      frontier.push(start);

      // Continue searching as long as there are nodes in the frontier.
      while (!frontier.empty()) {
        // Get the next node to visit from the top of the stack.
        V current = frontier.top();
        frontier.pop();

        // If the current node is the goal, a path has been found.
        if (current == goal) {
          // Create a mutable copy of goal because pathMapToPath requires a non-const reference.
          V mutableGoal = goal;
          // Reconstruct and return the path.
          return pathMapToPath(explored, mutableGoal);
        }

        // Explore the neighbors of the current node.
        for (const V &neighbor : neighbors(current)) {
          // If the neighbor has not been explored yet
          if (explored.find(neighbor) == explored.end()) {
            // Mark it as explored and record the current path.
            explored[neighbor] = current;
            // Add the neighbor to the frontier to visit later.
            frontier.push(neighbor);
          }
        }
      }
      // If the frontier is empty and the goal was not found, no path exists.
      return nullopt;
    }

    // Perform a breadth-first search from *start*, looking for *goal*
    // Return a path if one is found using pathMathToPath (with explored)
    // or return nullopt if no path is found
    optional<Path> bfs(const V &start, const V &goal) {
      // how did we get to each node, and which ones have already been visited (dual purpose)
      unordered_map<V, V> explored = unordered_map<V, V>();
      // the start node came from nowhere, so we mark its parent as itself
      explored[start] = start;

      // The frontier is a queue for BFS, representing nodes to visit.
      queue<V> frontier;
      // Start the search from the 'start' node.
      frontier.push(start);

      // Continue searching as long as there are nodes in the frontier.
      while (!frontier.empty()) {
        // Get the next node to visit from the front of the queue.
        V current = frontier.front();
        frontier.pop();

        // If the current node is the goal, we've found a path.
        if (current == goal) {
          // Create a mutable copy of goal because pathMapToPath requires a non-const reference.
          V mutableGoal = goal;
          // Reconstruct and return the path.
          return pathMapToPath(explored, mutableGoal);
        }

        // Explore the neighbors of the current node.
        for (const V &neighbor : neighbors(current)) {
          // If the neighbor has not been explored yet...
          if (explored.find(neighbor) == explored.end()) {
            // Mark it as explored and record how we got here (the parent).
            explored[neighbor] = current;
            // Add the neighbor to the frontier to visit later.
            frontier.push(neighbor);
          }
        }
      }
      // If the frontier is empty and the goal was not found, no path exists.
      return nullopt;
    }

    // Utility function if you need it
    void printExplored(unordered_map<V, V> um) {
      for (auto const &p : um) {
        cout << p.first << " : " << p.second;
        cout << endl;
      }
    }

    // Debug print out the contents of the graph
    void debugPrint() {
      for (auto const &p : adjacencyList) {
        cout << p.first << ": ";
        for (auto const &v : p.second) {
          cout << v << ", ";
        }
        cout << endl;
      }
    }

  private:
    unordered_map<V, unordered_set<V>> adjacencyList = unordered_map<V, unordered_set<V>>();
  };
}  // namespace csi281

#endif /* graph_hpp */

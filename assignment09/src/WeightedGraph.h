//
//  WeightedGraph.h
//
//  Defines the WeightedGraph class.
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

#ifndef weighted_graph_hpp
#define weighted_graph_hpp

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  // V is the type of the vertices
  // W is the type of the weights
  template <typename V, typename W> class WeightedGraph {
  public:
    // Add a vertex to the graph
    void addVertex(V vertex) { adjacencyList.emplace(vertex, unordered_map<V, W>()); }

    // Add an edge to the graph
    // *from* is the starting vertex
    // *to* is the ending vertex
    // *weight* is the edge's weight
    // *bidirectional* is whether the edge should be in both directions
    // If *from* and/or *to* do not exist, they are added as vertices
    void addEdge(V from, V to, W weight, bool bidirectional = true) {
      // add from if it's not in the graph
      if (adjacencyList.find(from) == adjacencyList.end()) {
        addVertex(from);
      }
      // add to if it's not in the graph
      if (adjacencyList.find(to) == adjacencyList.end()) {
        addVertex(to);
      }
      // add weighted edges
      adjacencyList[from][to] = weight;
      if (bidirectional) {
        adjacencyList[to][from] = weight;
      }
    }

    // Return the weighted edges (as an unordered_set) for a vertex
    list<pair<const V, W>> neighborsWithWeights(const V &vertex) {
      // ensure we actually have this vertex in the graph
      assert(adjacencyList.find(vertex) != adjacencyList.end());
      return list<pair<const V, W>>(adjacencyList[vertex].begin(), adjacencyList[vertex].end());
    }

    // Determines whether there is an edge between *from* and *to*
    // if either is not in the graph, return false
    bool edgeExists(const V &from, const V &to) {
      if (adjacencyList.find(from) == adjacencyList.end()) {
        return false;
      }
      if (adjacencyList[from].find(to) == adjacencyList[from].end()) {
        return false;
      }
      return true;
    }

    using Path = list<V>;
    // Figure out a path from a goal node back to
    // a start node using a map keeping track of each node and the
    // node that got to it (your explored map)
    Path pathMapToPath(unordered_map<V, V> &previousMap, V goal) {
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

    // Perform Dijkstra's algorithm from *start*, looking through
    // the entire graph
    // Returns a pair containing the pathMap (how to get to each vertex)
    // and the weightMap (how far each vertex is from the start)
    pair<unordered_map<V, V>, unordered_map<V, W>> dijkstra(const V &start) {
      // how did we get to each vertex
      unordered_map<V, V> parents = unordered_map<V, V>();
      parents[start] = start;
      // the weight to get to each vertex
      unordered_map<V, W> weights = unordered_map<V, W>();
      weights[start] = 0;
      // the next vertices to explore, will always pop/top the smallest weight
      // pair next; note that the weight comes before the vertex for ordering purposes
      // this is different than the order from neighborsWithWeights()
      priority_queue<pair<W, V>, vector<pair<W, V>>, greater<pair<W, V>>> frontier
          = priority_queue<pair<W, V>, vector<pair<W, V>>, greater<pair<W, V>>>();
      frontier.push(make_pair(0, start));

      // YOUR CODE HERE
      // NOTE: You must use the constructs defined at
      // the beginning of this method in your code.
      // NOTE: Because the majority of the grade is based on the
      // few (10-15) lines of code you need to write here, unlike
      // previous assignments, I will not help you write it.
      // However, of course I am happy to answer any of your
      // conceptual questions around Dijkstra's algorithm
      // or specific questions about C++ or how the
      // WeightedGraph class works. Remember, you have pseudocode
      // from class, from your book, and you are free to
      // use other pseudocode as long as you cite it. Please
      // do not look at other C++ solutions.

      return make_pair(parents, weights);
    }

    // Utility function if you need it
    template <typename T1, typename T2> void printMap(unordered_map<T1, T2> um) {
      for (auto const &p : um) {
        cout << p.first << " : " << p.second;
        cout << endl;
      }
    }

    // Debug print out the contents of the graph
    void debugPrint() {
      for (auto const &p : adjacencyList) {
        cout << p.first << ": ";
        for (auto const &we : p.second) {
          cout << "(" << we.first << " " << we.second << "), ";
        }
        cout << endl;
      }
    }

  private:
    unordered_map<V, unordered_map<V, W>> adjacencyList = unordered_map<V, unordered_map<V, W>>();
  };
}  // namespace csi281

#endif /* weighted_graph_hpp */

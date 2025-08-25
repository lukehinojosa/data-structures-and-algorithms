//
//  main.cpp
//
//  The main file for assignment 3; tests the data structures through
//  the tests in tests.cpp and by producing a timed search chart.
//  Don't worry too much about what's in this file frankly...
//  There is nothing in this file that you need to change unless
//  you want to do some testing by modifying main().
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

#include <chrono>  // for nanoseconds
#include <iostream>
#include <random>
#include <utility>  // for pair

#include "DynamicArray.h"
#include "LinkedList.h"
#include "MemoryLeakDetector.h"
#include "PPlot.h"
#include "SVGPainter.h"

using namespace std;
using namespace std::chrono;
using namespace csi281;
using namespace SVGChart;

// Finds the speed of linear search
// in a LinkedList and DynamicArray of *length* size
// by running *numTests* and averaging them
// Returns a pair indicating the average time it took
// to do linear search in nanoseconds
// LinkedList search should be first in the pair, and DynamicArray
// should be second
// Suggest using the facilities in STL <chrono>
static pair<nanoseconds, nanoseconds> searchSpeed(const int length, const int numTests) {
  // Generate Random Data Structures
  LinkedList<int> ll = LinkedList<int>();
  DynamicArray<int> da = DynamicArray<int>();

  // initialize random number generator in range min to max
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(0, length);

  // fill data structures with random data
  for (int i = 0; i < length; i++) {
    int num = uni(rng);
    ll.insertAtEnd(num);
    da.insertAtEnd(num);
  }

  // generate the testing array
  int *tests = new int[numTests];
  for (int i = 0; i < numTests; i++) {
    tests[i] = uni(rng);
  }

  // test the linked list
  using namespace std::chrono;
  auto start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
  for (int i = 0; i < numTests; i++) {
    ll.contains(tests[i]);
  }
  auto end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

  auto llSearchSpeed = (end - start) / numTests;

  // cout << "The linked list searches took on average " << llSearchSpeed << " nanoseconds\n";

  // test the dynamic array

  start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
  for (int i = 0; i < numTests; i++) {
    da.contains(tests[i]);
  }
  end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

  auto daSearchSpeed = (end - start) / numTests;
  // cout << "The dynamic array searches took on average " << daSearchSpeed << " nanoseconds\n";

  delete[] tests;
  return pair<nanoseconds, nanoseconds>(llSearchSpeed, daSearchSpeed);
}

// Draw a chart showing the average search times
// for different numbers of elements in "SearchChart.svg"
static void drawSearchChart() {
  PPlot pplot;
  pplot.mPlotBackground.mTitle = "Number of Elements Searched Versus Time";

  PlotData *theX1 = new PlotData();
  PlotData *theY1 = new PlotData();
  LineDataDrawer *theDataDrawer1 = new LineDataDrawer();
  theDataDrawer1->mDrawPoint = false;
  theDataDrawer1->mDrawLine = true;

  LegendData *legend1 = new LegendData();  // let us setup the first legend
  legend1->mName = "Linked List";
  legend1->mColor = PColor(200, 0, 100);  // just an rgb value

  PlotData *theX2 = new PlotData();
  PlotData *theY2 = new PlotData();
  LineDataDrawer *theDataDrawer2 = new LineDataDrawer();
  theDataDrawer2->mDrawPoint = false;
  theDataDrawer2->mDrawLine = true;

  LegendData *legend2 = new LegendData();  // let us setup the first legend
  legend2->mName = "Dynamic Array";
  legend2->mColor = PColor(100, 20, 220);  // just an rgb value

  // cout << "Generating SVG data..." << endl;

  const int NUM_TESTS = 1000;
  for (int i = 1000; i <= 10000; i *= 2) {
    auto speeds = searchSpeed(i, NUM_TESTS);
    theX1->push_back(i);
    theY1->push_back(speeds.first.count());
    theX2->push_back(i);
    theY2->push_back(speeds.second.count());
  }

  pplot.mPlotDataContainer.AddXYPlot(theX1, theY1, legend1, theDataDrawer1);
  pplot.mPlotDataContainer.AddXYPlot(theX2, theY2, legend2, theDataDrawer2);

  pplot.mMargins.mLeft = 100;
  pplot.mMargins.mTop = 50;
  pplot.mMargins.mRight = 50;
  pplot.mMargins.mBottom = 50;
  pplot.mGridInfo.mXGridOn = true;
  pplot.mGridInfo.mYGridOn = true;
  pplot.mYAxisSetup.mCrossOrigin = false;
  pplot.mXAxisSetup.mCrossOrigin = true;
  pplot.mXAxisSetup.mLabel = "N";
  pplot.mYAxisSetup.mAutoScaleMin = false;
  pplot.mYAxisSetup.mAutoScaleMax = true;
  pplot.mYAxisSetup.mMin = 0;
  pplot.mXAxisSetup.mMin = 0;
  // pplot.mYAxisSetup.mMax = 100;
  pplot.mYAxisSetup.mLabel = "Time (nanoseconds)";
  SVGPainter painter(800, 600);
  pplot.Draw(painter);
  painter.writeFile("SearchChart.svg");
  cout << "Wrote SVG SearchChart.svg" << endl;
}

// Test all code and draw charts.
int main(int argc, char *argv[]) {
  // draw chart
  drawSearchChart();
}

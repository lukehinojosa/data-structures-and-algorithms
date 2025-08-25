//
//  main.cpp
//
//  The main file for assignment 4; tests the sorts through
//  the tests in tests.cpp and by producing a timed sort chart.
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

#include <algorithm>  // for sort()
#include <array>
#include <chrono>  // for microseconds
#include <iostream>
#include <random>

#include "MemoryLeakDetector.h"
#include "PPlot.h"
#include "SVGPainter.h"
#include "sort.h"

using namespace std;
using namespace std::chrono;
using namespace csi281;
using namespace SVGChart;

// Finds the speed of bubbleSort, selectionSort, insertionSort,
// and std::sort (in that order) on an array of *length*
static array<long long, 4> sortSpeed(const int length) {
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
  bubbleSort(testArray1, length);
  auto end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long bubbleSortTime = (end - start);

  // test selection sort
  start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  selectionSort(testArray2, length);
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long selectionSortTime = end - start;

  // test insertion sort
  start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  insertionSort(testArray3, length);
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long insertionSortTime = end - start;

  // test std::sort
  start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  sort(testArray4, testArray4 + length);
  end = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  long long stdSortTime = end - start;
  // cout << stdSortTime << endl; // how long for std::sort
  delete[] testArray1;
  delete[] testArray2;
  delete[] testArray3;
  delete[] testArray4;

  return {bubbleSortTime, selectionSortTime, insertionSortTime, stdSortTime};
}

// Draw a chart showing the average sort times
// for different numbers of elements in "SortChart.svg"
static void drawSortChart() {
  PPlot pplot;
  pplot.mPlotBackground.mTitle = "Number of Elements Sorted Versus Time";

  PlotData *theX1 = new PlotData();
  PlotData *theY1 = new PlotData();
  LineDataDrawer *theDataDrawer1 = new LineDataDrawer();
  theDataDrawer1->mDrawPoint = false;
  theDataDrawer1->mDrawLine = true;

  LegendData *legend1 = new LegendData();  // let us setup the first legend
  legend1->mName = "bubbleSort";
  legend1->mColor = PColor(200, 0, 100);  // just an rgb value

  PlotData *theX2 = new PlotData();
  PlotData *theY2 = new PlotData();
  LineDataDrawer *theDataDrawer2 = new LineDataDrawer();
  theDataDrawer2->mDrawPoint = false;
  theDataDrawer2->mDrawLine = true;

  LegendData *legend2 = new LegendData();  // let us setup the first legend
  legend2->mName = "selectionSort";
  legend2->mColor = PColor(100, 20, 220);  // just an rgb value

  PlotData *theX3 = new PlotData();
  PlotData *theY3 = new PlotData();
  LineDataDrawer *theDataDrawer3 = new LineDataDrawer();
  theDataDrawer3->mDrawPoint = false;
  theDataDrawer3->mDrawLine = true;

  LegendData *legend3 = new LegendData();  // let us setup the first legend
  legend3->mName = "insertionSort";
  legend3->mColor = PColor(50, 220, 10);  // just an rgb value

  PlotData *theX4 = new PlotData();
  PlotData *theY4 = new PlotData();
  LineDataDrawer *theDataDrawer4 = new LineDataDrawer();
  theDataDrawer4->mDrawPoint = false;
  theDataDrawer4->mDrawLine = true;

  LegendData *legend4 = new LegendData();  // let us setup the first legend
  legend4->mName = "std::sort";
  legend4->mColor = PColor(200, 209, 220);  // just an rgb value

  // cout << "Generating SVG data..." << endl;

  for (int i = 16; i <= 2048; i *= 2) {
    array<long long, 4> speeds = sortSpeed(i);
    theX1->push_back(i);
    theY1->push_back(speeds[0]);
    theX2->push_back(i);
    theY2->push_back(speeds[1]);
    theX3->push_back(i);
    theY3->push_back(speeds[2]);
    theX4->push_back(i);
    theY4->push_back(speeds[3]);
  }

  pplot.mPlotDataContainer.AddXYPlot(theX1, theY1, legend1, theDataDrawer1);
  pplot.mPlotDataContainer.AddXYPlot(theX2, theY2, legend2, theDataDrawer2);
  pplot.mPlotDataContainer.AddXYPlot(theX3, theY3, legend3, theDataDrawer3);
  pplot.mPlotDataContainer.AddXYPlot(theX4, theY4, legend4, theDataDrawer4);

  pplot.mMargins.mLeft = 100;
  pplot.mMargins.mTop = 50;
  pplot.mMargins.mRight = 50;
  pplot.mMargins.mBottom = 50;
  pplot.mGridInfo.mXGridOn = true;
  pplot.mGridInfo.mYGridOn = true;
  pplot.mYAxisSetup.mCrossOrigin = false;
  pplot.mXAxisSetup.mCrossOrigin = true;
  pplot.mXAxisSetup.mTickInfo.mTicksOn = true;
  pplot.mXAxisSetup.mLabel = "N";
  pplot.mYAxisSetup.mAutoScaleMin = false;
  pplot.mYAxisSetup.mAutoScaleMax = true;
  pplot.mYAxisSetup.mMin = 0;
  pplot.mXAxisSetup.mMin = 0;
  // pplot.mYAxisSetup.mMax = 100;
  pplot.mYAxisSetup.mLabel = "Time (microseconds)";
  SVGPainter painter(800, 600);
  pplot.Draw(painter);
  painter.writeFile("SortChart.svg");
  cout << "Wrote SVG SortChart.svg" << endl;
}

// Test all code and draw charts.
int main(int argc, char *argv[]) {
  cout << "Generating chart..." << endl;
  // draw chart
  drawSortChart();
}

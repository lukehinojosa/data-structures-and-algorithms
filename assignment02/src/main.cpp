//
//  main.cpp
//
//  The main file for assignment 2; tests the search functions by running
//  the tests in tests.cpp and by producing some charts.
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

#include <iostream>

#include "PPlot.h"
#include "SVGPainter.h"
#include "util.h"

using namespace std;
using namespace csi281;
using namespace SVGChart;

// Draw a chart showing the average search times
// for different numbers of elements in "SearchChart.svg"
static void drawSearchChart() {
  PPlot pplot;
  pplot.mPlotBackground.mTitle = "Number of Elements Versus Time (1000 samples at each N)";

  PlotData *theX1 = new PlotData();
  PlotData *theY1 = new PlotData();
  LineDataDrawer *theDataDrawer1 = new LineDataDrawer();
  theDataDrawer1->mDrawPoint = false;
  theDataDrawer1->mDrawLine = true;

  LegendData *legend1 = new LegendData();  // let us setup the first legend
  legend1->mName = "Linear Search";
  legend1->mColor = PColor(200, 0, 100);  // just an rgb value

  PlotData *theX2 = new PlotData();
  PlotData *theY2 = new PlotData();
  LineDataDrawer *theDataDrawer2 = new LineDataDrawer();
  theDataDrawer2->mDrawPoint = false;
  theDataDrawer2->mDrawLine = true;

  LegendData *legend2 = new LegendData();  // let us setup the first legend
  legend2->mName = "Binary Search (w/ Sort Amortized)";
  legend2->mColor = PColor(100, 20, 220);  // just an rgb value

  cout << "Generating times for large arrays; this may take a while..." << endl;

  const int NUM_TESTS = 1000;
  for (int i = 100; i <= 10000; i *= 2) {
    auto speeds = arraySearchSpeed(i, NUM_TESTS);
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
}

// Test all code and draw charts.
int main(int argc, char *argv[]) {
  // draw chart
  drawSearchChart();
}

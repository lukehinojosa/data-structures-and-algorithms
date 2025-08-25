//
//  main.cpp
//
//  The main file for assignment 1; tests the data processing by running
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
#include "csv.h"

using namespace std;
using namespace csi281;
using namespace SVGChart;

// Draw a chart showing the days below 32 and days above 90
// for each city in "ExtremeDaysChart.svg"
static void drawExtremeDaysChart(CityTemperatureData &city1, CityTemperatureData &city2) {
  PPlot pplot;
  pplot.mPlotBackground.mTitle = "Extreme Days";

  PlotData *theX1 = new PlotData();
  PlotData *theY1 = new PlotData();
  for (int i = city1.getFirstYear(); i < city1.getFirstYear() + city1.count(); i++) {
    theX1->push_back(i);
    theY1->push_back(city1[i].numDaysBelow32);
  }
  LineDataDrawer *theDataDrawer1 = new LineDataDrawer();
  theDataDrawer1->mDrawPoint = false;
  theDataDrawer1->mDrawLine = true;

  LegendData *legend1 = new LegendData();  // let us setup the first legend
  legend1->mName = city1.getName() + " Days Below 32";
  legend1->mColor = PColor(100, 0, 200);  // just an rgb value

  pplot.mPlotDataContainer.AddXYPlot(theX1, theY1, legend1, theDataDrawer1);

  PlotData *theX2 = new PlotData();
  PlotData *theY2 = new PlotData();
  for (int i = city2.getFirstYear(); i < city2.getFirstYear() + city2.count(); i++) {
    theX2->push_back(i);
    theY2->push_back(city2[i].numDaysBelow32);
  }
  LineDataDrawer *theDataDrawer2 = new LineDataDrawer();
  theDataDrawer2->mDrawPoint = false;
  theDataDrawer2->mDrawLine = true;

  LegendData *legend2 = new LegendData();  // let us setup the first legend
  legend2->mName = city2.getName() + " Days Below 32";
  legend2->mColor = PColor(100, 200, 200);  // just an rgb value

  pplot.mPlotDataContainer.AddXYPlot(theX2, theY2, legend2, theDataDrawer2);

  PlotData *theX3 = new PlotData();
  PlotData *theY3 = new PlotData();
  for (int i = city1.getFirstYear(); i < city1.getFirstYear() + city1.count(); i++) {
    theX3->push_back(i);
    theY3->push_back(city1[i].numDaysAbove90);
  }
  LineDataDrawer *theDataDrawer3 = new LineDataDrawer();
  theDataDrawer3->mDrawPoint = false;
  theDataDrawer3->mDrawLine = true;

  LegendData *legend3 = new LegendData();  // let us setup the first legend
  legend3->mName = city1.getName() + " Days Above 90";
  legend3->mColor = PColor(200, 0, 100);  // just an rgb value

  pplot.mPlotDataContainer.AddXYPlot(theX3, theY3, legend3, theDataDrawer3);

  PlotData *theX4 = new PlotData();
  PlotData *theY4 = new PlotData();
  for (int i = city2.getFirstYear(); i < city2.getFirstYear() + city2.count(); i++) {
    theX4->push_back(i);
    theY4->push_back(city2[i].numDaysAbove90);
  }
  LineDataDrawer *theDataDrawer4 = new LineDataDrawer();
  theDataDrawer4->mDrawPoint = false;
  theDataDrawer4->mDrawLine = true;

  LegendData *legend4 = new LegendData();  // let us setup the first legend
  legend4->mName = city2.getName() + " Days Above 90";
  legend4->mColor = PColor(220, 100, 0);  // just an rgb value

  pplot.mPlotDataContainer.AddXYPlot(theX4, theY4, legend4, theDataDrawer4);

  pplot.mMargins.mLeft = 100;
  pplot.mMargins.mTop = 50;
  pplot.mMargins.mRight = 50;
  pplot.mMargins.mBottom = 50;
  pplot.mGridInfo.mXGridOn = true;
  pplot.mGridInfo.mYGridOn = true;
  pplot.mYAxisSetup.mCrossOrigin = false;
  pplot.mXAxisSetup.mCrossOrigin = false;
  pplot.mXAxisSetup.mLabel = "Year";
  pplot.mYAxisSetup.mAutoScaleMin = false;
  pplot.mYAxisSetup.mAutoScaleMax = false;
  pplot.mYAxisSetup.mMin = 0;
  pplot.mYAxisSetup.mMax = 100;
  pplot.mYAxisSetup.mLabel = "Number of Days";
  SVGPainter painter(800, 600);
  pplot.Draw(painter);
  painter.writeFile("ExtremeDaysChart.svg");
}

// Draw a chart showing the average temperatures
// for each city in "AvgTempChart.svg"
static void drawAvgTempChart(CityTemperatureData &city1, CityTemperatureData &city2) {
  PPlot pplot;
  pplot.mPlotBackground.mTitle = "Average Temperature";
  PlotData *theX1 = new PlotData();
  PlotData *theY1 = new PlotData();
  for (int i = city1.getFirstYear(); i < city1.getFirstYear() + city1.count(); i++) {
    theX1->push_back(i);
    theY1->push_back(city1[i].averageTemperature);
  }
  LineDataDrawer *theDataDrawer1 = new LineDataDrawer();
  theDataDrawer1->mDrawPoint = false;
  theDataDrawer1->mDrawLine = true;

  LegendData *legend1 = new LegendData();  // let us setup the first legend
  legend1->mName = city1.getName();
  legend1->mColor = PColor(100, 0, 200);  // just an rgb value

  pplot.mPlotDataContainer.AddXYPlot(theX1, theY1, legend1, theDataDrawer1);

  PlotData *theX2 = new PlotData();
  PlotData *theY2 = new PlotData();
  for (int i = city2.getFirstYear(); i < city2.getFirstYear() + city2.count(); i++) {
    theX2->push_back(i);
    theY2->push_back(city2[i].averageTemperature);
  }
  LineDataDrawer *theDataDrawer2 = new LineDataDrawer();
  theDataDrawer2->mDrawPoint = false;
  theDataDrawer2->mDrawLine = true;

  LegendData *legend2 = new LegendData();  // let us setup the first legend
  legend2->mName = city2.getName();
  legend2->mColor = PColor(100, 200, 200);  // just an rgb value

  pplot.mPlotDataContainer.AddXYPlot(theX2, theY2, legend2, theDataDrawer2);

  pplot.mMargins.mLeft = 100;
  pplot.mMargins.mTop = 50;
  pplot.mMargins.mRight = 50;
  pplot.mMargins.mBottom = 50;
  pplot.mGridInfo.mXGridOn = true;
  pplot.mGridInfo.mYGridOn = true;
  pplot.mYAxisSetup.mCrossOrigin = false;
  pplot.mXAxisSetup.mCrossOrigin = false;
  pplot.mXAxisSetup.mLabel = "Year";
  pplot.mYAxisSetup.mAutoScaleMin = false;
  pplot.mYAxisSetup.mAutoScaleMax = false;
  pplot.mYAxisSetup.mMin = 0;
  pplot.mYAxisSetup.mMax = 100;
  pplot.mYAxisSetup.mLabel = "Temperature (F)";
  SVGPainter painter(800, 600);
  pplot.Draw(painter);
  painter.writeFile("AvgTempChart.svg");
}

// Test all code and draw charts.
int main(int argc, char *argv[]) {
  // run tests
  // int result = Catch::Session().run( argc, argv );

  // draw graphs
  CityTemperatureData* nyc = readCity("NYC", "tempdata.csv", 1, 51);
  CityTemperatureData* burlington = readCity("Burlington", "tempdata.csv", 52, 102);
  drawAvgTempChart(*nyc, *burlington);
  drawExtremeDaysChart(*nyc, *burlington);
  delete nyc;
  delete burlington;
}

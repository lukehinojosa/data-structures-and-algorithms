//
//  csv.hpp
//
//  Functions for reading CSV files and turning them into
//  constructs from CityTemperatureData.h
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

#ifndef csv_hpp
#define csv_hpp

#include <fstream>
#include <string>

#include "CityTemperatureData.h"
#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  // Remove extraneous characters from string so it can
  // be converted into a number
  void clean(string &str);

  // Read from a input string stream we hit the next comma, or the end
  // and try to convert it into the type we seek.
  float readFloatCell(istringstream &iss);
  int readIntCell(istringstream &iss);
  string readStringCell(istringstream &iss);

  // Read a single line from a file stream and turn it into a CityYear
  CityYear readLine(ifstream &file);

  // Read city by looking at the specified lines in the CSV
  CityTemperatureData* readCity(string cityName, string fileName, int startLine, int endLine);
}  // namespace csi281

#endif /* csv_hpp */

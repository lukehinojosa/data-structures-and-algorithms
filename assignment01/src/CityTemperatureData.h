//
//  CityTemperatureData.h
//
//  This file defines the CityYear struct and CityTemperatureData class.
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

#ifndef CityTemperatureData_hpp
#define CityTemperatureData_hpp

#include <string>

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  // Represents one year of a city's data
  struct CityYear {
    int year;
    int numDaysBelow32;
    int numDaysAbove90;
    float averageTemperature;
    float averageMax;
    float averageMin;
  };

  // Represents all of the data for a city in aggregate
  class CityTemperatureData {
  public:
    CityTemperatureData(const string name, CityYear data[], int numYears);
    ~CityTemperatureData();
    int count() const { return _count; }
    const string& getName() const { return _name; }
    int getFirstYear() const { return _data[0].year; }
    const CityYear operator[](const int year) const;
    float getAllTimeAverage() const;
    int getTotalDaysBelow32() const;
    int getTotalDaysAbove90() const;

  private:
    string _name;     // name of city
    CityYear* _data;  // array of CityYear
    int _count;       // number of years covered by the class
  };
}  // namespace csi281

#endif /* CityTemperatureData_hpp */

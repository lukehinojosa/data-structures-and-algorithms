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

#include "CityTemperatureData.h"
#include "csv.h"

using namespace std;
using namespace csi281;

TEST_CASE("New York Test Data", "[New York]") {
  CityTemperatureData* nyc = readCity("NYC", "tempdata.csv", 1, 51);

  REQUIRE(nyc->count() == 51);
  REQUIRE(nyc->getName() == "NYC");
  REQUIRE(nyc->getFirstYear() == 1968);

  SECTION("Accessing random elements.") {
    CHECK((*nyc)[1970].numDaysBelow32 == 29);
    CHECK((*nyc)[2011].averageTemperature == 56.4f);
    CHECK((*nyc)[2000].averageMin == 46.9f);
    CHECK((*nyc)[2018].averageMax == 62.6f);
  }

  SECTION("Correct Averages & Totals") {
    CHECK(nyc->getAllTimeAverage() == Approx(55.25294118f).epsilon(0.01));
    CHECK(nyc->getTotalDaysBelow32() == 967);
    CHECK(nyc->getTotalDaysAbove90() == 891);
  }

  delete nyc;
}

TEST_CASE("Burlington Test Data", "[Burlington]") {
  CityTemperatureData* burlington = readCity("Burlington", "tempdata.csv", 52, 102);

  REQUIRE(burlington->count() == 51);
  REQUIRE(burlington->getName() == "Burlington");
  REQUIRE(burlington->getFirstYear() == 1968);

  SECTION("Accessing random elements.") {
    CHECK((*burlington)[1978].numDaysBelow32 == 87);
    CHECK((*burlington)[1989].averageTemperature == 44.6f);
    CHECK((*burlington)[2000].averageMin == 36.0f);
    CHECK((*burlington)[2018].averageMax == 56.9f);
  }

  SECTION("Correct Averages & Totals") {
    CHECK(burlington->getAllTimeAverage() == Approx(45.70589f).epsilon(0.01));
    CHECK(burlington->getTotalDaysBelow32() == 3242);
    CHECK(burlington->getTotalDaysAbove90() == 357);
  }

  delete burlington;
}

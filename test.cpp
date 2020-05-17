#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#define CATCH_CONFIG_MAIN //So that catch will define a main method
#include "catch.hpp"

#include "utilities.h"

using namespace std;

using namespace TRNELP001;

TEST_CASE("dimension mean") {
	
    vector<vector<double>> values = {{1.5, 2.5}, {2.5, 3.5}, {3.5, 4.5}};

    SECTION("first dimension") {

        double expected_mean = 2.5;
        double calculated_mean = dimension_mean(values, 0);
       
	    REQUIRE(expected_mean==calculated_mean);
	}

    SECTION("second dimension") {

        double expected_mean = 3.5;
        double calculated_mean = dimension_mean(values, 1);
       
	    REQUIRE(expected_mean==calculated_mean);
	}

}
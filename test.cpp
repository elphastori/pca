#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#define CATCH_CONFIG_MAIN //So that catch will define a main method
#include "catch.hpp"

#include "pca_math.h"

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

TEST_CASE("covariance") {
	
    vector<vector<double>> values = {{1.5, 2.5}, {2.5, 3.5}, {3.5, 4.5}};

    SECTION("two dimensions (covariance)") {

        double expected_covariance = 1.0;
       
	    REQUIRE(expected_covariance==covariance(values, 0, 1));
	    REQUIRE(expected_covariance==covariance(values, 1, 0));
	}

    SECTION("one dimension (variance)") {

        double expected_variance_0 = 1.0;
        double expected_variance_1 = 1.0;
       
	    REQUIRE(expected_variance_0==covariance(values, 0, 0));
	    REQUIRE(expected_variance_1==covariance(values, 1, 1));
	}

}
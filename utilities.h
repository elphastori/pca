#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace TRNELP001 {

    vector<double> split_string(const string& str, char delim);

    double dimension_mean(vector<vector<double>> values, int dimension);

    vector<vector<double>> mean_adjusted(vector<vector<double>> values);

    double covariance(vector<vector<double>> values, int dim_a, int dim_b);

    vector<vector<double>> covariance_matrix(vector<vector<double>> values);
}

#endif
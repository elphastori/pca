#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

namespace TRNELP001 {

    double dimension_mean(vector<vector<double>> values, int dimension);

    vector<vector<double>> mean_adjusted(vector<vector<double>> values);

    double covariance(vector<vector<double>> values, int dim_a, int dim_b);

    MatrixXd covariance_matrix(vector<vector<double>> values);
}

#endif
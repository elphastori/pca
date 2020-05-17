#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#include "utilities.h"

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

namespace TRNELP001 {

    double dimension_mean(vector<vector<double>> values, int dimension) {
        double sum = 0;
        int n = values.size();

        for (int i = 0; i < n; ++i) {
            sum += values[i][dimension];
        }

        return sum / n;
    }

    vector<vector<double>> mean_adjusted(vector<vector<double>> values) {
        vector<vector<double>> normalized_values;

        for (int i = 0; i < values.size(); ++i) {
            vector<double> point;

            for (int j = 0; j < values[i].size(); j++) {
                double value = values[i][j] - dimension_mean(values, j);
                point.push_back(value);
            }

            normalized_values.push_back(point);
        }
    }

    double covariance(vector<vector<double>> values, int dim_a, int dim_b) {
        int n = values.size();
        double product_sums = 0;

        for (int i = 0; i < n; ++i) {
            double a_diff = (values[i][dim_a] - dimension_mean(values, dim_a));
            double b_diff = (values[i][dim_b] - dimension_mean(values, dim_b));

            product_sums += a_diff * b_diff;
        }

        return product_sums / (n - 1);
    }

    MatrixXd covariance_matrix(vector<vector<double>> values) {
        int n_dimensions = values[0].size();
        MatrixXd m(n_dimensions, n_dimensions);

        for (int i = 0; i < n_dimensions; ++i) {
            for (int j = 0; j < n_dimensions; ++j) {
                m(i, j) = covariance(values, i, j);
            }
        }

        return m;
    }

}
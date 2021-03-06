#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#include "pca_math.h"

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

    MatrixXd show_results(EigenSolver<MatrixXd> es, MatrixXd m, ostream &output) {
        auto eigenvalues = es.eigenvalues().real();
        double eigenvalue_sum = eigenvalues.sum();

        output << "Eigenvalues:" << endl;
        output << eigenvalues << endl << endl;

        output << "Eigenvectors:" << endl;
        output << es.eigenvectors() << endl;
        output << "Each column in the matrix above in an eigenvector with the January value at the " << endl;
        output << "top and the July value at the bottom" << endl << endl;

        output << "Covariance matrix:" << endl;
        output << m << endl << endl;

        output << "Total variance:" << endl;
        output << eigenvalue_sum << endl << endl;

        for (int i = 0; i < eigenvalues.rows(); i++) {
            output << "Principal Component " << i + 1 << endl;
            output << (eigenvalues.row(i)(0) / eigenvalue_sum) * 100 << "%" << endl << endl;
        }
        output << "The eigenvalue of each principal component was used to calculate the percentage." << endl;
        output << "The eigenvector with the larger percentage has a higher spread, the data varies " << endl;
        output << "most in its direction." << endl << endl;
        output << "The purpose of Principal Component Analysis is to identify these directions in " << endl;
        output << "which the data varies most." << endl;
    }

}
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

        // Psedo-check for correctness
        // m(0,0) = 0.616555556;
        // m(0,1) = 0.615444444;
        // m(1,0) = 0.615444444;
        // m(1,1) = 0.716555556;

        return m;
    }

    MatrixXd show_results(EigenSolver<MatrixXd> es, MatrixXd m, ostream &output) {
        auto eigenvalues = es.eigenvalues().real();
        double eigenvalue_sum = eigenvalues.sum();

        output << "Eigenvalues:" << endl;
        for (int i = eigenvalues.rows() - 1; i >= 0; --i) {
                output << eigenvalues.row(i).col(0)[0] << " " << endl;
        }
        cout << endl;

        output << "Eigenvectors:" << endl;
        output << es.eigenvectors() << endl << endl;

        output << "Covariance matrix:" << endl;
        output << m << endl << endl;

        output << "Total variance:" << endl;
        output << eigenvalue_sum << endl << endl;

        for (int i = eigenvalues.rows() - 1; i >= 0; --i) {
            output << "Component " << eigenvalues.rows() - i << endl;
            output << (eigenvalues.row(i)(0) / eigenvalue_sum) * 100 << "%" << endl << endl;
        }
    }

}
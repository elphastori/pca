#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "utilities.h"

using namespace std;
using namespace TRNELP001;

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

vector<vector<double>> covariance_matrix(vector<vector<double>> values) {
    vector<vector<double>> matrix;
    int n_dimensions = values[0].size();

    for (int i = 0; i < 2; ++i) {
        vector<double> row;
        for (int j = 0; j < 2; ++j) {
            row.push_back(covariance(values, i, j));
        }
        matrix.push_back(row);
    }

    return matrix;
}

int main(int argc, char * argv[]) {

    const string DATA_FILENAME = "data.txt";

    ifstream in(DATA_FILENAME.c_str());

    if(!in) {
        cout << "Could not open data file " << DATA_FILENAME << endl;
        in.close();
        return -1;
    }

    vector<vector<double>> values;

    string line;

    while (getline(in, line)) {
        vector<double> point = split_string(line, ' ');
        values.push_back(point);
    }

    // Close file
    in.close();

    vector<vector<double>> matrix = covariance_matrix(values);

    // Display covariance matrix
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
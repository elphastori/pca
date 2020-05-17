#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "utilities.h"

#include <Eigen/Dense>
 
using Eigen::MatrixXd;

using namespace std;
using namespace TRNELP001;

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
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int n_dimensions = values[0].size();
    MatrixXd m(n_dimensions, n_dimensions);

    for (int i = 0; i < n_dimensions; ++i) {
        for (int j = 0; j < n_dimensions; ++j) {
            m(i, j) = matrix[i][j];
        }
    }

    cout << m << endl;

    return 0;

}
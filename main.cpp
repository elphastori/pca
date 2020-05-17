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

    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    cout << m << std::endl;

    return 0;

}
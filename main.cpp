#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "utilities.h"

#include <Eigen/Dense>
 
using namespace std;
using namespace TRNELP001;
using namespace Eigen;

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

    MatrixXd m = covariance_matrix(values);

    EigenSolver<MatrixXd> es(m);

    cout << "Eigenvalues:" << endl;
    cout << es.eigenvalues() << endl << endl;

    cout << "Eigenvectors:" << endl;
    cout << es.eigenvectors() << endl << endl;

    cout << "Covariance matrix:" << endl;
    cout << m << endl << endl;

    return 0;

}
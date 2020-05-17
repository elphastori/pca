#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "loader.h"
#include "utilities.h"

#include <Eigen/Dense>
 
using namespace std;
using namespace TRNELP001;
using namespace Eigen;

int main(int argc, char * argv[]) {
    const string DATA_FILENAME = "data.txt";
    vector<vector<double>> values = load_values(DATA_FILENAME);

    MatrixXd m = covariance_matrix(values);
    EigenSolver<MatrixXd> es(m);

    auto eigenvalues = es.eigenvalues().real();
    auto eigenvectors = es.eigenvectors().real();
    double eigenvalue_sum = eigenvalues.sum();

    cout << "Eigenvalues:" << endl;
    cout << eigenvalues << endl << endl;

    cout << "Eigenvectors:" << endl;
    cout << eigenvectors << endl << endl;

    cout << "Covariance matrix:" << endl;
    cout << m << endl << endl;

    cout << "Total variance:" << endl;
    cout << eigenvalue_sum << endl << endl;

    for (int i = 0; i < eigenvalues.rows(); ++i) {
        cout << "Component " << i + 1 << endl;
        cout << (eigenvalues.row(i) / eigenvalue_sum) * 100 << "%" << endl << endl;
    }

    return 0;
}
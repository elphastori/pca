#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "loader.h"
#include "pca_math.h"

#include <Eigen/Dense>
 
using namespace std;
using namespace TRNELP001;
using namespace Eigen;

int main(int argc, char * argv[]) {
    const string INPUT_FILE = "data.txt";
    const string OUTPUT_FILE = "output.txt";

    vector<vector<double>> values = load_values(INPUT_FILE);

    // Calculate covariance matrix
    MatrixXd m = covariance_matrix(values);
    EigenSolver<MatrixXd> es(m);

    cout << "Results saved to " << OUTPUT_FILE << endl << endl;

    // Print results to screen
    show_results(es, m, cout);

    // Save results to text file
    ofstream out(OUTPUT_FILE.c_str());
    show_results(es, m, out);
    out.close();

    return 0;
}
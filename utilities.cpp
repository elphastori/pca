#include "utilities.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace TRNELP001 {

    vector<double> split_string(const string& str, char delim) {
        stringstream ss(str);
        string token;
        vector<double> cont;
        while (getline(ss, token, delim)) {
            cont.push_back(stof(token));
        }
        return cont;
    }

    double dimension_mean(vector<vector<double>> values, int dimension) {
        double sum = 0;
        int n = values.size();

        for (int i = 0; i < n; ++i) {
            sum += values[i][dimension];
        }

        return sum / n;
    }

}
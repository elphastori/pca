#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#include "loader.h"

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

    vector<vector<double>> load_values(string filename) {
        ifstream in(filename.c_str());

        if(!in) {
            cout << "Could not open data file " << filename << endl;
            in.close();
            exit(-1);
        }

        vector<vector<double>> values;

        string line;
        while (getline(in, line)) {
            vector<double> point = split_string(line, ' ');
            values.push_back(point);
        }

        in.close();

        return values;
    }

}
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

}
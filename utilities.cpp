#include "utilities.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace TRNELP001 {

    vector<string> split_string(const string& str, char delim) {
        stringstream ss(str);
        string token;
        vector<string> cont;
        while (getline(ss, token, delim)) {
            cont.push_back(token);
        }
        return cont;
    }

}
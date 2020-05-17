#ifndef LOADER_H
#define LOADER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace TRNELP001 {

    vector<vector<double>> load_values(string filename);

}

#endif
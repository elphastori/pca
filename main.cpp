#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "utilities.h"

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

    vector<vector<string>> values;

    string line;

    while ( getline(in, line) ) {
        vector<string> point = split_string(line, ' ');
        values.push_back(point);
    }

    // Close file
    in.close();

    // Verify loaded data
    for (int i = 0; i < values.size(); ++i) {
        cout << values[i][0] << " " << values[i][1] << endl;
    }

    return 0;

}
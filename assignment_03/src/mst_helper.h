#ifndef MST_HELPER_H
#define MST_HELPER_H

#include <vector>
#include <fstream>

using namespace std;

void runMST(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    ofstream& output_file
);

#endif
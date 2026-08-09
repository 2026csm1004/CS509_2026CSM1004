
#ifndef CSR_H
#define CSR_H

#include <string>
#include <vector>

using namespace std;

void runCSR(
    const string& inputFile,
    const string& outputFile,
    vector<int>& row_ptr,
    vector<int>& col_idx,
    vector<int>& values,
    int& V,
    int& source
);

#endif
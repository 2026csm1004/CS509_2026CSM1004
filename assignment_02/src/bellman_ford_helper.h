
#ifndef BELLMAN_FORD_HELPER_H
#define BELLMAN_FORD_HELPER_H

#include <vector>
#include <fstream>

using namespace std;

void bellmanFordCSR(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    int source,
    ofstream& output_file
);

#endif
#ifndef PAGERANK_HELPER_H
#define PAGERANK_HELPER_H

#include <vector>
#include <fstream>

using namespace std;

void pageRank(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    int V,
    double damping,
    double tolerance,
    int max_iterations,
    ofstream& output_file
);

#endif

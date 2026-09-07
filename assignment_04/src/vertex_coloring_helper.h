#ifndef VERTEX_COLORING_HELPER_H
#define VERTEX_COLORING_HELPER_H

#include <vector>
#include <fstream>

using namespace std;

void vertexColoring(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    int V,
    ofstream& output_file
);

#endif

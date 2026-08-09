#ifndef CSR_HELPER_H
#define CSR_HELPER_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// For BFS and DFS
void adj_to_csr(ifstream &input_file,
                vector<int> &row_ptr,
                vector<int> &col_idx,
                int &V,
                int &E,
                int &source);

// For SSSP
void weighted_adj_to_csr(ifstream &input_file,
                         vector<int> &row_ptr,
                         vector<int> &col_idx,
                         vector<int> &values,
                         int &V,
                         int &E,
                         int &source);

#endif
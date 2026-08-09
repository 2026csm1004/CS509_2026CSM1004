#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <vector>

using namespace std;

const long long INF = 1e15;


bool floyd_warshall(
    const vector<vector<long long>>& graph,
    vector<vector<long long>>& dist
);

#endif
#ifndef FLOYD_WARSHALL_HELPER_H
#define FLOYD_WARSHALL_HELPER_H

#include <string>
#include <fstream>

using namespace std;

void floydWarshall(
    const string& inputFile,
    ofstream& outputFile
);

#endif
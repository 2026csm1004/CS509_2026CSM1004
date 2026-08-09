
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include "csr.h"

using namespace std;

void runCSR(
    const string& inputFile,
    const string& outputFile,
    vector<int>& row_ptr,
    vector<int>& col_idx,
    vector<int>& values,
    int& V,
    int& source
)
{
    clock_t start, end;

    start = clock();

    bool isWeighted = true;

    ifstream input_file(inputFile);
    ofstream output_file(outputFile);

    if(!input_file)
    {
        cout << "Error while opening input file!" << endl;
        return;
    }

    input_file >> V;

    int E;
    input_file >> E;

    // These are now passed from main()
    // so Bellman-Ford can use them.

    row_ptr.clear();
    col_idx.clear();
    values.clear();

    row_ptr.push_back(0);

    for(int i = 0; i < V; i++)
    {
        int vertex;
        int degree;

        input_file >> vertex >> degree;

        for(int j = 0; j < degree; j++)
        {
            int neighbour;

            input_file >> neighbour;

            col_idx.push_back(neighbour);

            if(isWeighted)
            {
                int weight;

                input_file >> weight;

                values.push_back(weight);
            }
        }

        row_ptr.push_back(col_idx.size());
    }

    end = clock();

    double time_taken =
        double(end - start) / CLOCKS_PER_SEC;

    double time_in_ms = time_taken * 1000;

    string temp;

    input_file >> temp;     // SOURCE
    input_file >> source;

    // ---------------------------------------
    // Write CSR representation
    // ---------------------------------------

    output_file << "row pointer:\n";

    for(int x : row_ptr)
        output_file << x << " ";

    output_file << "\ncolumn index:\n";

    for(int x : col_idx)
        output_file << x << " ";

    if(isWeighted)
    {
        output_file << "\nweight:\n";

        for(int x : values)
            output_file << x << " ";
    }

    output_file << "\nsource Vertex:\n";
    output_file << source << endl;

    output_file << "Execution time: "
                << time_in_ms
                << " ms"
                << endl;

    input_file.close();
    output_file.close();
}
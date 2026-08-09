#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../../assignment_01/src/csr.h"
#include "../../assignment_02/src/bellman_ford_helper.h"

using namespace std;

int main()
{
    string inputFile = "input.txt";

    string csrOutputFile = "csr_output.txt";

    string finalOutputFile = "output.txt";

    // CSR data
    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;

    int V;
    int source;

    // ---------------------------------------
    // Step 1: Convert adjacency list to CSR
    // ---------------------------------------

    runCSR(
        inputFile,
        csrOutputFile,
        row_ptr,
        col_idx,
        values,
        V,
        source
    );

    // ---------------------------------------
    // Step 2: Open final output file
    // ---------------------------------------

    ofstream output_file(finalOutputFile);

    if(!output_file)
    {
        cout << "Error while opening output.txt"
             << endl;

        return 1;
    }

    // ---------------------------------------
    // Step 3: Run Bellman-Ford
    // ---------------------------------------

    bellmanFordCSR(
        row_ptr,
        col_idx,
        values,
        V,
        source,
        output_file
    );

    output_file.close();

    cout << "Bellman-Ford completed successfully."
         << endl;

    cout << "Final result written to "
         << finalOutputFile
         << endl;

    return 0;
}
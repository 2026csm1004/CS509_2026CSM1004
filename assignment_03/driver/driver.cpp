#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../src/mst_helper.h"
#include "../../assignment_01/src/csr.h"

using namespace std;

int main()
{
    int algorithm;
    int test;

    cout << "To start MST press 1: ";
    cin >> algorithm;

    if(algorithm != 1)
    {
        cout << "Invalid choice\n";
        return 1;
    }

    cout << "\nEnter number of vertices for test case:\n";
    cout << "Available test cases: 10, 100, 500, 1000, 2000\n";
    cout << "Enter: ";
    cin >> test;


    string inputFile =
        "test/mst_" +
        to_string(test) +
        ".txt";

    string outputFile = "output.txt";


    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;

    int V;
    int source = 0;


    // Create CSR
    runCSR(
        inputFile,
        outputFile,
        row_ptr,
        col_idx,
        values,
        V,
        source
    );


    // Open output file for MST result
    ofstream output_file(outputFile);

    if(!output_file)
    {
        cout << "Error: Could not create output.txt\n";
        return 1;
    }


    // Run both Kruskal and Prim
    runMST(
        row_ptr,
        col_idx,
        values,
        V,
        output_file
    );


    output_file.close();

    cout << "\nMST completed successfully.\n";
    cout << "Results written to output.txt\n";

    return 0;
}
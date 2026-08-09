// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>

// #include "../../assignment_01/src/csr.h"
// #include "../../assignment_02/src/bellman_ford_helper.h"

// using namespace std;

// int main()
// {
//     string inputFile = "input.txt";

//     string csrOutputFile = "csr_output.txt";

//     string finalOutputFile = "output.txt";

//     // CSR data
//     vector<int> row_ptr;
//     vector<int> col_idx;
//     vector<int> values;

//     int V;
//     int source;

//     // ---------------------------------------
//     // Step 1: Convert adjacency list to CSR
//     // ---------------------------------------

//     runCSR(
//         inputFile,
//         csrOutputFile,
//         row_ptr,
//         col_idx,
//         values,
//         V,
//         source
//     );

//     // ---------------------------------------
//     // Step 2: Open final output file
//     // ---------------------------------------

//     ofstream output_file(finalOutputFile);

//     if(!output_file)
//     {
//         cout << "Error while opening output.txt"
//              << endl;

//         return 1;
//     }

//     // ---------------------------------------
//     // Step 3: Run Bellman-Ford
//     // ---------------------------------------

//     bellmanFordCSR(
//         row_ptr,
//         col_idx,
//         values,
//         V,
//         source,
//         output_file
//     );

//     output_file.close();

//     cout << "Bellman-Ford completed successfully."
//          << endl;

//     cout << "Final result written to "
//          << finalOutputFile
//          << endl;

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../../assignment_02/src/bellman_ford_helper.h"
#include "../../assignment_02/src/floyd_warshall_helper.h"

#include "../../assignment_01/src/csr.h"

using namespace std;

int main()
{
    int algorithm;
    int testCase;


    cout << "\nSelect Algorithm:\n";
    cout << "1. Bellman-Ford\n";
    cout << "2. Floyd-Warshall\n";

    cout << "\nEnter choice: ";
    cin >> algorithm;
     if (algorithm == 1){
        cout<<"\nEnter no of vertices for test case \n available test cases are 10, 100, 10000, 50000, 100000\n";
        cin >> testCase;
     }
     else if (algorithm == 2){
        cout<<"\nEnter no of vertices for test case \n available test cases are 10, 100, 500, 1000, 2000\n";
        cin >> testCase;
     }
    

    string inputFile;
   
    // -----------------------------------------
    // Select input file
    // -----------------------------------------

    if(algorithm == 1)
    {
        inputFile =
            "test/bellman_test/bf_" +
            to_string(testCase) +
            ".txt";
    }
    else if(algorithm == 2)
    {
        inputFile =
            "test/floyd_test/fw_" +
            to_string(testCase) +
            ".txt";
    }
    else
    {
        cout << "Invalid algorithm choice.\n";
        return 1;
    }

    // -----------------------------------------
    // Open output file
    // -----------------------------------------
 string resultFile = "output.txt";
    ofstream outputFile(resultFile);

    if(!outputFile)
    {
        cout << "Error: Could not create output.txt\n";
        return 1;
    }

    // -----------------------------------------
    // Run selected algorithm
    // -----------------------------------------

    if(algorithm == 1)
    {
        /*
         * Bellman-Ford section
         *
         * Your existing CSR function converts
         * the adjacency-list input into:
         *
         * row_ptr
         * col_idx
         * values
         * V
         * source
         */

        vector<int> row_ptr;
        vector<int> col_idx;
        vector<int> values;

        int V;
        int source;

        string csrOutputFile = "csr_output.txt";

        runCSR(
            inputFile,
            csrOutputFile,
            row_ptr,
            col_idx,
            values,
            V,
            source
        );

        bellmanFordCSR(
            row_ptr,
            col_idx,
            values,
            V,
            source,
            outputFile
        );
    }
    else if(algorithm == 2)
    {
        floydWarshall(
            inputFile,
            outputFile
        );
    }

    outputFile.close();

    cout << "\nAlgorithm completed successfully.\n";
    cout << "Result written to output.txt\n";

    return 0;
}
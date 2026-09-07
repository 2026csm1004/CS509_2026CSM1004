// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>

// #include "../src/vertex_coloring_helper.h"
// #include "../src/pagerank_helper.h"
// #include "../../assignment_01/src/csr.h"

// using namespace std;

// int main()
// {
//     int algorithm;
//     int test;

//     cout << "1. Vertex Coloring\n";
//     cout << "2. PageRank\n";
//     cout << "Choice : ";
//     cin >> algorithm;

//     if(algorithm != 1 && algorithm != 2)
//     {
//         cout << "Invalid Choice\n";
//         return 1;
//     }

//     cout << "\nChoose Test Case\n";

//     if(algorithm == 1)
//     {
//         cout << "1. 10 vertices\n";
//         cout << "2. 100 vertices\n";
//         cout << "3. 10000 vertices\n";
//         cout << "4. 50000 vertices\n";
//         cout << "5. 100000 vertices\n";
//     }
//     else
//     {
//         cout << "1. 10 vertices\n";
//         cout << "2. 100 vertices\n";
//         cout << "3. 1000 vertices\n";
//         cout << "4. 10000 vertices\n";
//         cout << "5. 50000 vertices\n";
//     }

//     cout << "Choice : ";
//     cin >> test;

//     if(test < 1 || test > 5)
//     {
//         cout << "Invalid Test Case\n";
//         return 1;
//     }

//     int testValue;

//     if(algorithm == 1)
//     {
//         int sizes[] = {10, 100, 10000, 50000, 100000};
//         testValue = sizes[test - 1];
//     }
//     else
//     {
//         int sizes[] = {10, 100, 1000, 10000, 50000};
//         testValue = sizes[test - 1];
//     }

//     string inputFile;

//     if(algorithm == 1)
//     {
//         inputFile =
//             "test/coloring_test/color_" +
//             to_string(testValue) +
//             ".txt";
//     }
//     else
//     {
//         inputFile =
//             "test/pagerank_test/pagerank_" +
//             to_string(testValue) +
//             ".txt";
//     }

//     string outputFile = "output.txt";
   

//     vector<int> row_ptr;
//     vector<int> col_idx;
//     vector<int> values;

//     int V = 0;
//     int source = 0;
//     int max_iterations = 0;

//     double damping = 0.0;
//     double tolerance = 0.0;

//     runCSR(
//     inputFile,
//     outputFile,
//     row_ptr,
//     col_idx,
//     values,
//     V,
//     source,
//     false
// );

//     ofstream output_file(outputFile);

//     if(!output_file)
//     {
//         cout << "Error: Could not create output.txt\n";
//         return 1;
//     }

//     if(algorithm == 1)
//     {
//         vertexColoring(
//             row_ptr,
//             col_idx,
//             V,
//             output_file
//         );

//         cout << "\nVertex Coloring completed successfully.\n";
//     }
//     else
//     {
//         pageRank(
//             row_ptr,
//             col_idx,
//             V,
//             damping,
//             tolerance,
//             max_iterations,
//             output_file
//         );

//         cout << "\nPageRank completed successfully.\n";
//     }

//     output_file.close();

//     cout << "Results written to output.txt\n";

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../src/vertex_coloring_helper.h"
#include "../src/pagerank_helper.h"
#include "../../assignment_01/src/csr.h"

using namespace std;

int main()
{
    int algorithm;
    int test;

    cout << "1. Vertex Coloring\n";
    cout << "2. PageRank\n";
    cout << "Choice : ";
    cin >> algorithm;

    if(algorithm != 1 && algorithm != 2)
    {
        cout << "Invalid Choice\n";
        return 1;
    }

    cout << "\nChoose Test Case\n";

    if(algorithm == 1)
    {
        cout << "1. 10 vertices\n";
        cout << "2. 100 vertices\n";
        cout << "3. 10000 vertices\n";
        cout << "4. 50000 vertices\n";
        cout << "5. 100000 vertices\n";
    }
    else
    {
        cout << "1. 10 vertices\n";
        cout << "2. 100 vertices\n";
        cout << "3. 1000 vertices\n";
        cout << "4. 10000 vertices\n";
        cout << "5. 50000 vertices\n";
    }

    cout << "Choice : ";
    cin >> test;

    if(test < 1 || test > 5)
    {
        cout << "Invalid Test Case\n";
        return 1;
    }

    int testValue;

    if(algorithm == 1)
    {
        int sizes[] = {10, 100, 10000, 50000, 100000};
        testValue = sizes[test - 1];
    }
    else
    {
        int sizes[] = {10, 100, 1000, 10000, 50000};
        testValue = sizes[test - 1];
    }

    string inputFile;

    if(algorithm == 1)
    {
        inputFile =
            "test/coloring_test/color_" +
            to_string(testValue) +
            ".txt";
    }
    else
    {
        inputFile =
            "test/pagerank_test/pagerank_" +
            to_string(testValue) +
            ".txt";
    }

    string outputFile = "output.txt";

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;

    int V = 0;
    int source = 0;

    double damping = 0.0;
    double tolerance = 0.0;
    int max_iterations = 0;


    // -----------------------------------
    // Read PageRank parameters
    // -----------------------------------

    if(algorithm == 2)
    {
        ifstream input(inputFile);

        if(!input)
        {
            cout << "Error: Could not open input file\n";
            return 1;
        }

        int E;

        input >> V >> E;

        // Skip adjacency list
        for(int i = 0; i < V; i++)
        {
            int vertex;
            int degree;

            input >> vertex >> degree;

            for(int j = 0; j < degree; j++)
            {
                int neighbour;
                input >> neighbour;
            }
        }

        string temp;

        input >> temp >> damping;
        input >> temp >> tolerance;
        input >> temp >> max_iterations;

        input.close();

        if(damping <= 0 || damping >= 1)
        {
            cout << "Invalid damping factor\n";
            return 1;
        }

        if(tolerance <= 0)
        {
            cout << "Invalid tolerance\n";
            return 1;
        }

        if(max_iterations <= 0)
        {
            cout << "Invalid maximum iterations\n";
            return 1;
        }
    }


    // -----------------------------------
    // Convert adjacency list to CSR
    // -----------------------------------

    runCSR(
        inputFile,
        outputFile,
        row_ptr,
        col_idx,
        values,
        V,
        source,
        false
    );


    // -----------------------------------
    // Run selected algorithm
    // -----------------------------------

    ofstream output_file(outputFile);

    if(!output_file)
    {
        cout << "Error: Could not create output.txt\n";
        return 1;
    }

    if(algorithm == 1)
    {
        vertexColoring(
            row_ptr,
            col_idx,
            V,
            output_file
        );

        cout << "\nVertex Coloring completed successfully.\n";
    }
    else
    {
        pageRank(
            row_ptr,
            col_idx,
            V,
            damping,
            tolerance,
            max_iterations,
            output_file
        );

        cout << "\nPageRank completed successfully.\n";
    }

    output_file.close();

    cout << "Results written to output.txt\n";

    return 0;
}
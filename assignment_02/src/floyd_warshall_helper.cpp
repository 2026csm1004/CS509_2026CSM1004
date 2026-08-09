#include "floyd_warshall_helper.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

void floydWarshall(
    const string& inputFile,
    ofstream& outputFile
)
{
    ifstream input_file(inputFile);

    if(!input_file)
    {
        outputFile << "Error: Could not open input file.\n";
        return;
    }

    // -----------------------------------------
    // Read number of vertices
    // -----------------------------------------

    int V;

    input_file >> V;

    // Consume the remaining newline
    string line;
    getline(input_file, line);

    // -----------------------------------------
    // Read dense matrix
    // -----------------------------------------

    const int INF = 1000000000;

    vector<vector<int>> distance(
        V,
        vector<int>(V, INF)
    );

    for(int i = 0; i < V; i++)
    {
        getline(input_file, line);

        stringstream ss(line);

        for(int j = 0; j < V; j++)
        {
            string value;

            ss >> value;

            if(value == "INF")
            {
                distance[i][j] = INF;
            }
            else
            {
                distance[i][j] = stoi(value);
            }
        }
    }

    input_file.close();

    // -----------------------------------------
    // Floyd-Warshall algorithm
    // -----------------------------------------

    auto start = chrono::high_resolution_clock::now();

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            // If i cannot reach k, skip
            if(distance[i][k] == INF)
                continue;

            for(int j = 0; j < V; j++)
            {
                // If k cannot reach j, skip
                if(distance[k][j] == INF)
                    continue;

                int newDistance =
                    distance[i][k] +
                    distance[k][j];

                if(newDistance < distance[i][j])
                {
                    distance[i][j] = newDistance;
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();

    // -----------------------------------------
    // Detect negative-weight cycle
    // -----------------------------------------

    bool negativeCycle = false;

    for(int i = 0; i < V; i++)
    {
        if(distance[i][i] < 0)
        {
            negativeCycle = true;
            break;
        }
    }

    // -----------------------------------------
    // Write output
    // -----------------------------------------

//     outputFile << "Algorithm: Floyd-Warshall\n";
   

//     outputFile << "Distance matrix:\n";

//     for(int i = 0; i < V; i++)
//     {
//         for(int j = 0; j < V; j++)
//         {
//             if(distance[i][j] == INF)
//             {
//                 outputFile << "INF";
//             }
//             else
//             {
//                 outputFile << distance[i][j];
//             }

//             if(j < V - 1)
//                 outputFile << " ";
//         }

//         outputFile << "\n";
//     }

//     if(negativeCycle)
//     {
//         outputFile << "Negative cycle: detected\n";
//     }
//     else
//     {
//         outputFile << "Negative cycle: none\n";
//     }

//     outputFile << "Execution time: "
//                << executionTime
//                << " ms\n";
// }
outputFile << "Algorithm: Floyd-Warshall\n";

if(negativeCycle)
{
    // Do NOT print the distance matrix
    outputFile << "Negative cycle: true\n";
}
else
{
    // Print matrix only when there is NO negative cycle
    outputFile << "Distance matrix:\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(distance[i][j] == INF)
            {
                outputFile << "INF";
            }
            else
            {
                outputFile << distance[i][j];
            }

            if(j < V - 1)
            {
                outputFile << " ";
            }
        }

        outputFile << "\n";
    }

    outputFile << "Negative cycle: false\n";
}

outputFile << "Execution time: "
           << executionTime
           << " ms\n";
}
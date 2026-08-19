#include "bellman_ford_helper.h"
#include <chrono>

using namespace std;

void bellmanFordCSR(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    int source,
    ofstream& output_file
)
{
    
    const int INF = 1000000000;

    vector<int> distance(V, INF);

    distance[source] = 0;


     auto start = chrono::high_resolution_clock::now();
    for(int iteration = 0; iteration < V - 1; iteration++)
    {
        bool updated = false;

        for(int u = 0; u < V; u++)
        {
            // Vertex u cannot help if it is unreachable
            if(distance[u] == INF)
                continue;

            // Traverse all outgoing edges of u
            for(int i = row_ptr[u];
                i < row_ptr[u + 1];
                i++)
            {
                int v = col_idx[i];
                int weight = values[i];

                // Relaxation
                if(distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    updated = true;
                }
            }
        }

        // No update means we are already done
        if(!updated)
            break;
    }

    auto end = chrono::high_resolution_clock::now();
      double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();


    bool negative_cycle = false;

    for(int u = 0; u < V; u++)
    {
        if(distance[u] == INF)
            continue;

        for(int i = row_ptr[u];
            i < row_ptr[u + 1];
            i++)
        {
            int v = col_idx[i];
            int weight = values[i];
 
            if(distance[u] + weight < distance[v])
            {
                negative_cycle = true;
                break;
            }
        }

        if(negative_cycle)
            break;
    }


    output_file << "Algorithm: Bellman-Ford\n";
  

    output_file << "Source Vertex: "
                << source << "\n\n";

    if(negative_cycle)
    {
        output_file << "Negative cycle : true.\n";
        return;
    }

    output_file << "Shortest distances:\n";

    for(int vertex = 0; vertex < V; vertex++)
    {
        output_file << "Vertex "
                    << vertex
                    << " : ";

               

        if(distance[vertex] == INF)
            output_file << "INF";
        else
            output_file << distance[vertex];

        output_file << "\n";
    }
    output_file<<"Negative cycle : none\n";   
        output_file << "Time taken : " << executionTime << " ms\n";  
}
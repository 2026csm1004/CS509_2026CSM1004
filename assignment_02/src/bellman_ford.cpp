#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellman_ford(const vector<int>& row_ptr,
                  const vector<int>& col_idx,
                  const vector<int>& values,
                  int V,
                  int source)
{
    const int INF = INT_MAX;

    
    vector<int> dist(V, INF);

    
    dist[source] = 0;

   
    for (int i = 0; i < V - 1; i++)
    {
        bool updated = false;

        for (int u = 0; u < V; u++)
        {
            
            if (dist[u] == INF)
                continue;

         
            for (int j = row_ptr[u]; j < row_ptr[u + 1]; j++)
            {
                int v = col_idx[j];
                int weight = values[j];

                
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    updated = true;
                }
            }
        }

       
        if (!updated)
            break;
    }

 
    bool negative_cycle = false;

    for (int u = 0; u < V; u++)
    {
        if (dist[u] == INF)
            continue;

        for (int j = row_ptr[u]; j < row_ptr[u + 1]; j++)
        {
            int v = col_idx[j];
            int weight = values[j];

           
            if (dist[u] + weight < dist[v])
            {
                negative_cycle = true;
                break;
            }
        }

        if (negative_cycle)
            break;
    }

   
    cout << "Algorithm: Bellman-Ford" << endl;
    cout << "Source: " << source << endl;

    if (negative_cycle)
    {
        cout << "Negative cycle: found" << endl;
        return;
    }

    cout << "Vertex Distance" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << i << " ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    cout << "Negative cycle: none" << endl;
}
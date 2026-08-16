#include "mst_helper.h"
#include <chrono>
#include <algorithm>
#include <climits>

using namespace std;


struct Edge
{
    int u;
    int v;
    int weight;
};



int findParent(vector<int>& parent, int x)
{
    if(parent[x] == x)
        return x;

    parent[x] = findParent(parent, parent[x]);

    return parent[x];
}



void kruskalMST(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    ofstream& output_file
)
{
    auto start = chrono::high_resolution_clock::now();

    vector<Edge> edges;

    for(int u = 0; u < V; u++)
    {
        for(int i = row_ptr[u];
            i < row_ptr[u + 1];
            i++)
        {
            int v = col_idx[i];
            int weight = values[i];


            if(u < v)
            {
                edges.push_back({u, v, weight});
            }
        }
    }

    sort(edges.begin(), edges.end(),
        [](Edge a, Edge b)
        {
            return a.weight < b.weight;
        }
    );
    vector<int> parent(V);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;

    int totalWeight = 0;

    // Kruskal
    for(Edge edge : edges)
    {
        int pu = findParent(parent, edge.u);
        int pv = findParent(parent, edge.v);

        if(pu != pv)
        {
            parent[pu] = pv;

            mst.push_back(edge);
            totalWeight += edge.weight;

            if(mst.size() == V - 1)
                break;
        }
    }

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();


    // Output
    output_file << "Algorithm: Kruskal's MST\n";

    output_file << "MST edges:\n";

    for(Edge edge : mst)
    {
        output_file << edge.u << " "
                    << edge.v << " "
                    << edge.weight << "\n";
    }

    output_file << "Total MST weight: "
                << totalWeight << "\n";

    output_file << "Execution time: "
                << executionTime
                << " ms\n\n";
}



void primMST(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    ofstream& output_file
)
{
    auto start = chrono::high_resolution_clock::now();

    const int INF = INT_MAX;

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> used(V, false);

    // Start from vertex 0
    key[0] = 0;

    for(int count = 0; count < V; count++)
    {
        int u = -1;

        // Find minimum key vertex
        for(int i = 0; i < V; i++)
        {
            if(!used[i] &&
               (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        if(u == -1 || key[u] == INF)
            break;

        used[u] = true;

        // Check neighbours using CSR
        for(int i = row_ptr[u];
            i < row_ptr[u + 1];
            i++)
        {
            int v = col_idx[i];
            int weight = values[i];

            if(!used[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();


    // Output
    output_file << "Algorithm: Prim's MST\n";

    output_file << "MST edges:\n";

    int totalWeight = 0;

    for(int v = 1; v < V; v++)
    {
        if(parent[v] != -1)
        {
            output_file << parent[v] << " "
                        << v << " "
                        << key[v] << "\n";

            totalWeight += key[v];
        }
    }

    output_file << "Total MST weight: "
                << totalWeight << "\n";

    output_file << "Execution time: "
                << executionTime
                << " ms\n\n";
}


void runMST(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    ofstream& output_file
)
{
    // Run Kruskal
    kruskalMST(
        row_ptr,
        col_idx,
        values,
        V,
        output_file
    );


    // Run Prim
    primMST(
        row_ptr,
        col_idx,
        values,
        V,
        output_file
    );
}
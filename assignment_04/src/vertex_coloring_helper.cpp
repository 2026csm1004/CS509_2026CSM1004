#include "vertex_coloring_helper.h"
#include <chrono>
#include <algorithm>

using namespace std;

void vertexColoring(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    int V,
    ofstream& output_file
)
{
    auto start = chrono::high_resolution_clock::now();

    vector<int> degree(V);
    vector<int> order(V);
    vector<int> color(V, -1);

    for(int v = 0; v < V; v++)
    {
        degree[v] = row_ptr[v + 1] - row_ptr[v];
        order[v] = v;
    }

    // Welsh-Powell: non-increasing degree.
    // Vertex id is used as a deterministic tie-breaker.
    sort(order.begin(), order.end(),
        [&](int a, int b)
        {
            if(degree[a] != degree[b])
                return degree[a] > degree[b];

            return a < b;
        }
    );

    int colors_used = 0;

    for(int index = 0; index < V; index++)
    {
        int u = order[index];

        vector<bool> used(colors_used, false);

        for(int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
        {
            int v = col_idx[i];

            if(color[v] >= 0 && color[v] < colors_used)
                used[color[v]] = true;
        }

        int chosen = 0;

        while(chosen < colors_used && used[chosen])
            chosen++;

        if(chosen == colors_used)
            colors_used++;

        color[u] = chosen;
    }

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();

    bool valid = true;

    for(int u = 0; u < V && valid; u++)
    {
        for(int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
        {
            int v = col_idx[i];

            if(color[u] == color[v])
            {
                valid = false;
                break;
            }
        }
    }

    output_file << "Algorithm: Greedy Vertex Coloring\n";
    output_file << "Vertex colors:\n";

    for(int v = 0; v < V; v++)
        output_file << v << " " << color[v] << "\n";

    output_file << "Colors used: " << colors_used << "\n";
    output_file << "Valid coloring: "
                << (valid ? "true" : "false") << "\n";
    output_file << "Execution time: "
                << executionTime << " ms\n";
}

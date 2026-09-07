#include "pagerank_helper.h"
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;

void pageRank(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    int V,
    double damping,
    double tolerance,
    int max_iterations,
    ofstream& output_file
)
{
    auto start = chrono::high_resolution_clock::now();

    vector<double> rank(V, 1.0 / V);
    vector<double> next_rank(V, 0.0);

    int iterations = 0;
    bool converged = false;

    for(int iteration = 0; iteration < max_iterations; iteration++)
    {
        double dangling_sum = 0.0;

        for(int u = 0; u < V; u++)
        {
            int outdegree = row_ptr[u + 1] - row_ptr[u];

            if(outdegree == 0)
                dangling_sum += rank[u];
        }

        double base =
            (1.0 - damping) / V +
            damping * dangling_sum / V;

        fill(next_rank.begin(), next_rank.end(), base);

        for(int u = 0; u < V; u++)
        {
            int outdegree = row_ptr[u + 1] - row_ptr[u];

            if(outdegree == 0)
                continue;

            double contribution =
                damping * rank[u] / outdegree;

            for(int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
            {
                int v = col_idx[i];
                next_rank[v] += contribution;
            }
        }

        double change = 0.0;

        for(int v = 0; v < V; v++)
            change += fabs(next_rank[v] - rank[v]);

        rank.swap(next_rank);

        iterations = iteration + 1;

        if(change <= tolerance)
        {
            converged = true;
            break;
        }
    }

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();

    double sum = 0.0;

    for(int v = 0; v < V; v++)
        sum += rank[v];

    int top_vertex = 0;

    for(int v = 1; v < V; v++)
    {
        if(rank[v] > rank[top_vertex])
            top_vertex = v;
    }

    output_file << fixed << setprecision(6);

    output_file << "Algorithm: PageRank\n";
    output_file << "Damping: " << damping << "\n";
    output_file << "Vertex ranks:\n";

    for(int v = 0; v < V; v++)
        output_file << v << " " << rank[v] << "\n";

    output_file << "Sum of ranks: " << sum << "\n";
    output_file << "Top vertex: " << top_vertex << "\n";
    output_file << "Iterations: " << iterations << "\n";
    output_file << "Converged: "
                << (converged ? "true" : "false") << "\n";
    output_file << "Execution time: "
                << executionTime << " ms\n";
}

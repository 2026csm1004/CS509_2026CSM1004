#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<ctime>

using namespace std;

int main() {
  clock_t start, end;
  start = clock();

    bool isWeighted = true;

    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    if (!input_file) {
        cout << "error while opening input file!" << endl;
        return 1;
    }

    int V, E;
    input_file >> V >> E;

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;

    row_ptr.push_back(0);

    for (int i = 0; i < V; i++) {

        int vertex, degree;
        input_file >> vertex >> degree;

        for (int j = 0; j < degree; j++) {

            int neighbour;
            input_file >> neighbour;
            col_idx.push_back(neighbour);

            if (isWeighted) {
                int weight;
                input_file >> weight;
                values.push_back(weight);
            }
        }

        row_ptr.push_back(col_idx.size());
    }
    end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    double time_in_ms = time_taken * 1000;
    string temp;
    int source;

    input_file >> temp;     // Reads "SOURCE"
    input_file >> source;


    // Write to output file
    output_file << "row pointer:\n";
    for (int x : row_ptr)
        output_file << x << " ";

    output_file << "\ncolumn index:\n";
    for (int x : col_idx)
        output_file << x << " ";

    if (isWeighted) {

        output_file << "\nweight:\n";
        for (int x : values)
            output_file << x << " ";
    }

    output_file << "\nsource Vertex:\n";
    output_file << source << endl;
    output_file << "Execution time: " << time_in_ms << " ms" << endl;

    input_file.close();
    output_file.close();

    return 0;
}
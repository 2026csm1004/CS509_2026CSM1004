#include "csr_helper.h"

using namespace std;

//---------------------------
// Unweighted Graph
//---------------------------

void adj_to_csr(ifstream &input_file,
                vector<int> &row_ptr,
                vector<int> &col_idx,
                int &V,
                int &E,
                int &source)
{
    input_file >> V >> E;

    row_ptr.push_back(0);

    for(int i=0;i<V;i++)
    {
        int vertex, degree;

        input_file >> vertex >> degree;

        for(int j=0;j<degree;j++)
        {
            int neighbour;

            input_file >> neighbour;

            col_idx.push_back(neighbour);
        }

        row_ptr.push_back(col_idx.size());
    }

    string temp;

    input_file >> temp;
    input_file >> source;
}


void weighted_adj_to_csr(ifstream &input_file,
                         vector<int> &row_ptr,
                         vector<int> &col_idx,
                         vector<int> &values,
                         int &V,
                         int &E,
                         int &source)
{
    input_file >> V >> E;

    row_ptr.push_back(0);

    for(int i=0;i<V;i++)
    {
        int vertex, degree;

        input_file >> vertex >> degree;

        for(int j=0;j<degree;j++)
        {
            int neighbour, weight;

            input_file >> neighbour >> weight;

            col_idx.push_back(neighbour);
            values.push_back(weight);
        }

        row_ptr.push_back(col_idx.size());
    }

    string temp;

    input_file >> temp;
    input_file >> source;
}
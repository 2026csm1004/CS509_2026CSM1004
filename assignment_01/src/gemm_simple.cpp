#include "gemm.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

void runGEMM(const string &inputFile, const string &outputFile)
{
    int bs = 10;
    clock_t start1 , end1,start2 , end2;
  ifstream matrix_file(inputFile);
  if (!matrix_file.is_open()) { 
    cout << "Error opening file." << endl;
    return ;
  }

  int r1, c1, c2;
matrix_file >> r1 >> c1 >> c2;

 vector<vector<int>> A(r1, vector<int>(c1));

for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c1; j++) {
       // matrix_file >> A[i][j];
       A[i][j] = rand() % 10; // Generate random numbers between 0 and 9
    }
}


 vector<vector<int>> B(c1, vector<int>(c2));

for(int i = 0; i < c1; i++) {
    for(int j = 0; j < c2; j++) {
        // matrix_file >> B[i][j];
        B[i][j] = rand() % 10; // Generate random numbers between 0 and 9
    }
}


//// blocking algo 
start1 = clock();
vector<vector<int>> CB(r1, vector<int>(c2, 0));
for(int ii=0; ii<r1; ii+=bs)
{
    for(int jj=0; jj<c2; jj+=bs)
    {
        for(int kk=0; kk<c1; kk+=bs) 
        {
            for(int i=ii; i<min(ii+bs,r1); i++)
            {
                for(int j=jj; j<min(jj+bs,c2); j++)
                {
                    for(int k=kk; k<min(kk+bs,c1); k++)
                    {
                        CB[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
    }
}
end1 = clock();
double time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
//////blocking algo end 


///simple multiplication algo
start2 = clock();
vector<vector<int>> C(r1, vector<int>(c2, 0));
   for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
end2 = clock();
double time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;

    ofstream output_file(outputFile);
    if (!output_file.is_open()) {
        cout << "Error opening output file." << endl;
        return ;
    }
    output_file << "Algorithm: GEMM Simple" << endl<<"Result Matrix: " << endl;
//     output_file << r1 << " " << c2 << endl;
//     for (int i = 0; i < C.size(); i++) {
//     for (int j = 0; j < C[i].size(); j++) {
//         output_file << C[i][j] << " ";
//     }
//     output_file << endl;
// }
output_file <<"Execution time : " << time_taken2 << " seconds" << endl;

output_file << endl;

///output for the blocked matrix multiplication
    output_file << "Algorithm: GEMM Blocked" << endl<<"Result Matrix: " << endl;
    // output_file << r1 << " " << c2 << endl;
    // for (int i = 0; i < CB.size(); i++) {
    //     for (int j = 0; j < CB[i].size(); j++) {
    //         output_file << CB[i][j] << " ";
    //     }
    //     output_file << endl;
    // }
    output_file <<"Execution time : " << time_taken1 << " seconds" << endl;

    matrix_file.close();
    output_file.close();

    return ;
}

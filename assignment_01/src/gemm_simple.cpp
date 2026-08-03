#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main (){
  ifstream matrix_file("input_matrix.txt");
  if (!matrix_file.is_open()) { 
    cout << "Error opening file." << endl;
    return 1;
  }

  int r1, c1, c2;
matrix_file >> r1 >> c1 >> c2;

 vector<vector<int>> A(r1, vector<int>(c1));

for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c1; j++) {
        matrix_file >> A[i][j];
    }
}


 vector<vector<int>> B(c1, vector<int>(c2));

for(int i = 0; i < c1; i++) {
    for(int j = 0; j < c2; j++) {
        matrix_file >> B[i][j];
    }
}
vector<vector<int>> C(r1, vector<int>(c2, 0));
   for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    ofstream output_file("output_matrix.txt");
    if (!output_file.is_open()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    output_file << r1 << " " << c2 << endl;
    for (int i = 0; i < C.size(); i++) {
    for (int j = 0; j < C[i].size(); j++) {
        output_file << C[i][j] << " ";
    }
    output_file << endl;
}
       
    

    matrix_file.close();
    output_file.close();

    return 0;
}

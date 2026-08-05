#include <iostream>
#include "../src/csr.h"
#include "../src/gemm.h"

using namespace std;

int main()
{
    int algo, test;

    cout << "1. GEMM\n";
    cout << "2. CSR\n";
    cout << "Choice : ";
    cin >> algo;

    cout << "\nChoose Test Case\n";
    cout << "1. Test1\n";
    cout << "2. Test2\n";
    cout << "3. Test3\n";
    cout << "Choice : ";
    cin >> test;

    string inputFile;
    string outputFile = "output.txt";

    if(algo == 1)
        inputFile = "Tests/gemm_test/gemm_test_0" + to_string(test) + ".txt";
    else
        inputFile = "Tests/csr_test/csr_test_0" + to_string(test) + ".txt";

    if(algo == 1)
        runGEMM(inputFile, outputFile);
    else if(algo == 2)
        runCSR(inputFile, outputFile);
    else
        cout << "Invalid Choice\n";

    return 0;
}

Course: CS509 ASSIGNMENT 01

This repository contains the implementation of **Compressed Sparse Row (CSR)** representation for sparse matrices and **General Matrix Multiplication (GEMM)** algorithms developed as part of the CS509 laboratory assignment.

The objectives of this assignment are:

- To understand and implement the Compressed Sparse Row (CSR) storage format for sparse matrices.
- To perform efficient matrix multiplication using the standard GEMM algorithm.
- To implement blocked (cache-friendly) matrix multiplication and compare its performance with the standard implementation.
- To analyze the execution time of different matrix multiplication approaches.
- To develop modular and reusable C++ code using separate driver and source files.

NAME: AJAY KUMAR
ENTRY NO : 2026CSM1004
ASSIGNMENT TYPE : INDIVIDUAL

PROGRAMMING LANGUAGE USED : C++
COMPILER : GNU G++ (MinGW-w64)
COMPILER VERSION : (MinGW.org GCC-6.3.0-1) 6.3.0
git version 2.53.0.windows.1


Directory structure:
CS509_2026CSM1004/
│
├── assignment_01/
│   ├── driver/
│   │   └── driver.cpp
│   │
│   ├── src/
│   │   ├── csr.h
│   │   ├── csr_implementation.cpp
│   │   ├── gemm.h
│   │   ├── gemm_simple.cpp
│   │   └── gemm_blocking.cpp
│   │
│   ├── tests/
│   │   ├── csr_test/
│   │   └── gemm_test/
│   │
│   ├── driver.exe
│   ├── output.txt
│   └── readme.md
│
└── README.md

PURPUSE OF MAIN FOLDERS:
DRIVER: CONTAIN THE driver.cpp 
src: contain the required helper function 
tests : contain the test cases for both gemm and csr
output.txt: hold the result value 
  

#instruction to run

compilation: g++ driver/driver.cpp src/csr_implementation.cpp src/gemm_simple.cpp -I src 
-o driver   
  
execute : ./driver.exe

GEMM RESULT TABLE 
| Test File        | Input                |  Simple (ms) | Block (ms) | BS | Status  |
| ---------------- | -------------------- |  ----------: | ---------: | -: | :----:  |
| gemm_test_01.txt | 150×150, 150×150     |         0.063 |     0.147 | 12 |    ✅   |
| gemm_test_02.txt | 500×500, 500×500     |         2.703 |      3.05 | 12 |    ✅   |
| gemm_test_03.txt | 1200×1200, 1200×1200 |         41.996 |   40.597 | 12 |    ✅   |




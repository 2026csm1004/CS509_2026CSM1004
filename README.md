# CS509_2026CSM1004

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



ourse: CS509 ASSIGNMENT 02

This repository contains the implementation of **Bellman-Ford** and **Floyd-Warshall** algorithms for solving the **Single-Source Shortest Path (SSSP)** and **All-Pairs Shortest Path (APSP)** problems, developed as part of the CS509 laboratory assignment.

The objectives of this assignment are:

* To understand and implement the **Bellman-Ford algorithm** for finding the shortest paths from a single source vertex to all other vertices in a weighted graph.
* To implement the **Floyd-Warshall algorithm** for finding the shortest paths between every pair of vertices in a weighted graph.
* To handle graphs containing **positive and negative edge weights** using appropriate shortest-path algorithms.
* To detect and identify **negative-weight cycles** where applicable.
* To analyze and compare the **time and space complexity** of Bellman-Ford and Floyd-Warshall algorithms.
* To evaluate the execution time of the algorithms for graphs of different sizes.
* To develop **modular and reusable C++ code** using separate driver, source, and header files.
* To generate and evaluate different test cases to study the performance and scalability of the implemented algorithms.


NAME: AJAY KUMAR
ENTRY NO : 2026CSM1004
ASSIGNMENT TYPE : INDIVIDUAL

PROGRAMMING LANGUAGE USED : C++
COMPILER : GNU G++ (MinGW-w64)
COMPILER VERSION : (MinGW.org GCC-6.3.0-1) 6.3.0
git version 2.53.0.windows.1


Directory structure:
assignment_02/
│
├── driver/
│   └── driver.cpp
│
├── src/
│   ├── bellman_ford_helper.cpp
│   ├── bellman_ford_helper.h
│   ├── floyd_warshall_helper.cpp
│   └── floyd_warshall_helper.h
│
├── test/
│   ├── bellman_test/
│   └── floyd_test/
│
└── tool/
|
|
|___output.txt
|
|___shortest_path.exe
PURPUSE OF MAIN FOLDERS:
DRIVER: CONTAIN THE driver.cpp 
src: contain the required helper function 
tests : contain the test cases for both bellman ford and floyd_test
output.txt: hold the result value 
  

#instruction to wrapper

compilation: g++ -std=c++14 wrapper.cpp -o wrapper.exe                  
  
execute : ./wrapper.exe

| Test File        | Input                | time (ms)   | negative   | Status  |
| ---------------- | -------------------- | ----------: | ---------: |  :----: |
| bf_10.txt        | 10 v                 |       0.063 |     NONE |    ✅   |
| bf_100.txt       | 100 v                |       0.073 |     NONE |    ✅   |
| bf_10000.txt     | 1000v                |         0.0 |     NONE |    ✅   |
| bf_50000.txt     | 50000                |       42.118|     NONE |    ✅   |
| bf_100000.txt    | 100000v              |       165.42|     NONE |    ✅   |
| fw_10.txt        | 10 v                 |       0.0   |     NONE |    ✅   |
| fw_100.txt       | 100 v                |       55.809|     NONE |    ✅   |
| fw_500.txt       | 500                  |      3335   |     NONE |    ✅   |
| fw_1000.txt      | 1000v                |      25608  |     NONE |    ✅   |
| fw_2000.txt      | 2000v                |      185016 |     NONE |    ✅   |

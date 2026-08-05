# Graph Algorithms using CSR

## Course Information

**Course:** CS509 – Design and Analysis of Algorithms Lab  
**Assignment:** Graph Algorithms using Compressed Sparse Row (CSR)

---

## Student Details

| Name | Entry Number |
|------|--------------|
| Your Name | 2026CSMXXXX |

> If this is a pair assignment:

| Name | Entry Number |
|------|--------------|
| Student 1 | 2026CSMXXXX |
| Student 2 | 2026AIMXXXX |

---

## Programming Environment

- **Programming Language:** C++
- **Compiler:** g++
- **C++ Standard:** C++17
- **Operating System:** Windows 10/11
- **IDE Used:** Visual Studio Code
- **Build Command:**

```bash
g++ driver/driver.cpp src/csr_helper.cpp src/bfs_helper.cpp src/dfs_helper.cpp src/sssp_helper.cpp -o graph.exe
```

---

## Repository Structure

```
assignment_01/
│
├── driver/
│   └── driver.cpp
│
├── src/
│   ├── csr_helper.h
│   ├── csr_helper.cpp
│   ├── bfs_helper.h
│   ├── bfs_helper.cpp
│   ├── dfs_helper.h
│   ├── dfs_helper.cpp
│   ├── sssp_helper.h
│   └── sssp_helper.cpp
│
├── test/
│   ├── bfs_test/
│   ├── dfs_test/
│   └── sssp_test/
│
├── graph_generator.cpp
├── output.txt
└── README.md
```

### Folder Description

| Folder/File | Purpose |
|-------------|---------|
| `driver/` | Contains the common driver program used to execute different graph algorithms. |
| `src/` | Contains all helper functions and algorithm implementations. |
| `test/` | Stores input graph files for BFS, DFS, and SSSP. |
| `graph_generator.cpp` | Generates input graphs of different sizes. |
| `output.txt` | Stores the output of the selected algorithm. |
| `README.md` | Project documentation and execution instructions. |

---

# Compilation

Compile the project using:

```bash
g++ driver/driver.cpp src/csr_helper.cpp src/bfs_helper.cpp src/dfs_helper.cpp src/sssp_helper.cpp -o graph.exe
```

---

# Running the Program

Run the executable:

```bash
./graph.exe
```

or on Windows:

```powershell
graph.exe
```

The driver will ask the user to:

1. Select the graph algorithm (BFS, DFS, or SSSP).
2. Select the graph size.
3. Execute the algorithm.
4. Display the output in `output.txt`.

---

## Graph Generator

Compile:

```bash
g++ graph_generator.cpp -o graph_generator.exe
```

Run:

```powershell
graph_generator.exe
```

This creates graph input files for the required graph sizes.

---

## Test File Format

The graph input is provided as an **Adjacency List**.

### Unweighted Graph (BFS/DFS)

```
V E
vertex degree neighbour1 neighbour2 ...
...
SOURCE source_vertex
```

Example:

```
5 6
0 2 1 2
1 2 2 3
2 1 4
3 1 4
4 0
SOURCE 0
```

---

### Weighted Graph (SSSP)

```
V E
vertex degree neighbour1 weight1 neighbour2 weight2 ...
...
SOURCE source_vertex
```

Example:

```
5 6
0 2 1 3 2 5
1 2 2 1 3 4
2 1 4 2
3 1 4 3
4 0
SOURCE 0
```

---

## Output Format

Each algorithm writes its result to `output.txt`.

Example:

```
Algorithm: BFS
Source: 0
Traversal:
0 1 2 3 4

Execution time: 0.034 ms
```

---

## Runtime Measurement

- Graph input is read as an adjacency list.
- The adjacency list is converted to CSR before the algorithm begins.
- CSR conversion is treated as preprocessing.
- Execution time is measured **only for the graph algorithm**.
- Timing starts immediately before the algorithm call and stops immediately after the algorithm finishes.

---

## Algorithms Implemented

- Breadth First Search (BFS)
- Depth First Search (DFS)
- Single Source Shortest Path (Dijkstra using CSR)

---

## Test Graph Sizes

Graphs were generated for the following vertex counts:

- 10
- 100
- 1000
- 50000
- 100000

---

## Results

| Algorithm | Vertices | Edges | Execution Time (ms) |
|-----------|---------:|------:|--------------------:|
| BFS | 10 | | |
| BFS | 100 | | |
| BFS | 1000 | | |
| BFS | 50000 | | |
| BFS | 100000 | | |
| DFS | 10 | | |
| DFS | 100 | | |
| DFS | 1000 | | |
| DFS | 50000 | | |
| DFS | 100000 | | |
| SSSP | 10 | | |
| SSSP | 100 | | |
| SSSP | 1000 | | |
| SSSP | 50000 | | |
| SSSP | 100000 | | |
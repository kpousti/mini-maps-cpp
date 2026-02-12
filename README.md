# Mini Maps (C++)

A lightweight graph engine implementing:

- BFS connectivity check  
- Dijkstra weighted shortest path  
- Path reconstruction  
- Adjacency list representation  

---

## Why this exists

Mini Maps was built to implement and deeply understand core graph algorithms in C++ from scratch.

Rather than relying on external libraries, this project focuses on:

- Manual adjacency list construction  
- Efficient shortest path computation using a priority queue  
- Explicit path reconstruction  
- Clean systems-level implementation with performance in mind  

The goal is to bridge graph theory with practical, compile-and-run C++ systems code.

---

## Prerequisites

Before building, make sure you have:

- A C++17 compatible compiler (`g++` or `clang++`)
- macOS or Linux terminal (Windows users: WSL recommended)

### macOS
```bash
xcode-select --install
```

### Ubuntu / Debian
```bash
sudo apt-get install build-essential
```

---

## Build

```bash
g++ --std=c++17 -O2 -Wall -Wextra main.cpp -o mini_maps
```

---

## Run

```bash
./mini_maps < examples/sample_input.txt
```

The program reads graph input from standard input (stdin).  
See `examples/sample_input.txt` for a working example of the expected format.

---

## Example

Example input (`examples/sample_input.txt`):

```
5 6
0 1 4
0 2 2
1 2 5
1 3 10
2 4 3
4 3 4
```

Example output:

```
Shortest path from 0 to 3:
0 -> 2 -> 4 -> 3
Distance: 9
```

---

## Time Complexity

- **BFS:** O(V + E)  
- **Dijkstra (binary heap):** O((V + E) log V)  
- **Adjacency list storage:** O(V + E)

Where:
- V = number of vertices  
- E = number of edges  

---

## Project Structure

```
mini-maps-cpp/
│
├── main.cpp
├── examples/
│   └── sample_input.txt
└── README.md
```

---

## Concepts Covered

- Graph traversal (O(V + E))  
- Priority queue optimization  
- Early exit strategy  
- Systems-level performance considerations  

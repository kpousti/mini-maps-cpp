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

The goal is to bridge theory (graph algorithms) with practical, compile-and-run C++ systems code.

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

## Concepts Covered

- Graph traversal (O(V + E))  
- Priority queue optimization  
- Early exit strategy  
- Systems-level performance considerations  

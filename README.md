# Graph traversal and search algorithms
Graph path search algorithms(a*, depth first search, breadth first search, uniform cost search, greedy search) implemented in C++.

## Features
- Clean code
- Reading graph data from text file
- Reading graph data from user by console
- providing structured, well-designed framework to implement other graph search algortihms.
- Simple CLI interface

## Algortihms
- A* graph search algorithm.
- Breadth-first graph search algorithm.
- Depth-first graph search algorithm.
- Greedy graph search algorithm with heuristics.
- Uniform-Cost graph search algorithm with heuristic.

## Launch
Only g++ compiler is needed, and makefile to compile and link dependencies.

### Graph data entry
The program can read graph data via two methods either from program console or from DAT/links.data. each link should be entered individually in line as tribled data values to describe the entered edge/link.

![image](https://user-images.githubusercontent.com/77664485/109084321-4114db00-7710-11eb-8aa8-fd5d3924ebf7.png)
In the previous graph, data should be entered as follows:
a b cost
a c cost
b c cost
c d cost
, where cost should be replaced with the edge cost values as in weighted graphs.

### Makefile
using Makefile, only command make to create base2 which is executable file to run the program.

![image](https://user-images.githubusercontent.com/77664485/109085411-47a45200-7712-11eb-84a5-2089899137d9.png)


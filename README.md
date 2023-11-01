# Parallel Programming

A comprehensive repository dedicated to demonstrating various facets of parallel programming in C++.

## Repository Contents

This repository contains demonstrations and code examples focusing on parallel programming in C++. The primary topics covered include cache coherence issues in multi-threaded programming, basic multi-threading operations and pitfalls, OpenMP functionalities, parallel summation, and parallel prime counting.

### Projects Included:

1. **Cache Coherence Demo**: Explores the race conditions and performance implications arising due to cache coherence in multi-threaded environments.
2. **Multi-Threading Demonstration**: Showcases basic multi-threading concepts, pitfalls, and solutions related to race conditions.
3. **OpenMP Demonstration**: A comprehensive guide to understanding various functionalities provided by OpenMP for parallel programming.
4. **OpenMP Parallel**: Delves into parallel summation using OpenMP, exploring different synchronization and optimization methods.
5. **Prime Counter Parallelization**: Focuses on parallelizing the task of counting prime numbers up to a given number using different methods and solutions.

Each project is well-documented, detailing its objectives, prerequisites, key components, and instructions for compilation and execution.

## Getting Started

### Prerequisites

To run the demonstrations effectively, you will need:

- A C++ compiler supporting C++11 or higher.
- OpenMP library for parallel programming (used in some demonstrations).
- A machine with multiple processor cores to fully appreciate parallel execution.

### Compilation

While specific compilation instructions are given for each project, a general method for compiling C++ programs with OpenMP support using GCC is:

```bash
g++ -fopenmp <filename>.cpp -o <outputname>
```

Replace `<filename>.cpp` with the source file name and `<outputname>` with your desired output executable name.

### Execution

After compilation, execute the binary using:

```bash
./<outputname>
```

## Contribution

Contributions to enhance these demonstrations are welcome. If you have ideas or optimizations that can be added, please fork the repository and create a pull request. If you find issues or have suggestions, you can raise an issue in the repository.

## License

This repository is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgements

We thank all the contributors and developers who have provided feedback and insights, helping to shape this repository into a useful resource for understanding parallel programming in C++.

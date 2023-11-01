# OpenMP Parallel Summation

This repository contains an example of using OpenMP to perform parallel summation on an array of integers in C++.

## Overview

The code demonstrates various methods to achieve parallel summation:

1. **Standard Solution**: A basic sequential sum of array elements.
2. **Shared Sum with Race Condition**: Demonstrates what can go wrong when multiple threads modify a shared variable without synchronization.
3. **Using OMP Mutex**: Uses `omp_lock_t` to synchronize access to the shared `sum` variable.
4. **Using OMP Critical Section**: Utilizes the `#pragma omp critical` directive to ensure exclusive access to the shared `sum` variable.
5. **Work Sharing with `omp for`**: Distributes loop iterations among threads, while still using a mutex for synchronization.
6. **Local Variables and Reduction**: Utilizes the `reduction` clause for thread-safe summation.
7. **Dynamic Scheduling and Reduction**: Combines the `reduction` clause with dynamic scheduling for even distribution of loop iterations among threads.
8. **Dynamic Scheduling and Thread Assignment**: Demonstrates how OpenMP dynamically assigns iterations of a loop to different threads.

## Prerequisites

- A C++ compiler with OpenMP support, such as GCC or Clang.
- Basic knowledge of C++ programming and parallelization concepts.

## Compilation and Execution

To compile the program using GCC:

```bash
g++ -fopenmp filename.cpp -o outputname
```

To run the program:

```bash
./outputname
```

## Key Insights

1. Simply parallelizing without considering shared variable access can lead to race conditions.
2. OpenMP provides various mechanisms like mutexes and critical sections to handle synchronization.
3. The `reduction` clause in OpenMP is a powerful tool for parallelizing operations like summation, which involve accumulating a result across threads.
4. Dynamic scheduling can be beneficial when loop iterations have unpredictable workloads.

## Feedback and Contributions

Any feedback, issues, or contributions to improve the code or its explanations are highly appreciated!

## License

[MIT License](LICENSE)

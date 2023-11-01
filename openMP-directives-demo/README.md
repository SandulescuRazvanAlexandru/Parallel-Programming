# OpenMP Demonstration

This repository contains a code snippet demonstrating various functionalities provided by OpenMP for parallel programming in C++.

## Overview

The provided code showcases the following OpenMP functionalities:

1. **Basic Parallel Execution**: Introduction to creating parallel sections and accessing thread IDs.
2. **Setting Number of Threads**: Demonstrates how to specify the number of threads for a parallel region.
3. **Master Thread Execution**: Shows how only the master thread can be made to execute certain sections.
4. **Conditional Parallel Execution**: Demonstrates runtime decisions on executing blocks in parallel or sequentially.
5. **Variable Sharing and Private Copies**: Highlights how variables are managed in parallel sections, including shared variables, private copies, and initialized private copies.

Additionally, the code also provides a hands-on example of a race condition, emphasizing the need for careful synchronization in parallel programming.

## Prerequisites

- A C++ compiler with OpenMP support. Popular choices include GCC and Clang.
- Basic understanding of C++ and parallel programming concepts.

## Compilation and Execution

To compile the program using GCC:

```bash
g++ -fopenmp filename.cpp -o outputname
```

To run the program:

```bash
./outputname
```

## Key Takeaways

1. OpenMP provides an easy-to-use directive-based approach to parallel programming.
2. Proper synchronization and understanding of shared vs. private variables are crucial to avoid race conditions.
3. OpenMP provides various functionalities like setting the number of threads, master thread-specific execution, and more to fine-tune parallel execution as per requirements.

## Feedback and Contributions

Feel free to provide feedback, raise issues, or contribute to the codebase to enhance the demonstration further.

## License

[MIT License](LICENSE)

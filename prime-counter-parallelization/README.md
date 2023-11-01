# Prime Counter Parallelization

## Introduction
This project focuses on parallelizing the task of counting prime numbers up to a given size `N`. Several approaches are utilized, including sequential, parallel with race conditions, parallel with mutex locks, and parallel using OpenMP, among others.

## Table of Contents

1. Introduction
2. Dependencies
3. Compilation and Execution
4. Implemented Methods
5. Benchmarking
6. Conclusions

## Dependencies
- C++ Standard Library
- OpenMP library for parallel programming

## Compilation and Execution

To compile the code with g++ and OpenMP:
```bash
g++ -o PrimeCounter Source.cpp -fopenmp
```

To run the compiled program:
```bash
./PrimeCounter
```

## Implemented Methods

### 1. `sequentialSolution`:
A straightforward method to count primes sequentially from 0 up to `setSize`.

### 2. `parallelRaceSolution`:
Parallelizes the prime counting task but may lead to a race condition since multiple threads might attempt to update the `noPrimes` counter simultaneously.

### 3. `parallelMutexSolution`:
Utilizes mutex locks to prevent race conditions when updating the prime counter. Every time a prime number is found, the counter is updated within a critical section.

### 4. `parallelLoadBalancingSolution`:
Introduces a form of static load balancing where each thread checks prime numbers with a given step size.

### 5. `parallelBetterLoadBalancingSolution`:
Enhances load balancing by skipping even numbers (as they aren't prime) and introducing a more sophisticated step-size logic.

### 6. `parallelBetterLoadBalancingSolutionWithoutMutex`:
Aims to reduce the overhead of mutex locking by letting each thread have its counter. Summation is performed after all threads complete.

### 7. `ompParallelSolution`:
Leverages OpenMP's `parallel for` construct to parallelize prime counting. Also utilizes OpenMP's `reduction` clause to accumulate the prime count safely.

## Benchmarking

The `benchmark` function is provided to evaluate the performance of each method. For every method, the function measures and prints:
- The description of the method.
- The number of prime numbers found.
- The time taken to compute.

## Conclusions

Different parallel methods provide varying levels of efficiency, depending on the overhead they introduce (like mutex locking) and the granularity of the tasks (like the size of numbers each thread processes). Proper benchmarking helps in choosing the most suitable method for the given problem size and available hardware.

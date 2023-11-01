# Multi-Threading Demonstration

This repository contains a demonstration of basic concepts and pitfalls of multi-threaded programming in C++.

## Overview

The code demonstrates the use of threads in C++ to perform parallel computation and the challenges that arise, particularly race conditions. Several functions are implemented to showcase the behavior of threads when printing messages and computing array sums.

## Key Components

- **Thread Print Functions**:
  - `printHelloFromThread()`: Prints a simple message from a thread.
  - `printHelloFromThreadWithId(int id)`: Prints a message along with the thread's unique identifier.
  - `printMessage(string msg, int id)`: Generic function to print a given message with the thread's ID.
  
- **Array Sum Function**:
  - `computeArraySum(int array[], int n, int& result)`: Computes the sum of an integer array.

- **Main Program**:
  - Demonstrates printing from multiple threads.
  - Shows race condition pitfalls when computing sums in parallel threads.
  - Provides a race condition-free solution by using separate sum variables for each thread.
  - Demonstrates the use of a thread vector to manage multiple threads.

## Prerequisites

- A compiler supporting C++11 or higher.

## Usage

1. Compile the program using a suitable compiler.
2. Execute the binary.
3. Observe the printed results and understand the challenges and solutions related to race conditions in multi-threaded environments.

## Notes

- While the demonstration is simple, the concepts showcased, especially race conditions, are fundamental in multi-threaded programming. Proper understanding and resolution of these issues are crucial for building reliable and efficient multi-threaded applications.
- The program highlights the importance of thread-safe practices, especially when multiple threads access shared resources.

## Future Work

- Implementing more advanced synchronization mechanisms such as mutexes or semaphores to handle race conditions.
- Expanding the demonstration to cover more complex multi-threaded scenarios and best practices.


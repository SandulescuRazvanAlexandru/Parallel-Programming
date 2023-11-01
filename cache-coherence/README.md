# Cache Coherence Demo

This repository contains a demonstration of cache coherence issues in multi-threaded programming and their resolution.

## Overview

The provided code primarily focuses on understanding the race conditions that arise due to cache coherence in multi-threaded environments. The demonstration runs a simple counter across multiple threads and measures performance implications.

## Key Components

- **Global Mutex (`counterMutex`)**: A mutex to ensure that critical sections of the code are not accessed concurrently by multiple threads.
  
- **Counter Functions**:
  - `counter()`: Increments a counter without using mutex, which leads to a race condition.
  - `counterWithMutex()`: Uses the global mutex to increment the counter in a thread-safe manner.

- **Main Program**:
  - Initializes thread counters and metrics.
  - Demonstrates race conditions by running the `counter()` function across multiple threads.
  - (Optional, commented out) Demonstrates a thread-safe counter using `counterWithMutex()`.
  - Demonstrates a race condition-free solution by using multiple variables for each thread.
  - Demonstrates a race condition-free solution by placing thread counters on different cache lines.

## Prerequisites

- A compiler supporting C++11 or higher.
- OpenMP library for measuring time and determining available processor cores.

## Usage

1. Compile the program using a suitable compiler.
2. Execute the binary.
3. Observe the printed results to understand the time required and discrepancies in the counter due to cache coherence issues.

## Notes

The demonstration highlights the importance of understanding hardware-level details, such as cache lines, when developing performance-critical multi-threaded applications. Adjusting for cache coherence can lead to substantial performance improvements in certain scenarios.

## Future Work

- Exploring other synchronization primitives to handle cache coherence.
- Analyzing performance implications with varying sizes of data and thread counts.


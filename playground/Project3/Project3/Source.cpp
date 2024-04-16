//checking primes 
#include <string>
#include <vector>
#include <stdio.h>
#include <omp.h>
#include "Methods.h"

int main() {
	const long N = 5e5;

	const int noCores = omp_get_num_procs();
	printf("\nAvailable cores = %d", noCores);

	//count how many primes we have in an interval

	//benchmark("Test", 100, solution);	
	
	//benchmark("Sequential solution", N, sequentialSolution);
	//benchmark("Parralel solution with race condition", N, parallelRaceSolution);
	//benchmark("Parralel solution with a mutex", N, parallelMutexSolution);
	//printf("\n------------------------");
	//nr pare si impare problem
	//benchmark("Parralel solution with a mutex and a better load balancing", N, parallelLoadBalancingSolution); 
	//printf("\n------------------------");
	benchmark("Parralel solution with a mutex and an optimized load balancing", N, parallelBetterLoadBalancingSolution); 
	printf("\n------------------------");
	benchmark("No cache sharing parralel solution without a mutex and an optimized load balancing", N, parallelBetterLoadBalancingSolutionWithoutMutex); 




	printf("\n\nEnd of exameple");


	//ora 12:35+ zice diferenta cu mpi vs ce am facut acum
}
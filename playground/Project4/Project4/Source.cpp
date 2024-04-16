//OMPDirectives

#include <string>
#include <omp.h> //see what happens if i delete this line (common mistake !!! instruct to know to use omp !!)

int main() {
	printf("OMP examples\n");

	printf("\nHello from the main thread. Its id is %d", omp_get_thread_num());

	int noCores = omp_get_num_procs();
	printf("\nNumber of cores = %d", noCores);

	//these are macrodefinitions (ora 13:52)
#pragma omp parallel
	{ //atentie unde deschis { } 
		printf("\nHello from thread %d", omp_get_thread_num());
		printf("\nHow r u?");
	}

	printf("\n------------------");

	int requiredNoThreads = 4;
	omp_set_num_threads(4);
#pragma omp parallel
	{ 
		printf("\nHello again from thread %d", omp_get_thread_num());
		printf("\nHow r u?");
	}

	printf("\n------------------");

	int specialNoThreads = 2;
#pragma omp parallel num_threads(specialNoThreads)
	{
		printf("\nBye from thread %d", omp_get_thread_num());
	}

	printf("\n------------------");

	int hugeNumberOfThreads = 1e2; //1e5
#pragma omp parallel num_threads(hugeNumberOfThreads)
	{
		//int noRealThreads = omp_get_num_threads();
		//printf("\nThe number of threads in the parralel section is %d", noRealThreads);
		
		//how to execute only once 
		if (omp_get_thread_num() == 0) { //alwasy use the master thread
			int noRealThreads = omp_get_num_threads();
			printf("\nThe number of threads in the parralel section is %d", noRealThreads);
		}
		//how to execute only once part2
#pragma omp master
		{
			int noRealThreads = omp_get_num_threads();
			printf("\nThe number of threads in the parralel section is %d", noRealThreads);
		}
	}

	printf("\n------------------");

	//controlling the execution in parallel or not 
	bool doItInParallel = true;

	if (doItInParallel) {
#pragma omp parallel 
		{
			//parallel
		}
	}
	else {
		//sequentially
	}

	if (noCores < 16)
		doItInParallel = false;

#pragma omp parallel if(doItInParallel)
	{
		printf("\nHello from parallel section");
	}

	//managing variables
	//all external variables are shared by all threads -> race conditions
	printf("\n------------------");

	int counter = 0;
	int noIterations = 1000;
#pragma omp parallel num_threads(4)
	{
		for (int i = 0; i < noIterations; i++) {
			counter += 1;
		}
		printf("\nCounter value is %d", counter);
	}
	printf("\nFinal counter value is %d", counter);

	//all the variables are shared -- race conditions 

	printf("\n------------------");
#pragma omp parallel num_threads(4)
	{
		int localCounter = 0;
		for (int i = 0; i < noIterations; i++) {
			localCounter += 1;
		}
		printf("\nLocal counter value is %d", localCounter);
	}

	printf("\n------------------");
#pragma omp parallel num_threads(4) private(counter)
	{
		counter = 0;
		for (int i = 0; i < noIterations; i++) {
			counter += 1;
		}
		printf("\nCounter value is %d", counter);
	}


	printf("\n------------------");
	counter = 500;
#pragma omp parallel num_threads(4) firstprivate(counter) shared(noIterations)
	{
		for (int i = 0; i < noIterations; i++) {
			counter += 1;
		}
		printf("\nCounter value is %d", counter);
	}
	printf("\nThe main counter value is %d", counter);
	// shared(noIterations) --- e redundant, oricum este deja shared 



	printf("\n\nEnd of example");
}
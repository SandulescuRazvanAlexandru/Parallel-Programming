// cache coherence 
#include <thread>
#include <string>
#include <vector>
#include <mutex>
#include <omp.h>

using namespace std;

//define a global mutex
mutex counterMutex;

void counter(int& counter, int limit) {
	for (int i = 0; i < limit; i++) {
		counter += 1;
	}
}

// aka syncronised
void counterWithMutex(int& counter, int limit) {
	for (int i = 0; i < limit; i++) {
		counterMutex.lock();
		counter += 1; //when we do this, we kill paralellism
		counterMutex.unlock();
	}
}

int main() {

	int noCores = omp_get_num_procs();
	printf("\nAvailable cores: %d", noCores);

	double currentTime = omp_get_wtime();
	printf("\nCurrent time %f", currentTime);

	currentTime = omp_get_wtime();
	printf("\nCurrent time %f", currentTime);

	int finalCounter = 0;
	vector<thread> threads;
	const int limit = 1e7;

	double tStart = omp_get_wtime();

	for (int i = 0; i < noCores; i++) {
		threads.push_back(thread(counter, ref(finalCounter), limit));
		// threads[i].join(); it is a mistake - you wait on the thread to finish
	}
	for (int i = 0; i < noCores; i++) {
		threads[i].join();
	}

	double tFinal = omp_get_wtime();

	//race condition = faza ca o variabila este modificata in acelasi timp pe mai multe thread-uri si apoi se pierd unele valori pe drum
	printf("\nThe counter result with race condition and multiple threads is %d and it requires %f seconds", finalCounter, tFinal - tStart);

	/* comentam ca sa nu mai stam mult pana se executa 
	//testing the solution with a mutex and without race conditions
	threads.clear();

	tStart = omp_get_wtime();
	finalCounter = 0;

	for (int i = 0; i < noCores; i++) {
		threads.push_back(thread(counterWithMutex, ref(finalCounter), limit));
	}
	for (int i = 0; i < noCores; i++) {
		threads[i].join();
	}

	tFinal = omp_get_wtime();

	//this way the result is correct 
	printf("\nThe counter result with mutex and multiple threads is %d and it requires %f seconds", finalCounter, tFinal - tStart);

	//mutex can be done cand probabilitatea de ciocnire e mica 
	*/
	
	//--------------

	//testing without mutex and without race conditions with/using multiple variables
	threads.clear();
	finalCounter = 0;
	int* threadResults = new int[noCores];
	for (int i = 0; i < noCores; i++) {
		threadResults[i] = 0;
	}

	tStart = omp_get_wtime();
	for (int i = 0; i < noCores; i++) {
		threads.push_back(thread(counter, ref(threadResults[i]), limit));
		// threads[i].join(); it is a mistake - you wait on the thread to finish
	}
	for (int i = 0; i < noCores; i++) {
		threads[i].join();
	}
	tFinal = omp_get_wtime();

	for (int i = 0; i < noCores; i++) {
		finalCounter += threadResults[i];
	}

	printf("\nThe counter result without either mutex or race condition and multiple threads is %d and it requires %f s", finalCounter, tFinal - tStart);


	//---------------------------------

	//testing without mutex and without race conditions with/using multiple variables on different cache lines
	threads.clear();
	finalCounter = 0;
	int threadResultsMatrix[8][1000]; // because i have 8 cores
	for (int i = 0; i < noCores; i++) {
		threadResultsMatrix[i][0] = 0;
	}

	tStart = omp_get_wtime();
	for (int i = 0; i < noCores; i++) {
		threads.push_back(thread(counter, ref(threadResultsMatrix[i][0]), limit));
	}
	for (int i = 0; i < noCores; i++) {
		threads[i].join();
	}
	tFinal = omp_get_wtime();

	for (int i = 0; i < noCores; i++) {
		finalCounter += threadResultsMatrix[i][0];
	}

	printf("\nThe counter result without cache coherence is %d and it requires %f s", finalCounter, tFinal - tStart);




	printf("\n\nEnd of example");
}
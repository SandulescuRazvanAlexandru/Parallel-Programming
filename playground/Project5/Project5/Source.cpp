//OMP more complex directives

//compute the sum of an array in a parallel way

#include <string>
#include <omp.h> //activate !!!!!!!

using namespace std;

int main() {

	//we write normal, apoi vedem in a parallel way

	const int N = 10000;
	int* array = new int[N];
	for (int i = 0; i < N; i++) {
		array[i] = i + 1;
	}

	//standard solution
	long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += array[i];
	}
	printf("\nThe sum is %d", sum);
	
	//parallel solution with sharesd sum and race condition 
	sum = 0;
#pragma omp parallel
	{
		for (int i = 0; i < N; i++) {
			sum += array[i];
		}
	}
	printf("\nThe sum is %d", sum);

	//parallel solution with an OMP mutex
	//the for is duplicated on all threads  --- 50005000 * 8 = 4000040000

	//creating mutex
	omp_lock_t mutex;
	omp_init_lock(&mutex);
	
	sum = 0;
#pragma omp parallel
	{
		for (int i = 0; i < N; i++) {
			omp_set_lock(&mutex);
			sum += array[i];
			omp_unset_lock(&mutex);
		}
	}
	//omp_destroy_lock(&mutex);
	printf("\nThe sum is %d", sum); 

	//parallel solution with an OMP critical
	//the for is duplicated on all threads

	sum = 0;
#pragma omp parallel 
	{
		for (int i = 0; i < N; i++) {
#pragma omp critical
			sum += array[i];
		}
	}
	printf("\n The sum is %d", sum);


	//parallel with work sharing of the for loop
	sum = 0;
#pragma omp parallel 
	{
#pragma omp for
		for (int i = 0; i < N; i++) {
			omp_set_lock(&mutex);
			sum += array[i];
			omp_unset_lock(&mutex);
		}
	}

	printf("\nThe sum is %d", sum);

	//parallel with local variables and reduction//standard solution
	sum = 0;
#pragma omp parallel for num_threads(4) reduction(+: sum) //ora 15:35 also echivalent cu ?? firstprivate(sum)
	for (int i = 0; i < N; i++) {
		sum += array[i];
	}
	printf("\nThe sum is %d", sum);

	//parallel with reduction and a dynamic scheduler
	sum = 0;
#pragma omp parallel for num_threads(4) reduction(+: sum) schedule (dynamic, 100)
	for (int i = 0; i < N; i++) {
		sum += array[i];
	}
	printf("\nThe sum is %d", sum);

/*
#pragma omp parallel num_threads(4)
	{

#pragma omp for reduction(+: sum) schedule (dynamic, 10)
		for (int i = 0; i < 1000; i++) {
			printf("\nThread id %d got iteration %d", omp_get_thread_num(), i);
			sum += array[i];
		}
		printf("\nThe sum is %d", sum);
	}
*/

/*
#pragma omp parallel num_threads(4)
	{

#pragma omp for reduction(+: sum) schedule (static) //they all get 10 iterations
		for (int i = 0; i < 40; i++) {
			printf("\nThread id %d got iteration %d", omp_get_thread_num(), i);
			sum += array[i];
		}
		printf("\nThe sum is %d", sum);
	}
*/


#pragma omp parallel num_threads(4)
	{

#pragma omp for reduction(+: sum) schedule (dynamic) //ala mai rapid
		for (int i = 0; i < 40; i++) {
			printf("\nThread id %d got iteration %d", omp_get_thread_num(), i);
			sum += array[i];
		}
		printf("\nThe sum is %d", sum);
	}


	printf("\nEnd of example");
}
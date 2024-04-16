#include <thread>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void printHelloFromThread() {
	cout << endl << "Hello " << " from another thread";
} 

void printHelloFromThreadWithId(int id) {
	//cout << endl << "Hello " << " from another thread" << " with id = " << id;
	printf("\nHello from another thread with id = %d", id);

	//always use printf
}

void computeArraySum(int array[], int n, int& result) {
	//result = 0;
	for (int i = 0; i < n; i++) {
		result += array[i];
	}
}

void printMessage(string msg, int id) {
	printf("\n %s from %d", msg.c_str(), id);
}

int main() {
	cout << endl << "Hello from MAIN thread";

	//simple threads
	// 
	//it starts automatically (fara .start sau .run)
	// pointer to the function 
	thread t1(printHelloFromThreadWithId, 1);
	thread t2(printHelloFromThreadWithId, 2);
	thread t3(printHelloFromThreadWithId, 3);
	thread t4(printHelloFromThreadWithId, 4);

	//we instruct the main thread to wait on t1, t2.. ()orchestarade them ???
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	// poate sa afiseze in orice ordine, asta e faza cu paralel 
	//---------------------

	//simple threads that return 
	int values[] = { 10,20,30 };
	int values2[] = { 40,50,60 };
	int n = 3;

	//we have a race condition, but we cant see it for now
	int sum = 0;
	//ca in .net referinta 
	thread tsum1(computeArraySum, values, n, ref(sum)); 
	thread tsum2(computeArraySum, values2, n, ref(sum)); 
	tsum1.join();
	tsum2.join();

	//sunt pe main thread, astept join-urile, pot sa folosesc cout 
	cout << endl << "The sum is " << sum;


	const int N = 1e5;
	int* values3 = new int[N];
	for (int i = 0; i < N; i++) {
		values3[i] = i + 1;
	}

	sum = 0;
	computeArraySum(values3, N, sum);
	computeArraySum(values3, N, sum);

	cout << endl << "The result in a sequentially way is " << sum;

	//again weh have a race condition
	sum = 0;
	thread tsum3(computeArraySum, values3, N, ref(sum));
	thread tsum4(computeArraySum, values3, N, ref(sum));
	tsum3.join();
	tsum4.join();
	cout << endl << "The result in a parallel way is " << sum;

	//without racing conditions
	int sumT1 = 0;
	int sumT2 = 0;
	thread tsum5(computeArraySum, values3, N, ref(sumT1));
	thread tsum6(computeArraySum, values3, N, ref(sumT2));
	tsum5.join();
	tsum6.join();

	sum = sumT1 + sumT2;

	cout << endl << "The result in parallel way without racing conditions is " << sum;

	//handling multiple threads using an array
	vector<thread> threads;
	int noThreads = 10;
	for (int i = 0; i < noThreads; i++) {
		threads.push_back(thread(printMessage, "Hello", i));
	}
	for (int i = 0; i < noThreads; i++) {
		threads[i].join();
	}


	cout << endl << "End of example";
}
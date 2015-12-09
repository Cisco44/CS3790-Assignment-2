#include "cPrimesMath"

/* ------------------ ISPRIME ------------------ 

IsPrime is tasked with determining if a value is a prime number.
It does so by verifying if the number returns is at any point returns
a remainder of 0. 

It does this comparision for every number between 2 and the square root
of the number being tested rounded up.

If so then the function returns false. Otherwise it returns true.

*/

int isPrime(int num){
	double sqrtnum = num;
	sqrtnum = ceil(sqrt(sqrtnum));
	for(int i = 2; i < sqrtnum; i++)
		if(num % i == 0) return 0;

	return 1;
}

/* ------------------ TESTER ------------------ 

Tester runs in every child thread created by the main.
It is tasked with checking every number in a specific range,
and printing out a statement indicating every prime number
found in it's respective thread.

*/

int tester(void *param){

	int threadID = (int)param;
	
	int lowerbound = threadID * (N/M) + 1;
	int upperbound = (N/M) * (threadID + 1);

	for(int i= lowerbound; i < upperbound; i++){
		if(isPrime(i))
			printf("Thread %d found the prime: %d\n", threadID, i);
	}
}


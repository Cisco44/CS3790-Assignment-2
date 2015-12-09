#include "cPrimesMath"

pthread_t tid[1000];
int N,M;

int main(int argc, char *argv[] ){
	
/*

*/

	if(argc != 3){
		fprintf(stderr, "Usage: %s <Range Interger Value> <Number of Threads>\n", argv[0]);
		return -1;
	}
	
	if(atoi(argv[1]) <= 0){
		fprintf(stderr, "%d must be larger than 0.\n", atoi(argv[1]));
		return -1;
	}

	if(atoi(argv[2]) > atoi(argv[1])){
		fprintf(stderr, "Number of threads(%d) must be less than the range(%d).\n", atoi(argv[2]), atoi(argv[1]));
		return -1;
	}

	N = atoi(argv[1]); //
	M = atoi(argv[2]); //
	
/*

*/

	for(int i = 0; i < M; i++)
		pthread_create(&tid[i], NULL, tester, (void*)i);
	for(int i = 0; i < M; i++)
		pthread_join(tid[i], NULL);

}

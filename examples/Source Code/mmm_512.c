#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <cblas.h>

int main()
{
	const int M = 512, K = 512, N = 512;    //define the size of the matrix and vector
	float *M1 = malloc(M * K * sizeof(float));
	float *M2 = malloc(K * N * sizeof(float));
	float *M3 = malloc(M * N * sizeof(float));

	//rand weight1
	unsigned int seed = time(NULL);
	srand(seed);
	
	for(int i = 0; i < M; i++)
		for(int j = 0; j < K; j++) {
			float v = 10 * (float)rand() / RAND_MAX;
			M1[i*M+j] = v;
	}
	
	for(int i = 0; i < K; i++)
	    	for(int j = 0; j < N; j++) {
			float v = 2 * (float)rand() / RAND_MAX - 1;
		 	M2[i*M+j] = v;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int m = 0; m < K; m++) {
				M3[i*N+j] += M1[i*K+m] * M2[m*N+j];
			}
		}
	}
	
	printf("the value of output: %f\n", M3[1025]);//, M6[1 * N + 1]);

	return 0;
}

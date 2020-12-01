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
	for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
			M1[i * N + j] = (float) (i + j) / N;
        }
	}
	
	//init weight2
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < N; j++) {
			M2[i * N + j] = (float)(i * j) / N;
		}
	}
	
	//do the mmm
	cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, 1.0, M1, K, M2, N, 0.0, M3, N);

	printf("the value of output: %f\n", M3[1 * N + 1]);

	return 0;
}

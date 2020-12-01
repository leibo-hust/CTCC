#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int main()
{
	const int M = 512, N = 512;    //define the size of the matrix and vector
	float weight[512][512]={0}, in[512]={0}, out[512]= {0};

	//rand to init
	unsigned int seed = time(NULL);
	srand(seed);
	for(int i = 0; i < M; i++)
	{
		float val = (float)rand() / RAND_MAX;
		in[i] = val;
	}

	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++) {
			float v = 2 * (float)rand() / RAND_MAX;
			weight[i][j] = (v - 1);
	}
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) {
			out[i] += in[j] * weight[j][i];
		}


	printf("test value of output: %f\n", out[6]);

	return 0;
}

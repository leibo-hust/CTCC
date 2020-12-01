#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

int main()
{
	int M = 512;
	int arr1[512], arr2[512], arr3[512];

	//rand to init
	unsigned int seed = time(NULL);
	srand(seed);
	for(int i = 0; i < M; i++)
	{
		int val = rand() % 2;
		arr1[i] = val;
	}
	srand(seed);
	for(int i = 0; i < M; i++) 
	{   
		int val = rand() % 2;    
		arr2[i] = val;
	}

	for(int i = 0; i < 512; i++) {
		arr3[i] = arr1[i] | arr2[i];
	}

	printf("test out: %d\n", arr3[2]);	
	return 0;
}

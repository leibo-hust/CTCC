#include <stdio.h>
#include <stdlib.h>

//c[1][n] = a[1][n] logic c[1][n]
void CIM_Bitmap(int opcode, int a[], int b[], int c[], int n);

// a[1][M] * B[M][N] = c[1][N];
void CIM_MVM(int M, int N, float a[], float* B, float c[]);

// A[M][N] * B[N][K] = C[M][K];
void CIM_MMM(int M, int N, int K, float* A, float* B, float* C);
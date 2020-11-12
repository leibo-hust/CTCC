#include <stdlib.h>
#include <stdio.h>
#include <cblas.h>

int main()
{
    //compared vector
    float A[3] = {1, 2.5, 3};
    //matrix
    float weight[3][2] = {4, 5,
                        5.2, 6.3,
                        7.3, 8};
    float resA[2] = {0};
    cblas_sgemm(CblasRowMajor, CblasTrans, CblasTrans, 2, 1, 3, 1.0, weight[0], 2, A, 3, 0.0, resA, 1);

    for (int i = 0; i < 2; i++) {
        printf(" %f\n", resA[i]); 
    }

    return 0;
}
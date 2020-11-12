#include <stdio.h>
#include <cblas.h>

int main()
{
    float A [6][5] = { 1.1, 2.1, 3.2, 4.2, 5.5,
             2.4, 3.8, 5.2, 7.4, 8.5,
             3.1, 2.1, 0.5, 1.01, 4.32,
             4.5, 3.2, 8.1, 1.5, 2.3,
             1.1, 13, 5.7, 1.12, 8.33,
             -9.01, 9.23, 8.8, 8.8, 8.8};

    float b [2][6] = { 4.3, -7.4, 8.8, -2.3, 1.3, 2.58,
               0.5, 1.32, 2.88, 3.4, -0.6, 1.7};
    float c[2][5] = { 0 };
    float c1[2][5] = { 0 };
    for (int i = 0; i < 2; ++i)
    {
            for (int j = 0; j < 5; ++j)
            {
                for(int k = 0; k < 6; k++)
                    c [i][j] += b[i][k] * A[k][j];
            }
    }
    //cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 5, 6, 1.0, b, 6, A, 5, 0.0, c1, 5);


    float a = c[1][2];
    printf("%f\n", a);
}

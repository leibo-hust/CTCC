#include <stdlib.h>
#include <stdio.h>

int main() {
    float A[3] = {1, 2, 3};
    float weight[3][2] = {4, 5,
                        5, 6,
                        7, 8};

    float res[2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            res[i] += A[j] * weight[j][i];
        }
    } 
    
    for (int i = 0; i < 2; i++) {
        printf("%f\n", res[i]); 
    }

    return 0;
}
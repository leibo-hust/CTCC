#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[10] = {1, 0, 0, 1, 0, 1, 1, 1, 0, 1};
    int arr2[10] = {0, 0, 1, 1, 1, 1, 0, 0, 0, 1};
    int arr3[10] = {0};

    for(int i = 0; i < 10; i++) {
        arr3[i] = arr1[i] & arr2[i];
    }

    for(int i = 0; i < 10; i++) {
        printf("%d\n", arr3[i]);
    }

    return 0;
}
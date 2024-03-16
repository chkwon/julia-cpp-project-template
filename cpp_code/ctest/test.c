#include "c_interface.h"
#include <stdio.h>
#include <assert.h>

int main() {

    double arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int factor = 2;

    multiply_array(arr, n, factor);

    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        assert (arr[i] == (i + 1) * factor);
    }
    
}
#include "c_interface.h"
#include "bar.hpp"



extern "C" 
void multiply_array(double* arr, int n, int factor) {

    // Inside of this C interface function
    // we can use C++ code to call the C++ function

    // First, we need to create a vector from the array (copying)
    std::vector<double> v(arr, arr + n);

    // Then, we can call the C++ function
    multiply_vector(v, factor);
    
    // Finally, we need to convert the vector back to an array
    // so that Julia's vector is updated
    for (int i = 0; i < n; i++) {
        arr[i] = v[i];
    }
    
}


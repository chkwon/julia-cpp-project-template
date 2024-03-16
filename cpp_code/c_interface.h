#ifndef C_INTERFACE_H
#define C_INTERFACE_H


// This is the C interface to the C++ function, which will be exposed to Julia.
#ifdef __cplusplus
extern "C"
#endif
void multiply_array(double* arr, int n, int factor);

#endif //C_INTERFACE_H
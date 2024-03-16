# julia-cpp-project-template

First compile the C/C++ part.

```
mkdir build
cd build
cmake ..
make
```

This will make a shared library `build/libbar.dylib` in macOS or `build/libbar.so` in Linux.

Test
```
ctest lib
```

Then, comeback to the main repo directory:
```
cd ..
```

Then, run the julia script:
```
julia src/main.jl  
```
or
```
julia> include("src/main.jl")
```


## Remarks

In `bar.cpp`, the actual computation is done via `vector<double>` in C++. 
But, Julia is better connected with C. 
So, `c_interface.c` has an interface to connect Julia and C++.
#include <iostream>
#include "bar.hpp"

void display_vector(const std::vector<double> &v){
    for (auto i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void multiply_vector(std::vector<double>& v, int factor){
    for (auto &i : v){
        i *= factor;
    }
}


int main() {
    std::vector<double> myvector = {1, 2, 3, 4, 5};

    std::cout << "myvector before multiply_vector:\t";
    display_vector(myvector);
    
    multiply_vector(myvector, 2);

    std::cout << "myvector after multiply_vector:\t";
    display_vector(myvector);


    return 0;
}
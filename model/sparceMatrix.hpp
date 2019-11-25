#ifndef SPARCE_MATRIX_HPP
#define SPARCE_MATRIX_HPP
#include <vector>
#include <iostream>

#include "hashable.hpp"

class SparseMatrix: public Hashable {
    private:
        std::vector<int> storage;
        void generate();    // Generate random matrix, no point to do that manually
        long int length;
        long int height;
        long int amountOfZeros;
        double getSumm();
    public:
        SparseMatrix(long int len, long int height);     // Creates matrix and calls generate to fill it 
        double getQuality();    // Returns a matrix quality – for comparisons
        void test_Output();

        std::string valueToHash ();
};


#endif
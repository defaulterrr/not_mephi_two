#include "sparceMatrix.hpp"


void SparseMatrix::generate () {
    long long int maxSize = length * height;
    long long int randomQ = rand()%maxSize;
    long long int amountOfZeros;

    // Calculate such amount of zeros so that they take most of the matrix
    (randomQ < maxSize/2) ? amountOfZeros = maxSize - randomQ : amountOfZeros = randomQ; 
    long long int iterator = 0;
    while (iterator < amountOfZeros) {
        storage.push_back(0); iterator++;
    }

    while (iterator < maxSize) {
        storage.push_back(rand()%iterator+rand()%storage.size()); iterator++;
    }
   this->amountOfZeros = amountOfZeros;
}

SparseMatrix::SparseMatrix(long int len, long int height) {
    this->length = len;
    this->height = height;
    SparseMatrix::generate();
}

void SparseMatrix::test_Output() {
    
    long int i=0;
    while(i<storage.size()) {
        std::cout.width(4);
        std::cout << storage[i] << " ";
        if ((i+1)%height == 0) {std::cout.width(4);std::cout << std::endl;} 
        i++;
    }
}

double SparseMatrix::getSumm() {
    long int i = amountOfZeros-1;
    double summ=0;
    while (i<storage.size()) {
        summ+=storage[i];
        i++;
    }
    return summ;
}

double SparseMatrix::getQuality() {
    return height*length + getSumm();
}

std::string SparseMatrix::valueToHash () {
    
    long int i = 0;
    string summ = string();
    while (i<storage.size()) {
        summ+=to_string(storage[i]);
        i++;
    }
    return summ;
}

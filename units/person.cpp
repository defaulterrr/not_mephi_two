#include "../model/h_Person.hpp"
#include <iostream>
using namespace std;

int main() {
    cout << "Started" << endl;
    Person firstTest = Person();
    firstTest.print();
    cout << "Hash is " << firstTest.hash() << endl;
}
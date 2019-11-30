#include "../model/h_Person.hpp"
#include "../model/h_HashTable_one.hpp"
#include <iostream>
using namespace std;

int main() {
    HashTable table = HashTable();
    Person *dummy1 = new Person("Mike","Ross","mross@harvard.edu",1985);
    table.add(dummy1);
    Person *checkDummy = dynamic_cast<Person*>(table.get(dummy1->hash()%table.getCapacity()));
    if (checkDummy!=nullptr) {checkDummy->print();} 
    else {
        cout << "returned nullptr" << endl;
    }

    Person *array = new Person[512];
    for (int i=0;i<512;i++) {
        array[i] = Person();
    }
    cout << "Created persons" << endl;
    for (int i=0;i<512;i++) {
        cout << "Index " << i+1 << " and its hash is " << array[i].hash() << endl;
        table.add(&array[i]);
        
    }
    cout << "Added them to table" << endl;


    cout << table.getCount() << " out of "<< table.getCapacity() << endl;
    
}
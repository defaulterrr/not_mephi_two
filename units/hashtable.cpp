#include "../model/h_Person.hpp"
#include "../model/h_HashTable_one.hpp"
#include "../model/h_HashTable_two.hpp"
#include "../model/h_HashTable_three.hpp"
#include <iostream>
using namespace std;

int main() {
    func();
    HashTableList table = HashTableList();
    Person *dummy1 = new Person("Mike","Ross","mross@harvard.edu",1985);
    table.add(dummy1);
    Person *checkDummy = dynamic_cast<Person*>(table.get(dummy1->hash()%table.getCapacity()));
    if (checkDummy!=nullptr) {checkDummy->print();} 
    else {
        cout << "returned nullptr" << endl;
    }
    cout << "Creating persons" << endl;
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
    cout << "find1 test" << table.find(dummy1) << endl;
    table.add(dummy1);
    cout << "find2 test" << table.find(dummy1) <<"ss"<<endl;
    for(int l=0;l<10;l++)
    cout << table.get(dummy1->hash()%table.getCapacity()) << endl;
    
}
#include <iostream>
using namespace std;


bool hashTests() {
    func();
    bool suc = true;
    cout << "Create reference Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1985)\n";
    Person *dummy1 = new Person("Mike","Ross","mross@harvard.edu",1985);
    Person *dummy2 = new Person("1","1","1",1);
    cout << "Creating random persons" << endl;
    Person *array = new Person[512];
    for (int i=0;i<512;i++) {
        array[i] = Person();
    }
    cout << "Created 512 persons" << endl;


    cout << "\nStart test for basic Hash-Table" << endl;
    HashTableBasic table = HashTableBasic();
    for (int i=0;i<512;i++) {
        table.add(&array[i]);
    }
    table.add(dummy1);
    cout << "Added the elements to the table" << endl;
    cout << "There are "<< table.getCount() << " elements out of "<< table.getCapacity() << endl;
    cout << "Find test for existing element " << endl;
    if(table.find(dummy1)== true)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }
    cout << "Find test for non existing element " << endl;
    if(table.find(dummy2)== false)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }



    cout << "\nStart test for List Hash-Table" << endl;
    HashTableList table2 = HashTableList();
    for (int i=0;i<512;i++) {
        table2.add(&array[i]);
    }
    cout << "There are "<< table2.getCount() << " elements out of "<< table2.getCapacity() << endl;
    table2.add(dummy1);
    cout << "Find test for existing element " << endl;
    if(table2.find(dummy1)== true)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }
    cout << "Find test for non existing element " << endl;
    if(table2.find(dummy2)== false)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }


    cout << "\nStart test for Dist Hash-Table" << endl;
    HashTableDist table3 = HashTableDist();
    for (int i=0;i<512;i++) {
        table3.add(&array[i]);
    }
    cout << "There are "<< table3.getCount() << " elements out of "<< table3.getCapacity() << endl;
    table3.add(dummy1);
    cout << "There are "<< table3.getCount() << " elements out of "<< table3.getCapacity() << endl;
    cout << "Find test for existing element " << endl;
    if(table3.find(dummy1)== true)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }
    cout << "Find test for non existing element " << endl;
    if(table3.find(dummy2)== false)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    return suc;
}


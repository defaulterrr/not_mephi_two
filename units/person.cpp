#include <iostream>
using namespace std;

bool personTests() {
    cout << "Start indexing tests for Person" << endl;
    Person firstTest = Person();
    cout << "Create 21 different Persons\n";
    Person *array = new Person[21];
    array[0] = Person("Mike","Ross","mross@harvard.edu",1985);
    array[1] = Person("Harvey","Spectre","mross@harvard.edu",1985);
    array[2] = Person("Jessica","Pearson","mross@harvard.edu",1985);
    array[3] = Person("Rachel","Zane","mross@harvard.edu",1985);
    array[4] = Person("Donna","Paulson","mross@harvard.edu",1985);
    array[5] = Person("Louis","Litt","mross@harvard.edu",1985);
    array[6] = Person("Daniel","Hardman","mross@harvard.edu",1985);
    array[7] = Person("Robert","Zane","mross@harvard.edu",1985);
    array[8] = Person("Han","Solo","mross@harvard.edu",1985);
    array[9] = Person("Luke","Skywalker","mross@harvard.edu",1985);
    array[10] = Person("Anakin","Skywalker","mross@harvard.edu",1985);
    array[11] = Person("Obi-wan","Kenobi","mross@harvard.edu",1985);
    array[12] = Person("Qui Gon","Jinn","mross@harvard.edu",1985);
    array[13] = Person("Master","Yoda","mross@harvard.edu",1985);
    array[14] = Person("Councellor","Palpatin","mross@harvard.edu",1985);
    array[15] = Person("Mace","Windu","mross@harvard.edu",1985);
    array[16] = Person("Ed","Sheeran","mross@harvard.edu",1985);
    array[17] = Person("Taylor","Swift","mross@harvard.edu",1985);
    array[18] = Person("Randall","Logic","mross@harvard.edu",1985);
    array[19] = Person("Paul","Hudson","mross@harvard.edu",1985);
    array[20] = Person("Paul","Hudson","mross@harvard.edu",1985);

    for (int i =0;i<21;i++) {
        cout << "For person #"<< i<< " with data:\n";
        array[i].print();
        cout<<"Hash: "<<array[i].hash()<<endl<<endl;
    }
    cout << "Test hash func for same elements:\n";
    if (array[19].hash() == array[20].hash()){
        cout << "Test for hash-func passed!\n" << endl;
        return true;
    }
    else
        cout << "Test failed\n" << endl;
    return false;

}



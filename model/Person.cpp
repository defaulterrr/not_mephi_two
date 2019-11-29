#include "Person.hpp"



void Person::print() {
    cout << this->name << " " << this->fathersName << " " << this->surname << endl;
    cout << this->email << endl;
    cout << this->birth << endl;
}

Person ranPers() {
    Person toReturn = Person();
    return toReturn;
}
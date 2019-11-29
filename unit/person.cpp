#include "../model/Person.cpp"

int main() {
    // Person test = Person();
    // test.print();
    vector<Person> storage;
    for (int i =0; i<26; i++) {
        cout << i << endl;
        storage.push_back(Person());
        // storage[storage.size()].print();
        cout << sizeof(storage) << endl;
    }
    for (int i =0; i<25; i++) {
        cout << i << endl;
        storage.push_back(Person());
        // storage[storage.size()].print();
        cout << sizeof(storage) << endl;
    }
}
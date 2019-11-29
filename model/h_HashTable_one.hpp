#include "protocols.hpp"
#include <vector>
#include <iostream>
using namespace std;

/* Declaration */
class HashTable: public Dictionary<int,Hashable*> {
    public:
        HashTable();
        int getCount();
        int getCapacity();
        Hashable* get(int key);
        bool containsKey(int key);
        void add(Hashable* value);
        void add(int key,Hashable* value);

    private:
        void rebuild();
        void evaluate();

        /* Storages */
        vector<Hashable*> storage;
        int curSize = 0;
        int maxSize = 256;
        
};

/* Implementation */

HashTable::HashTable(){
    // Create empty vector filled with nullptrs
    storage = vector<Hashable*>(maxSize,nullptr);
}

int HashTable::getCount() {
    return curSize;
}

int HashTable::getCapacity() {
    return maxSize;
}

Hashable* HashTable::get(int key) {
    if (key > maxSize) {return nullptr;}
    return storage[key];
}

void HashTable::add(Hashable* value) {
    storage[value->hash()%maxSize] = value;
    this->evaluate();
}

bool HashTable::containsKey(int key) {
    if (storage[key]==nullptr) return false;
    return true;
}

void HashTable::rebuild() {
    int old_maxSize = this->maxSize;
    maxSize*=2;
    vector<Hashable*> newStorage = vector<Hashable*>(this->maxSize,nullptr);
    for (int i = 0;i<storage.size();i++) {
        newStorage[storage[i]->hash()%maxSize] = storage[i];
    }
    this->storage = newStorage;
}

void HashTable::evaluate() {
    if (curSize/maxSize >= 0.75) {this->rebuild();}
}




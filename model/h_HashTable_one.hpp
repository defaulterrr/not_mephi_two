#ifndef HASHTABLEONE_H
#define HASHTABLEONE_H

#include "protocols.hpp"
#include <vector>
#include <iostream>
using namespace std;

/* Declaration */
class HashTable  {
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
    if(storage[value->hash()%maxSize] == nullptr) this->curSize++;
    storage[value->hash()%maxSize] = value;
    this->evaluate();
}

void HashTable::add(int key,Hashable* value) {
    storage[value->hash()%maxSize] = value;
    this->evaluate();
}

bool HashTable::containsKey(int key) {
    if (storage[key]==nullptr) return false;
    return true;
}

void HashTable::rebuild() {
    maxSize*=2;
    vector<Hashable*> newStorage = vector<Hashable*>(this->maxSize,nullptr);
    cout << "Initialized vector" << endl;
    for (int i = 0;i<storage.size();i++) {
        cout << "Index of old vector = " << i+1 << endl;
        if(storage[i]!=nullptr) {newStorage[storage[i]->hash()%(maxSize+1)] = storage[i];}
    }
    this->storage = newStorage;
}

void HashTable::evaluate() {
    if (curSize > maxSize*0.75) {cout << "Calling rebuild" << endl;this->rebuild();}
}



#endif
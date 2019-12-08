#ifndef HASHTABLEONE_H
#define HASHTABLEONE_H

#include "protocols.hpp"
#include <vector>
#include <iostream>
using namespace std;

/* Declaration */
class HashTableBasic  {
    public:
        HashTableBasic();
        int getCount();
        int getCapacity();
        Hashable* get(int key);
        bool containsKey(int key);
        void add(Hashable* value);
        void add(int key,Hashable* value);
        bool find(Hashable* value);

    private:
        void rebuild();
        void evaluate();

        /* Storages */
        vector<Hashable*> storage;
        int curSize = 0;
        int maxSize = 256;
        
};

/* Implementation */

HashTableBasic::HashTableBasic(){
    // Create empty vector filled with nullptrs
    storage = vector<Hashable*>(maxSize,nullptr);
}

int HashTableBasic::getCount() {
    return curSize;
}

int HashTableBasic::getCapacity() {
    return maxSize;
}

Hashable* HashTableBasic::get(int key) {
    if (key > maxSize) {return nullptr;}
    return storage[key];
}

void HashTableBasic::add(Hashable* value) {
    if(storage[value->hash()%maxSize] == nullptr) this->curSize++;
    storage[value->hash()%maxSize] = value;
    this->evaluate();
}

void HashTableBasic::add(int key,Hashable* value) {
    storage[value->hash()%maxSize] = value;
    this->evaluate();
}

bool HashTableBasic::containsKey(int key) {
    if (storage[key]==nullptr) return false;
    return true;
}

void HashTableBasic::rebuild() {
    maxSize*=2;
    vector<Hashable*> newStorage = vector<Hashable*>(this->maxSize,nullptr);
    vector<Hashable*> oldStorage = this->storage;
    this->storage = newStorage;
    this->curSize = 0;
    for (int i = 0;i<oldStorage.size();i++) {
        if(oldStorage[i]!=nullptr)
            this->add(oldStorage[i]);
    }
}

bool HashTableBasic::find(Hashable* value){
    if(this->get(value->hash()%maxSize) == nullptr)
        return false;
    if(this->get(value->hash()%maxSize) == value)
        return true;
    return false;
}

void HashTableBasic::evaluate() {
    if (curSize > maxSize*0.75) {cout << "Calling rebuild" << endl;this->rebuild();}
}



#endif
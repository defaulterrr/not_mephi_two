#ifndef HASHTABLETWO_H
#define HASHTABLETWO_H

#include "protocols.hpp"
#include <vector>
#include <iostream>
using namespace std;

/* Declaration */
class HashTableList: public Dictionary<int,Hashable*> {
    public:
        HashTableList();
        int getCount();
        int getCapacity();
        Hashable* get(int key);
        vector<Hashable*> getAll(int key);
        bool containsKey(int key);
        void add(Hashable* value);
        void add(int key,Hashable* value);

    private:
        void rebuild();
        void evaluate();

        /* Storages */
        vector<vector<Hashable*>> storage;
        int curSize = 0;
        int maxSize = 256;
        
};

/* Implementation */

HashTableList::HashTableList(){
    // Create empty vector filled with nullptrs
    // storage = vector<vector<Hashable*>>(maxSize,nullptr);
    storage = vector<vector<Hashable*>>();
    for (int i = 0; i<maxSize; i++) {
        vector<Hashable*> temp = vector<Hashable*>(1,nullptr);
        storage.push_back(temp);
    }
}

int HashTableList::getCount() {
    return curSize;
}

int HashTableList::getCapacity() {
    return maxSize;
}

Hashable* HashTableList::get(int key) {
    if (key > maxSize) {return nullptr;}
    if (storage[key][0] == nullptr) {return nullptr;}
    else {return storage[key][0];}
}

void HashTableList::add(Hashable* value) {
    // storage[value->hash()%maxSize] = value;
    storage[value->hash()%maxSize].push_back(value);
    this->evaluate();
}

bool HashTableList::containsKey(int key) {
    if (storage[key][0]==nullptr) return false;
    return true;
}

void HashTableList::rebuild() {
    maxSize*=2;
    vector<vector<Hashable*>> newStorage = vector<vector<Hashable*>>();
    for (int i = 0; i<maxSize; i++) {
        vector<Hashable*> temp = vector<Hashable*>(1,nullptr);
        newStorage.push_back(temp);
    }
    for (int i = 0;i<storage.size();i++) {
        if (storage[i][0]!=nullptr) {
            for (int j = 0; j<storage[i].size();j++) {
                newStorage[storage[i][j]->hash()%maxSize].push_back(storage[i][j]); 
            }
        }
    }
    this->storage = newStorage;
}

void HashTableList::evaluate() {
    if (curSize/maxSize >= 0.75) {this->rebuild();}
}



#endif
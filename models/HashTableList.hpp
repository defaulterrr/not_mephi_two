#ifndef HASHTABLETWO_H
#define HASHTABLETWO_H

#include "protocols.hpp"
#include <vector>
#include <iostream>
using namespace std;

/* Declaration */
class HashTableList {
    public:
        HashTableList();
        int getCount();
        int getCapacity();
        Hashable* get(int key);
        Hashable* get(int key, int n);
        vector<Hashable*> getAll(int key);
        bool containsKey(int key);
        void add(Hashable* value);
        void add(int key,Hashable* value);
        bool find(Hashable* value);

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

Hashable* HashTableList::get(int key, int n) {
    if (key > maxSize) {return nullptr;}
    if (storage[key][n] == nullptr) {return nullptr;}
    else {return storage[key][n];}
}

void HashTableList::add(Hashable* value) {
    int itr = value->hash()%maxSize;
    if( storage[itr][0] == nullptr) {
        storage[itr][0] = value;
        this->curSize++;
    }
    else {
        storage[itr].push_back(value);
    }

    this->evaluate();
}

bool HashTableList::containsKey(int key) {
    if (storage[key][0]==nullptr) return false;
    return true;
}

void HashTableList::rebuild() {
    maxSize*=2;
    vector<vector<Hashable*>> newStorage = vector<vector<Hashable*>>();
    vector<vector<Hashable*>> oldStorage = this->storage;
    this->curSize = 0;
    for (int i = 0; i<maxSize; i++) {
        vector<Hashable*> temp = vector<Hashable*>(1,nullptr);
        newStorage.push_back(temp);
    }
    this->storage = newStorage;
    for (int i = 0;i<oldStorage.size();i++) {
        if (oldStorage[i][0]!=nullptr) {
            for (int j = 0; j<oldStorage[i].size();j++) {
                this->add(oldStorage[i][j]);
            }
        }
    }
}

bool HashTableList::find(Hashable* value){
    vector<Hashable*> tmp = storage[value->hash()%maxSize];
    for(int i=0;i<tmp.size();i++){
        if(tmp[i] == value)
            return true;

    }
    return false;
}



void HashTableList::evaluate() {
    if (curSize/maxSize >= 0.75) {this->rebuild();}
}



#endif
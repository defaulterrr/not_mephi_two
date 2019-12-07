#ifndef HASHTABLETHREE_H
#define HASHTABLETHREE_H

#include "protocols.hpp"
#include <vector>
#include <iostream>
using namespace std;

/* Declaration */
class HashTableDist  {
    public:
        HashTableDist();
        int getCount();
        int getCapacity();
        Hashable* get(int key);
        bool containsKey(int key);
        void add(Hashable* value);
        void add(int key,Hashable* value);
        bool find(Hashable* value);
        bool find(Hashable* value, int k);

    private:
        void rebuild();
        void evaluate();

        /* Storages */
        vector<Hashable*> storage;
        int curSize = 0;
        int maxSize = 256;
        
};

/* Implementation */

HashTableDist::HashTableDist(){
    // Create empty vector filled with nullptrs
    storage = vector<Hashable*>(maxSize,nullptr);
}

int HashTableDist::getCount() {
    return curSize;
}

int HashTableDist::getCapacity() {
    return maxSize;
}

Hashable* HashTableDist::get(int key) {
    if (key > maxSize) {return nullptr;}
    return storage[key];
}

void HashTableDist::add(Hashable* value) {
    int k = value->hash()%maxSize;
    if(storage[k] == nullptr) {
        storage[k] = value;
        this->curSize++;
        this->evaluate();
    } 
    else {
        this->add(k+1, value);
    }
    
    
}

void HashTableDist::add(int k,Hashable* value) {
    if(k>=maxSize)
        k-=maxSize;
    if(storage[k] == nullptr) {
        storage[k] = value;
        this->curSize++;
        this->evaluate();
    }
    else {
        add(k+1,value);
    }
}

bool HashTableDist::containsKey(int key) {
    if (storage[key]==nullptr) return false;
    return true;
}

bool HashTableDist::find(Hashable* value){
    if(this->get(value->hash()%maxSize) == nullptr)
        return false;
    if(this->get(value->hash()%maxSize) == value)
        return true;
    find(value, value->hash()%maxSize+1);
}

bool HashTableDist::find(Hashable* value, int k){
    if(k>=maxSize)
        k-=maxSize;
    if(this->get(k) == nullptr)
        return false;
    if(this->get(k) == value)
        return true;
    find(value, k+1);
}

void HashTableDist::rebuild() {
    maxSize*=2;
    vector<Hashable*> newStorage = vector<Hashable*>(this->maxSize,nullptr);
    cout << "Initialized vector" << endl;
    for (int i = 0;i<storage.size();i++) {
        cout << "Index of old vector = " << i+1 << endl;
        if(storage[i]!=nullptr) {newStorage[storage[i]->hash()%(maxSize+1)] = storage[i];}
    }
    this->storage = newStorage;
}

void HashTableDist::evaluate() {
    if (curSize > maxSize*0.75) {cout << "Calling rebuild" << endl;this->rebuild();}
}



#endif
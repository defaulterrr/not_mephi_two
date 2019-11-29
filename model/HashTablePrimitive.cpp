#include "HashTablePrimitive.hpp"

template<typename Key, typename Any> HashTablePrimitive<Key,Any>::HashTablePrimitive() {
    try {
        this->storage = std::vector<Any>(STARTINGPOINT);
        for (uint32_t i = 0; i<this->storage.size(); i++) {
            this->storage[i] = nullptr;
        }
        this->maxSize = STARTINGPOINT;
        this->curSize = 0;
    } catch (std::exception e) {
        e.what();
        std::cout << "Failure during hash-table\'s storage creation" << std::endl;
        exit(1);
    }
}

template<typename Key, typename Any> HashTablePrimitive<Key,Any>::HashTablePrimitive(HashTablePrimitive &source) {
    try {
        this->storage = std::vector<Any>(source);
        this->curSize = source.curSize;
        this->maxSize = source.maxSize;
    } catch (std::exception e){
        e.what();
        std::cout << "Failure during hash-table\'s storage copy creation" << std::endl;
        exit(1);
    }
}

template<typename Key, typename Any> void HashTablePrimitive<Key,Any>::rebuild() {
    // this func is always called, so its here where you are supposed to check for a need of rebuilding
    if (curSize/maxSize < BREAKPOINT) {return;} else {
        try {
            std::vector<Any> newStorage = std::vector<Any>(this->maxSize*BASE);
            for (int i = 0; i < newStorage.size(); i++) {newStorage[i] = nullptr;};
            for (int i = 0; i < this->storage.size(); i++) {newStorage[this->storage[i].hash(this->curSize)] = this->storage[i];};
        }   catch (std::exception e) {
            e.what();
            std::cout << "Failure during hash-table rebuilding" << std::endl;
            exit(1);
        }
    } 
}

template<typename Key, typename Any> int HashTablePrimitive<Key,Any>::getCount() {
    if (this->curSize == -1) {return -1;} else {return this->curSize;}
}

template<typename Key, typename Any> int HashTablePrimitive<Key,Any>::getCapacity() {
    return this->maxSize;
}

template<typename Key, typename Any> bool HashTablePrimitive<Key,Any>::containsKey(Key key) {
    try {if (this->storage[key] == nullptr) return true;} 
    catch (std::exception e) {
        std::cout << "Failure during containsKey check\n";
        }
    return false;
}

template<typename Key, typename Any> Any HashTablePrimitive<Key,Any>::get(Key key) {
    try {
            if (this->storage[key] != nullptr) {
            return this->storage[key];
            } else {return nullptr;}}

            catch (std::exception e) {
                std::cout << "Failure while returning element by key" << std::endl;
            }
}

template<typename Key, typename Any> void HashTablePrimitive<Key,Any>::add(Key key, Any element) {

}
#include "../protocols/Dictionary.hpp"
#include <exception>
#include <iostream>
#include <vector>

int BASE = 2;
int STARTINGPOINT = 256;
double BREAKPOINT = 0.75;

template<typename Key, typename Any>
class HashTablePrimitive: public Dictionary<Key,Any> {
private:
    std::vector<Any> storage;
    int maxSize;
    int curSize = -1;
    void rebuild();
public:
    HashTablePrimitive();
    HashTablePrimitive(HashTablePrimitive &source);

    ~HashTablePrimitive();

    int getCount();
    int getCapacity();
    bool containsKey(Key key);
    Any get(Key key);
    void add(Key key, Any element);
    void remove(Key key);
};
#include <vector>

#ifndef Dictionary_H
#define Dictionary_H

template<typename Key, typename Any>
class Dictionary {
public:
    virtual int getCount() = 0;
    virtual int getCapacity() = 0;
    virtual bool containsKey(Key key) = 0;
    virtual Any get(Key key) = 0;
    virtual void add(Key key,Any element) = 0;
    virtual void remove(Key key) = 0;
private:
    
};

#endif
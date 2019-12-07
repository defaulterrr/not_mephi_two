#include <iostream>

#ifndef MEPHI_LAB_0_SEQUENCE_H
#define MEPHI_LAB_0_SEQUENCE_H

template<class TElement>
class Sequence {
protected:
    int length_;
private:

public:

    Sequence() { //Default constructor
        length_ = 0;
    }

    Sequence(Sequence<TElement> *toCopyFrom) { //Copy constructor

    }

    bool getIsEmpty() { //Returns false if sequence is not empty and true if it is empty
        return length_ <= 0;
    }

    int getLength() { //Get length
        return length_;
    }

    virtual Sequence<TElement> *getSubsequence(int i, int j) = 0; //Abstract class can't be returned. Only pointer

    virtual TElement getFirst() = 0; //Get first item in sequence

    virtual TElement getLast() = 0; //Get last item in sequence

    virtual void append(TElement item) = 0; //Add new item to the end of sequence

    virtual void prepend(TElement item) = 0; //Add new item to the start of sequence

    virtual void insertAt(int index, TElement item) = 0; //Insert new item between [index] and [index-1]

    virtual void remove(TElement item) = 0; //Remove item

    virtual TElement get(int index) = 0; //Get item by index

    virtual void swap(int i, int j) = 0; //Swap two elemetns

    virtual void setElement (int index, TElement toSet) = 0;

    virtual ~Sequence() {

    }
};


#endif //MEPHI_LAB_0_SEQUENCE_H

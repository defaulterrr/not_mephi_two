#include <iostream>
#include <cstdlib>
#include "Sequence.h"

template<class TElement>
class Array : public Sequence<TElement> {
private:
    TElement *items;//Array of elements
public:
    explicit Array() : Sequence<TElement>() { //Create empty list
        //Initialize with length_ 0
    }

    Array(Sequence<TElement> *seq) : Sequence<TElement>() { //Copy constructor. Allows implicit conversion
        for (int i = 0; i < seq->getLength(); i++) {
            append(seq->get(i));
        }
    }//Example  Array<int> test_array_2 = &test_array;

    explicit Array(TElement newItem) : Sequence<TElement>() { //Create list with one item
        append(newItem);
    }

    Array<TElement> *getSubsequence(int i, int j) { //Indexes should start from 0
        if (i < 0 || j < 0 || i >= this->length_ || j >= this->length_) {
            throw std::out_of_range("Invalid parameters");
        }

        auto *new_array = new Array<TElement>(); //Auto - automatically detects type

        for (; i <= j; i++) {
            new_array->append(items[i]);
        }

        return new_array;
    }

    ~Array() override {
        delete(items);
    }

    TElement getFirst() {
        if (this->getIsEmpty()) {
            throw std::length_error("Array is empty");
        }
        return items[0];
    }

    TElement getLast() {
        if (this->getIsEmpty()) {
            throw std::length_error("Array is empty");
        }
        return items[this->length_ - 1];
    }

    void append(TElement item) {

        if (this->getIsEmpty()) {
            this->length_++;
            items = new TElement[1];
        } else {
            this->length_++;
            items = (TElement *) realloc(items, this->length_ * sizeof(TElement));
        }

        items[this->length_ - 1] = item;
    }

    void prepend(TElement item) {
        if (this->getIsEmpty()) {
            this->length_++;
            items = new TElement[1];
        } else {
            this->length_++;
            items = (TElement *) realloc(items, this->length_ * sizeof(TElement));
        }
        for (int i = this->length_ - 2; i >= 0; i--) {
            items[i + 1] = items[i];
        }
        items[0] = item;
    }

    void insertAt(int index, TElement item) { //Index starts from 0
        if (index < 0 || index >= this->length_) {
            throw std::out_of_range("Invalid parameter");
        }

        this->length_++;

        items = (TElement *) realloc(items, this->length_ * sizeof(TElement));

        for (int j = this->length_ - 2; j >= index; j--) {
            items[j + 1] = items[j];
        }

        items[index] = item;
    }

    void remove(TElement item) {

        bool found = false;

        for (int i = 0; i < this->length_ - 1; i++) {
            if (items[i] == item) {
                for (int j = i; j < this->length_ - 1; j++) {
                    items[j] = items[j + 1];
                }
                found = true;
                this->length_--;
                items = (TElement *) realloc(items, this->length_ * sizeof(TElement));
                break;
            }
        }

        if (!found) {
            //Do something
        }

    }

    TElement get(int index) {
        if (index < 0 || index >= this->length_) {
            throw std::out_of_range("Invalid parameter");
        }

        return items[index];
    }

    void swap(int i, int j) {
        int temp = items[i];
        items[i] = items[j];
        items[j] = temp;
    }

    void setElement(int index, TElement toSet) {
        items[index] = toSet;
    }
};


#include <iostream>
#include "Sequence.h"
#include "Node.h"

#ifndef MEPHI_LAB_0_LIST_H
#define MEPHI_LAB_0_LIST_H

template<typename TElement>
class List : public Sequence<TElement> {
private:
    Node<TElement> *head_;
    Node<TElement> *tail_;

    Node<TElement> *current_;
public:

    explicit List() : Sequence<TElement>() { //Create empty list
        head_ = nullptr;
        tail_ = nullptr;
    }

    explicit List(TElement item) : Sequence<TElement>() { //Create list with one item
        head_ = new Node<TElement>(item);
        tail_ = head_;

        this->length_++;
    }

    List(Sequence<TElement> *seq) : Sequence<TElement>() { //Copy list. Allows implicit conversion
        for (int i = 0; i < seq->getLength(); i++) {
            append(seq->get(i));
        }
    } //Example List<int> test_list_2 = &test_list;

    ~List() override {
        if (!this->getIsEmpty()) {
            if (head_->getNext() != nullptr) {
                current_ = head_->getNext();
                while (current_ != nullptr) {
                    delete (current_->getPrev());
                    current_ = current_->getNext();
                }
            } else {
                delete (head_);
            }
        }
        if (this->length_ != 1) {
            delete (tail_);
        }
    }

    List<TElement> *getSubsequence(int i, int j) {

        if (i < 0 || j < 0 || i >= this->length_ || j >= this->length_) {
            throw std::out_of_range("Invalid parameters");
        }

        current_ = head_;
        for (int g = 0; g < i; g++) {
            current_ = current_->getNext();
        }

        auto *newList = new List<TElement>();

        for (; i <= j; i++) {
            newList->append(current_->getItem());
            current_ = current_->getNext();
        }

        return newList;

    }

    TElement popFirst() {
        TElement item = head_->getItem();
        head_ = head_->getNext();
        delete (head_->getPrev());
        return item;
    }

    TElement popLast() {
        TElement item = tail_->getItem();
        tail_ = tail_->getPrev();
        delete (tail_->getNext());
        return item;
    }

    TElement getFirst() {
        if (this->getIsEmpty()) {
            throw std::length_error("List is empty");
        }
        return head_->getItem();
    }

    TElement getLast() {
        if (this->getIsEmpty()) {
            throw std::length_error("List is empty");
        }
        return tail_->getItem();
    }

    void append(TElement item) {
        auto *newElement = new Node<TElement>(item);

        if (this->getIsEmpty()) {
            tail_ = newElement;
            head_ = newElement;
        } else {
            tail_->setNext(newElement);
            newElement->setPrev(tail_);
            tail_ = newElement;
        }
        this->length_++;
    }

    void prepend(TElement item) {
        auto *newElement = new Node<TElement>(item);
        if (this->getIsEmpty()) {
            tail_ = newElement;
            head_ = newElement;
        } else {
            head_->setPrev(newElement);
            newElement->setNext(head_);
            head_ = newElement;
        }
        this->length_++;
    }

    TElement get(int index) {

        if (index < 0 || index >= this->length_) {//Exception
            throw std::out_of_range("Invalid parameter");

        }

        current_ = head_;
        for (int i = 0; i < index; i++) {
            current_ = current_->getNext();
        }

        return current_->getItem();
    }

    void insertAt(int index, TElement item) {

        if (index < 0 || index >= this->length_) {
            throw std::out_of_range("Invalid parameter"); //Exception
        }

        this->length_++;

        current_ = head_;
        for (int i = 0; i < index; i++) {
            current_ = current_->getNext();
        }

        auto *newNode = new Node<TElement>(item);

        if (current_->getPrev() != nullptr) {
            current_->getPrev()->setNext(newNode);
            newNode->setPrev(current_->getPrev());

        } else {
            head_ = newNode;
        }

        current_->setPrev(newNode);
        newNode->setNext(current_);


    }

    void remove(TElement item) {
        current_ = head_;

        while (current_->getItem() != item) {
            current_ = current_->getNext();
        }

        if (current_ == head_) {
            head_ = head_->getNext();
        } else if (current_ == tail_) {
            tail_ = tail_->getPrev();
        } else {
            return; //Exit without remove
        }

        delete current_;

        this->length_--;
    }

    void swap(int i, int j) {
        current_ = head_;
        for (int g = 0; g < i; g++) {
            current_ = current_->getNext();
        }
        Node<TElement> *first = current_;

        current_ = head_;
        for (int g = 0; g < j; g++) {
            current_ = current_->getNext();
        }

        Node<TElement> *second = current_;

        TElement tmpData = first->getItem();
        first->setitem(second->getItem());
        second->setitem(tmpData);
    }

    void setElement (int index, TElement toSet) {
        if (index < 0 || index >= this->length_) {
            throw std::out_of_range("Invalid parameter"); //Exception
        }
        if(index == 0) {
            head_->setitem(toSet);
        }
        else if(index == (this->length_-1)) {
            tail_->setitem(toSet);
        }
        else {
            current_ = head_;
            for (int i = 0; i < index; i++) {
            current_ = current_->getNext();
            }
            current_->setitem(toSet);
        }
        
    }
};


#endif //MEPHI_LAB_0_LIST_H

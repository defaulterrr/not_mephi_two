#include <iostream>
#include "Sequence.hpp"
#include "Node.hpp"
using namespace std;

#ifndef SORTEDSEQUENCE_HPP
#define SORTEDSEQUENCE_HPP

template<typename TElement>
class SortedSequence : public Sequence<TElement> {
private:

	Node<TElement>* head_;
	Node<TElement>* tail_;

	Node<TElement>* current_;

public:

	explicit SortedSequence() : Sequence<TElement>() { //Create empty list
		head_ = nullptr;
		tail_ = nullptr;
	}

	explicit SortedSequence(TElement item) : Sequence<TElement>() { //Create list with one item
		head_ = new Node<TElement>(item);
		tail_ = head_;

		this->length_++;
	}

	SortedSequence(Sequence<TElement>* seq) : Sequence<TElement>() { //Copy list. Allows implicit conversion
		for (int i = 0; i < seq->getLength(); i++) {
			append(seq->get(i));
		}
	} //Example SortedSequence<int> test_list_2 = &test_list;

	~SortedSequence() override {
		if (!this->getIsEmpty()) {
			if (head_->getNext() != nullptr) {
				current_ = head_->getNext();
				while (current_ != nullptr) {
					delete (current_->getPrev());
					current_ = current_->getNext();
				}
			}
			else {
				delete (head_);
			}
		}
		if (this->length_ != 1) {
			delete (tail_);
		}
	}

	SortedSequence<TElement>* getSubsequence(int i, int j) {

		if (i < 0 || j < 0 || i >= this->length_ || j >= this->length_) {
			throw std::out_of_range("Invalid parameters");
		}

		current_ = head_;
		for (int g = 0; g < i; g++) {
			current_ = current_->getNext();
		}

		auto* newList = new SortedSequence<TElement>();

		for (; i <= j; i++) {
			newList->append(current_->getItem());
			current_ = current_->getNext();
		}

		return newList;

	}

	int indexOf(TElement item){
		if(tail_->getItem() == item){
			return this->getLength()-1;
		}
		if(head_->getItem() == item){
			return 0;
		}
		Node<TElement>* current=head_;
		int tmp=0;
		while(true){
			if(current->getNext() == nullptr || tmp == this->getLength()){
				return -1;
			}
			if(current->getNext()->getItem()==item){
				return tmp+1;
			}
			tmp++;
			current=current->getNext();

		}
	}

	int binarySearch(TElement elem, int left, int right){


		int midd = 0;
		while (true)
		{
			midd = (left + right) / 2;
			if (elem < this->get(midd))       
				right = midd - 1;     
			else if (elem > this->get(midd))  
				left = midd + 1;    
			else                       
				return midd;           
			
			if (left > right)         
				return -1;
		}
}

	int binarySearchProportion(TElement elem, int first, int second, int left, int right){



		int midd = 0;
		int k=0;
		while (true)
		{	
			midd = ((right - left)*first)/(first+second);
			midd+=left;
			if (elem < this->get(midd))       
				right = midd - 1;     
			else if (elem > this->get(midd))  
				left = midd + 1;    
			else                       
				return midd;           
			
			if (left > right)         
				return -1;
				
		}
}

	TElement popFirst() {}
	TElement popLast() {}

    
	TElement getFirst() {
		if (this->getIsEmpty()) {
			throw std::length_error("Sequence is empty");
		}
		return head_->getItem();
	}

	TElement getLast() {
		if (this->getIsEmpty()) {
			throw std::length_error("Sequence is empty");
		}
		return tail_->getItem();
	}


	void add(TElement item) {
		auto* newElement = new Node<TElement>(item);
		if (this->getIsEmpty()) {
			tail_ = newElement;
			head_ = newElement;
            
		}
		else if (newElement->getItem() <= head_->getItem()) {
			head_->setPrev(newElement);
			newElement->setNext(head_);
			head_ = newElement;
		}
		else
		{
			Node<TElement>* current = head_;
			while (true) {
				if (current->getNext() == nullptr) {
					current->setNext(newElement);
                    this->tail_ = newElement;
					newElement->setPrev(current);
					break;
				}
				if (current->getNext() != nullptr && (newElement->getItem() < current->getNext()->getItem())) {
					current->getNext()->setPrev(newElement);
                    newElement->setNext(current->getNext());
					current->setNext(newElement);
					break;
				}
				current = current->getNext();
			}

			
		}
        this->length_++;
	}
		void append(TElement item) {}

		void prepend(TElement item) {}

		TElement get(int index) {
			if (index < 0 || index >= this->length_) {//Exception
				throw std::out_of_range("Invalid parameter");

			}
			
			if(index<int(this->length_)/2){
				current_ = head_;
				for (int i = 0; i < index; i++) {
					current_ = current_->getNext();
				}

				return current_->getItem();
			}
			else
			{
				current_ = tail_;
				for (int i = 0; i < this->length_-index-1; i++) {
					current_ = current_->getPrev();
			}

			return current_->getItem();
			}
			
			
		}

		void insertAt(int index, TElement item){}

		void remove(TElement item) {
			current_ = head_;

			while (current_->getItem() != item) {
				current_ = current_->getNext();
			}

			if (current_ == head_) {
				head_ = head_->getNext();
			}
			else if (current_ == tail_) {
				tail_ = tail_->getPrev();
			}
			else {
				return; //Exit without remove
			}

			delete current_;

			this->length_--;
		}

		void swap(int i, int j) {}

		void setElement(int index, TElement toSet) {}
	};

#endif 
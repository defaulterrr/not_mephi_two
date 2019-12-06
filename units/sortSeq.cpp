#include "../models/SortedSequence.hpp"
using namespace std;



int main() {
    cout << "start";
	SortedSequence<int> s = new SortedSequence<int>();
    s.add(3);
    s.add(2);
    s.add(1);
    s.add(4);
    s.add(5);
    s.add(2);
    cout <<  s.getLast() << s.getFirst();
    cout << "    "<< s.getLast() << s.getFirst();
    cout <<  "\n "<< s.getLength() << s.get(5);
    cout <<  "\n ts"<< s.get(s.indexOf(5));
    cout <<  "\n ts"<< s.get(s.indexOf(4)) << "ssss";
    cout <<  "\n ts"<< s.get(s.indexOf(1));
    cout <<  "\n ts"<< s.get(s.indexOf(2));
    cout <<  "\n sear "<< s.get(s.binarySearch(2, 0, s.getLength()-1));
    cout <<  "\n sear "<< s.get(s.binarySearch(1, 0, s.getLength()-1));
    cout <<  "\n sear "<< s.get(s.binarySearch(4, 0, s.getLength()-1));
    cout <<  "\n sear "<< s.get(s.binarySearch(5, 0, s.getLength()-1));
    cout <<  "\n sear "<< s.get(s.binarySearch(3, 0, s.getLength()-1));
    cout <<  "\n searx "<< (s.binarySearch(3, 0, s.getLength()-1));
    cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(3, 1, 4, 0, s.getLength()-1));
    cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(4, 1, 4, 0, s.getLength()-1));
    cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(5, 1, 4, 0, s.getLength()-1));
	cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(2, 1, 4, 0, s.getLength()-1));
    cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(3, 2, 1, 0, s.getLength()-1));
    cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(4, 2, 1, 0, s.getLength()-1));
    cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(5, 2, 1, 0, s.getLength()-1));
	cout <<  "\n sear2 "<< s.get(s.binarySearchProportion(2, 2, 1, 0, s.getLength()-1));

}

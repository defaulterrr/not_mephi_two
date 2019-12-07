#include "../models/SortedSequence.hpp"
#include "../models/h_Person.hpp"
using namespace std;



int main() {
    cout << "start";
    SortedSequence<Person> p = new SortedSequence<Person>();
    p.add(Person("Mike","Ross","mross@harvard.edu",1988));
    p.add(Person("Mike","Ross","mross@harvard.edu",1987));
    p.add(Person("Mike","Ross","mross@harvard.edu",1986));
    p.add(Person("Mike","Ross","mross@harvard.edu",1985));
    cout <<  "\n Test for person "<< (p.binarySearch(Person("Mike","Ross","mross@harvard.edu",1985), 0, p.getLength()-1));
	cout <<  "\n Another test "<< (p.indexOf(Person("Mike","Ross","mross@harvard.edu",1987)));
    SortedSequence<int> s = new SortedSequence<int>();
    s.add(3);
    s.add(2);
    s.add(1);
    s.add(4);
    s.add(5);
    s.add(2);
    cout << " \n" << s.getLast() << s.getFirst();
    cout << "    "<< s.getLast() << s.getFirst();
    cout <<  "\n "<< s.getLength() << s.get(5);
    cout <<  "\n "<< s.get(s.indexOf(5));
    cout <<  "\n "<< s.get(s.indexOf(4));
    cout <<  "\n "<< s.get(s.indexOf(1));
    cout <<  "\n "<< s.get(s.indexOf(2));
    cout <<  "\n "<< s.get(s.binarySearch(2, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearch(1, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearch(4, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearch(5, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearch(3, 0, s.getLength()-1));
    cout <<  "\n Last search: "<< (s.binarySearch(3, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearchProportion(3, 1, 4, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearchProportion(4, 1, 4, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearchProportion(5, 1, 4, 0, s.getLength()-1));
	cout <<  "\n "<< s.get(s.binarySearchProportion(2, 1, 4, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearchProportion(3, 2, 1, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearchProportion(4, 2, 1, 0, s.getLength()-1));
    cout <<  "\n "<< s.get(s.binarySearchProportion(5, 2, 1, 0, s.getLength()-1));
	cout <<  "\n "<< s.get(s.binarySearchProportion(2, 2, 1, 0, s.getLength()-1));

}

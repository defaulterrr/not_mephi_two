using namespace std;



bool sortSeqTests() {
    bool suc = true;
    cout << "Start tests for SortedSequence<Person>\n";
    SortedSequence<Person> p = new SortedSequence<Person>();
    cout << "Add Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1988)\n";
    p.add(Person("Mike","Ross","mross@harvard.edu",1988));
    cout << "Add Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1987)\n";
    p.add(Person("Mike","Ross","mross@harvard.edu",1987));
    cout << "Add Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1986)\n";
    p.add(Person("Mike","Ross","mross@harvard.edu",1986));
    cout << "Add Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1985)\n";
    p.add(Person("Mike","Ross","mross@harvard.edu",1985));
    cout << "Length test\n";
    if (p.getLength()==4)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    cout << "Binary search test for Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1985)\n";
    if ((p.binarySearch(Person("Mike","Ross","mross@harvard.edu",1985), 0, p.getLength()-1))==0)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    cout << "Proportional binary search test for Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1988)\n";
    if (p.binarySearchProportion(Person("Mike","Ross","mross@harvard.edu",1988),1,3, 0, p.getLength()-1)==3)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    cout << "Search test for Person(\"Mike\",\"Ross\",\"mross@harvard.edu\",1987)\n";
    if ((p.indexOf(Person("Mike","Ross","mross@harvard.edu",1987))==2))
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    cout << "Start tests for SortedSequence<int>\n";
    SortedSequence<int> s = new SortedSequence<int>();
    cout << "Add 3,2,1,4,5,2 to Sequence\n";
    s.add(3);
    s.add(2);
    s.add(1);
    s.add(4);
    s.add(5);
    s.add(2);
    cout << "Length test\n";
    if (s.getLength()==6)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    cout << "Test does the last element equal to 5\n";
    if (s.getLast()==5)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }
    cout << "Search test\n";
    if (s.get(s.indexOf(4))==4)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    cout << "Binary search test\n";
    if (s.get(s.binarySearch(3, 0, s.getLength()-1))==3)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }

    cout << "Proportional binary search test\n";
    if (s.get(s.binarySearchProportion(4, 2, 1, 0, s.getLength()-1))==4)
        cout << "Test passed\n\n";
    else{
        cout << "Test Failed\n\n";
        suc=false;
    }
    return suc;

}



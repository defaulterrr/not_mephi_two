#ifndef ENGINE_H
#define ENGINE_H
#include "lib.hpp"
#include <map>
#include <iostream>
#include "../units/person.cpp"
#include "../units/sortSeq.cpp"
#include "../units/hashtable.cpp"
using namespace std;

template<typename T> T evaluate(string message, std::map<string,T> options) {
    auto itr = options.find(message);
    if( itr != options.end() ) {
        return options.at(message);
    }
    return (T)404;
}

enum StorageType {
    Hashtable,
    Seq,
    Test
};

enum HashTableType {
    Basic,
    List,
    Shift
};

enum SequenceType {
    Simple,
    Binary,
    BinaryProp
};

enum GenerationType {
    Manual,
    Random
};

class Application {
    public:
        Application() {
            print("Initializing shell");

        }

        void run() {
            eventLoop();
        }

    private:
        string base;
        void eventLoop() {
            int succesful = 0;
            while (!succesful) {
                print("Select type of container or run tests: Hashtable or Seq or Test");
                string first = getCommand();
                Command task = Command(first);
                map<string,StorageType> options1 = {
                        {"Hashtable",StorageType::Hashtable},
                        {"Seq",StorageType::Seq},
                        {"Test",StorageType::Test}
                    };
                switch (evaluate<StorageType>(task.base(),options1))
                {
                    case StorageType::Test:
                        print("Start tests");
                        succesful=1;
                        Tests();
                        break;
                    case StorageType::Hashtable:
                        print("Using Hash-Table to store elements");
                        succesful=1;
                        HashTable();
                        break;
                    case StorageType::Seq:
                        print("Using Seq to store elements");
                        succesful=1;
                        Seq();
                        break;



                    case 404:
                        print("Invalid command was entered");
                        break;

                    default:
                        print("Undefined behaviour");
                        break;
                }
            }
        }

                void Tests(){
                    if (sortSeqTests() && personTests() && hashTests())
                        cout <<"\n\nAll tests passed!\n";
                    else
                        cout <<"\n\nTests failed\n";
                }

                void HashTable() {
                    print("Select type of Hash-table: Basic,List,Shift");
                    string second = getCommand();
                    Command task = Command(second);
                    map<string,HashTableType> options2 {{"Basic",HashTableType::Basic},{"Shift",HashTableType::Shift},{"List",HashTableType::List}};

                    switch (evaluate<HashTableType>(task.base(),options2))
                    {
                    case HashTableType::Basic:
                        internal_HashTable_Basic();
                        break;

                    case HashTableType::List:
                        internal_HashTable_List();
                        break;

                    case HashTableType::Shift:
                        internal_HashTable_Shift();
                        break;
                    
                    default:
                        break;
                    }
                }

                        void internal_HashTable_Basic() {
                            HashTableBasic table = HashTableBasic();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);
                            Person* searchfor;

                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                table.add(dummy);
                                if(i == amount-1)
                                    searchfor = dummy;
                            }
                            clock_t start, end;
                            start = clock();
                            table.find(searchfor);
                            end = clock();
                            printf("The search was executed in %.7f sec for %d elements\n", ((double) end - start) / ((double) CLOCKS_PER_SEC), amount);

                        }

                        void internal_HashTable_Shift() {
                            HashTableDist table = HashTableDist();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);
                            Person* searchfor;
                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                table.add(dummy);
                                if(i == amount-1)
                                    searchfor = dummy;
                            }
                            clock_t start, end;
                            start = clock();
                            table.find(searchfor);
                            end = clock();
                            printf("The search was executed in %.7f sec for %d elements\n", ((double) end - start) / ((double) CLOCKS_PER_SEC), amount);

                        }

                        void internal_HashTable_List() {
                            HashTableList table = HashTableList();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);
                            Person* searchfor;
                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                table.add(dummy);
                                if(i == amount-1)
                                    searchfor = dummy;
                            }
                            clock_t start, end;
                            start = clock();
                            table.find(searchfor);
                            end = clock();
                            printf("The search was executed in %.7f sec for %d elements\n", ((double) end - start) / ((double) CLOCKS_PER_SEC), amount);

                        }

                void Seq() {
                    print("Select search type: Simple, PropBinary or Binary");
                    string third = getCommand();
                    Command task = Command(third);
                    map<string,SequenceType> options {{"Simple",Simple},{"Binary",Binary},{"PropBinary",BinaryProp}};

                    switch (evaluate<SequenceType>(task.base(),options)) {
                        case Simple:
                            BaseSearch();
                            break;

                        case Binary:
                            BinarySearch();
                            break;

                        case BinaryProp:
                            BinaryPropSearch();
                            break;

                        default:
                            break;
                    }
                }

                        void BaseSearch() {
                            SortedSequence<Person> seq = SortedSequence<Person>();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);
                            Person* searchfor;
                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                seq.add(*dummy);
                                if(i == amount-1)
                                    searchfor = dummy;
                            }
                            clock_t start, end;
                            start = clock();
                            seq.indexOf(*searchfor);
                            end = clock();
                            printf("The search was executed in %.7f sec for %d elements\n", ((double) end - start) / ((double) CLOCKS_PER_SEC), amount);

                        }

                        void BinarySearch() {
                            SortedSequence<Person> seq = SortedSequence<Person>();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);
                            Person* searchfor;
                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                seq.add(*dummy);
                                if(i == amount-1)
                                    searchfor = dummy;
                            }
                            clock_t start, end;
                            start = clock();
                            seq.binarySearch(*searchfor, 0, seq.getLength()-1);
                            end = clock();
                            printf("The search was executed in %.7f sec for %d elements\n", ((double) end - start) / ((double) CLOCKS_PER_SEC), amount);

                        }



                        void BinaryPropSearch() {
                            SortedSequence<Person> seq = SortedSequence<Person>();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);
                            print("Enter coefficients of proportionality ");
                            string four = getCommand();
                            int k1 = stoi(four);
                            string five = getCommand();
                            int k2 = stoi(five);
                            Person* searchfor;
                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                seq.add(*dummy);
                                if(i == amount-1)
                                    searchfor = dummy;
                            }
                            clock_t start, end;
                            start = clock();
                            seq.binarySearchProportion(*searchfor, k1, k2, 0, seq.getLength()-1);
                            end = clock();
                            printf("The search was executed in %.7f sec for %d elements\n", ((double) end - start) / ((double) CLOCKS_PER_SEC), amount);

                        }
        string getCommand(){
            string commandToGet;
            getline(cin,commandToGet);
            if (commandToGet.empty()) {return "unkn";} else return commandToGet;
        }

        void print(string message) {
            cout << message << endl;
        }
};

#endif
#ifndef ENGINE_H
#define ENGINE_H
#include "lib.hpp"
#include <map>
#include <iostream>
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
    Set
};

enum HashTableType {
    Basic,
    List,
    Shift
};

enum SequenceType {
    Sequence,
    SortedSequence
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
                print("Select type of container: Hash-table or Set");
                string first = getCommand();
                Command task = Command(first);
                map<string,StorageType> options1 = {
                        {"Hash-table",StorageType::Hashtable},
                        {"Set",StorageType::Set}
                    };
                switch (evaluate<StorageType>(task.base(),options1))
                {
                case StorageType::Hashtable:
                    print("Using Hash-Table to store elements");
                    succesful=1;
                    break;
                case StorageType::Set:
                    print("Using Set to store elements");
                    succesful=1;
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

                        break;

                    case HashTableType::Shift:
                        break;
                    
                    default:
                        break;
                    }
                }

                        void internal_HashTable_Basic() {
                            auto table = HashTable::HashTable();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);

                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                table.add(dummy);
                            }
                                // TODO: DENCHIK SUDA KOD VSTAV
                        }
        
                //TODO
                void Set() {

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
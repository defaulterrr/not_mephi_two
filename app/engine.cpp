#ifndef ENGINE_H
#define ENGINE_H
#include "Command.h"
#include "../model/h_HashTable_one.hpp"
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
    HashTable,
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
                map<string,StorageType> options {{"Hash-table",HashTable},{"Set",Set}};
                switch (evaluate<StorageType>(task.base(),options))
                {
                case HashTable:
                    print("Using Hash-Table to store elements");
                    succesful=1;
                    break;
                case Set:
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
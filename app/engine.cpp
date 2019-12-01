#ifndef ENGINE_H
#define ENGINE_H
#include "Command.h"
#include "../model/h_HashTable_one.hpp"
#include <map>
#include <iostream>
using namespace std;

enum MajorComms {
    Create,
    Fill,
    Search,
    Delete,
    Test,
    InvalidM
};

enum GenerationType {
    Random,
    Manual,
    InvalidG
};

enum ContainerTypes {
    HashTable,
    Sequence,
    InvalidC
};

enum hashTypes {
    basic,
    list,
    shift,
    invalidH
};

enum seqTypes {
    seq,
    sortSeq,
    invalidS
};

enum sortSeqSearches {
    binary,
    basicS,
    binaryCool,
    invalidSearch
};

hashTypes resolveH(string command) {
    static const std::map<std::string, hashTypes> optionStrings {
        {"basic", basic },
        {"list", list},
        {"shift", shift}
    };

    auto itr = optionStrings.find(command);
    if( itr != optionStrings.end() ) {
        return optionStrings.at(command);
    }
    return hashTypes::invalidH; 
}

seqTypes resolveS(string command) {
    static const std::map<std::string, seqTypes> optionStrings {
        {"sequence", seq },
        {"sortedSequence", sortSeq}
    };

    auto itr = optionStrings.find(command);
    if( itr != optionStrings.end() ) {
        return optionStrings.at(command);
    }
    return seqTypes::invalidS; 
}

// Resolve top-level command
MajorComms resolveM(string command) {
    static const std::map<std::string, MajorComms> optionStrings {
        { "create", Create },
        { "fill", Fill },
        { "search", Search },
        { "delete", Delete },
        { "test", Test }
    };

    auto itr = optionStrings.find(command);
    if( itr != optionStrings.end() ) {
        return optionStrings.at(command);
    }
    return MajorComms::InvalidM; 
}
// Resolve generation type
GenerationType resolveG(string command) {
    static const std::map<std::string, GenerationType> optionStrings {
        { "random", Random },
        { "manual", Manual }
    };

    auto itr = optionStrings.find(command);
    if( itr != optionStrings.end() ) {
        return optionStrings.at(command);
    }
    return GenerationType::InvalidG; 
}
// Resolve container type
ContainerTypes resolveC(string command) {
    static const std::map<std::string, ContainerTypes> optionStrings {
        { "hash", HashTable },
        { "seq", Sequence }
    };

    auto itr = optionStrings.find(command);
    if( itr != optionStrings.end() ) {
        return optionStrings.at(command);
    }
    return ContainerTypes::InvalidC; 
}

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
            // while (base!="exit" && base !="q" && base != "quit") {
            //     cout << "\nengine@localhost > ";
            //     base = getCommand();
            //     Command task = Command(base);

            //     switch (resolveM(task.getLevel(0))) {
            //         case Create:
            //             cout << "Catched create command" << endl;
            //             break;

            //         case Fill:
            //             break;

            //         case Search:
            //             break;

            //         case Delete:
            //             break;

            //         case Test:
            //             break;

            //         default:
            //             if (task.getLevel(0) == "exit" or task.getLevel(0) == "quit" or task.getLevel(0) == "q")
            //             {print("Bye bye");}

            //             else {
            //                 print("Seems that entered command is unknown to me :( ");
            //             }
            //             break;
            //     }
            // }
            print("Select type of container: hash or seq");
            string first = getCommand();
            Command task = Command(first);
            switch(resolveC(task.getLevel(0))) {
                case HashTable:
                    executeHash();
                    break;

                case Sequence:
                    executeSeq();
                    break;

                default:
                    break;
            }
        }

        void executeHash() {
            print("Select type of hash-table: (with collision solving)List or Shift, (without collision solving) basic");
            string second = getCommand();
            Command task = Command(second);
            switch(resolveH(task.getLevel(0))) {
                case shift:
                    break;
                case basic:
                    break;
                case list:
                    break;
                default:
                    break;
            }
        }

        void executeSeq() {
            print("Select type of hash-table: (with collision solving)List or Shift, (without collision solving) basic");
            string second = getCommand();
            Command task = Command(second);
            switch(resolveH(task.getLevel(0))) {
                case shift:
                    break;
                case basic:
                    break;
                case list:
                    break;
                default:
                    break;
            }
        }

        string getCommand(){
            string commandToGet;
            getline(cin,commandToGet);
            if (commandToGet.empty()) {return "unkn";}
            else
            return commandToGet;
        }

        void print(string message) {
            cout << message << endl;
        }
};

#endif
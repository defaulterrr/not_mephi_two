#include <iostream>
#include <vector>
using namespace std;

#ifndef Hasher_H
#define Hasher_H

// string to hash (int) 
// expects mm.dd.yyyy or dd.mm.yyyy
int hashOfDate(string date);

// vector of strings and date to hash (int)

int hashOfStrings(vector<string> strings, int year);

// date(day) + month + name_length to hash (int)

int hashFromDate(int day, int month, int nameLength);

// first letters of name, surname and father's name to hash (int)

int hashFromFullName(string name, string surname, string fathersName);

struct Incorrect_data: public exception {
    const char* what() const throw() {
        return "Incorrect form of data given to hashFunction";
    }
};



#endif
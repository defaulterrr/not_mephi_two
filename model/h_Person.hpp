#ifndef PERSON_H
#define PERSON_H
#include "../protocol/Hashable.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

static void func() {
    std::srand(time(nullptr));
}

/* Declaration */
    static int i = 0;

int ranInt (int max) {
    int ran = std::rand()%(max+2);
    cout << ran << endl;
    return ran;
   };

const vector<string> names = {"John","Joe","Carl","Vito","Alan","Barbara","Robert","Harvey","Mike","Jessica","Rachel","Vicky","Louis","Donna"};
const vector<string> surnames = {"Scaletta","Swift","Zane","Ross","Spectre","Litt","Paulson","Pearson","Hardman","Potter","Granger","Jobs","Voznyak"};
const vector<string> fathersNames = {"Adams","Allan","Amadeus","Anne","Chandler","Forsite","Alysson","Daniel","Dawn","Grace","Joan","Jep"};
const vector<string> emails = 
    {"zuckinator@hotmail.com","drolsky@sbcglobal.net","zeitlin@icloud.com","hamilton@live.com",
    "gtaylor@mac.com","schumer@verizon.net","neuffer@yahoo.ca","cvrcek@sbcglobal.net","boser@gmail.com",
    "dcoppit@verizon.net","hstiles@icloud.com","glenz@me.com","hahsler@yahoo.com","eegsa@comcast.net",
    "bdbrown@sbcglobal.net","matty@outlook.com","alfred@aol.com","brickbat@aol.com","bowmanbs@msn.com",
    "adillon@yahoo.com","ewaters@comcast.net","geekgrl@icloud.com","shang@live.com","symbolic@gmail.com"};

int hashOfStrings(vector<string> strings, int year) {
    auto summ = 0;
    auto stringSumm = [] (string str) {int summ=0,i=0; while (i<str.size()) {summ+=(int)str[i++];} return summ;};

    auto i = 0;
    while (i<strings.size()) {summ+=stringSumm(strings[i++]);}

    return summ*10 + year;
}

class Person: public Hashable {
public:
    Person();
    Person(string name,string surname,string email,int year);
    int hash();
    int hash(int max);
    void print();
    int hashVal = 0;
    bool operator == (const Person &two) {
        if (this->hash() == two.hash()) return true;
        return false;
    }

    bool operator != ( const Person &two) {
        if (this->hash() == two.hash()) return false;
        return true;
    }

    bool operator < ( const Person &two) {
        if (this->hash() < two.hash()) return true;
        return false;
    }

    bool operator > ( const Person &two) {
        if (this->hash() < two.hash()) return false;
        return true;
    }

    bool operator <= ( const Person &two) {
        if (this->hash() <= two.hash()) return true;
        return false;
    }

    bool operator >= ( const Person &two) {
        if (this->hash() <= two.hash()) return false;
        return true;
    }
private:
    string name,surname,email;
    int year;
    
};

/* Implementation */

Person::Person() {
    cout << "Created person" << endl;
    
    // this->name = names[ranInt(name.size()-1)];
    this->name = "asd";
    // this->surname = surnames[ranInt(surnames.size()-1)];
    this->surname = "asdaf";
    // this->email = emails[ranInt(emails.size()-1)];
    this->email = "maskdal";
    cout << " Created names etc" << endl;
    // this->year = ranInt(10000); 
    this->year = ++i; 
    
}

Person::Person(string name,string surname,string email,int year) {
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->year = year;
}

int Person::hash() {
    if (this->hashVal == 0 ) {vector<string> temp = {this->name,this->surname,this->email};
    hashVal = hashOfStrings(temp,this->year);}
    return hashVal;
}

int Person::hash(int max) {
    vector<string> temp = {this->name};
    return hashOfStrings(temp,this->year) % max;
}

void Person::print() {
    cout << this->name << " " << this->surname << endl;
    cout << this->email << " birth: " << this->year << endl;
}

#endif
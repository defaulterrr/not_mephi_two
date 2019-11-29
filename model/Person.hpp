

#ifndef Person_H
#define Person_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

auto ranInt = [] (int max) {return rand()%max+1;};

const vector<string> names = {"John","Joe","Carl","Vito","Alan","Barbara","Robert","Harvey","Mike","Jessica","Rachel","Vicky","Louis","Donna"};
const vector<string> surnames = {"Scaletta","Swift","Zane","Ross","Spectre","Litt","Paulson","Pearson","Hardman","Potter","Granger","Jobs","Voznyak"};
const vector<string> fathersNames = {"Adams","Allan","Amadeus","Anne","Chandler","Forsite","Alysson","Daniel","Dawn","Grace","Joan","Jep"};
const vector<string> emails = 
    {"zuckinator@hotmail.com","drolsky@sbcglobal.net","zeitlin@icloud.com","hamilton@live.com",
    "gtaylor@mac.com","schumer@verizon.net","neuffer@yahoo.ca","cvrcek@sbcglobal.net","boser@gmail.com",
    "dcoppit@verizon.net","hstiles@icloud.com","glenz@me.com","hahsler@yahoo.com","eegsa@comcast.net",
    "bdbrown@sbcglobal.net","matty@outlook.com","alfred@aol.com","brickbat@aol.com","bowmanbs@msn.com",
    "adillon@yahoo.com","ewaters@comcast.net","geekgrl@icloud.com","shang@live.com","symbolic@gmail.com"};

struct Person {
public:
    string name,surname,fathersName,birth,email;

    Person() {
    this->name = names[ranInt(names.size())];
    cout << this->name << endl;
    this->surname = surnames[ranInt(surnames.size())];
    cout << this->surname << endl;
    this->fathersName = fathersNames[ranInt(fathersNames.size())];
    cout << this->fathersName << endl;
    this->email = emails[ranInt(emails.size())];
    cout << this->email << endl;
    this->birth = to_string(ranInt(31))+'.'+to_string(ranInt(12))+'.'+to_string(ranInt(10000));
    cout << this->birth << endl;
    }
    Person(string name,string surname,string fathersName,string birth,string address,string email);
    

    void print();
};


#endif
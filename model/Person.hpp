

#ifndef Person_H
#define Person_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

auto ranInt = [] (int max) {return rand()%max+1;};

struct Person {
    string name,surname,fathersName,birth,email;

    Person();
    Person(string name,string surname,string fathersName,string birth,string address,string email);
    
    const vector<string> names = {"John","Joe","Carl","Vito","Alan","Barbara","Robert","Harvey","Mike","Jessica","Rachel","Vicky","Louis","Donna"};
    const vector<string> surnames = {"Scaletta","Swift","Zane","Ross","Spectre","Litt","Paulson","Pearson","Hardman","Potter","Granger","Jobs","Voznyak"};
    const vector<string> fathersNames = {"Adams","Allan","Amadeus","Anne","Chandler","Forsite","Alysson","Daniel","Dawn","Grace","Joan","Jep"};
    const vector<string> emails = 
        {"zuckinator@hotmail.com","drolsky@sbcglobal.net","zeitlin@icloud.com","hamilton@live.com",
        "gtaylor@mac.com","schumer@verizon.net","neuffer@yahoo.ca","cvrcek@sbcglobal.net","boser@gmail.com",
        "dcoppit@verizon.net","hstiles@icloud.com","glenz@me.com","hahsler@yahoo.com","eegsa@comcast.net",
        "bdbrown@sbcglobal.net","matty@outlook.com","alfred@aol.com","brickbat@aol.com","bowmanbs@msn.com",
        "adillon@yahoo.com","ewaters@comcast.net","geekgrl@icloud.com","shang@live.com","symbolic@gmail.com"};


};


#endif
#include "Hasher.hpp"

int hashOfDate(string date) {
    int summ = 0;
    try {
        if (date.length() != 10) {throw Incorrect_data();}
        if (date[2]!='.' or date[5]!='.') {throw Incorrect_data();}
                        auto stringToSumm = [] (string date, int n, int j) {
                            return stoi(date.substr(n,j));
                        };
        summ += stringToSumm(date,0,2);
        summ += stringToSumm(date,3,2);
        summ += stringToSumm(date,6,2);

    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
    return summ;
}

int hashOfStrings(vector<string> strings, int year) {
    auto summ = 0;
    auto stringSumm = [] (string str) {int summ=0,i=0; while (i<str.size()) {summ+=(int)str[i++];} return summ;};

    auto i = 0;
    while (i<strings.size()) {summ+=stringSumm(strings[i++]);}

    return summ*10 + year;
}

int hashFromDate(int day, int month, int nameLength) {
    return day+10*month+nameLength*100;
}

int hashFromFullName(string name, string surname, string fathersName) {
    auto summ = (int)name[0] + (int)surname[0] + (int)fathersName[0];
    return summ;
}

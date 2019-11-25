#include "Person.hpp"

Person::Person() {
    this->name = names[ranInt(names.size())];
    this->surname = surnames[ranInt(surnames.size())];
    this->fathersName = fathersNames[ranInt(fathersNames.size())];
    this->email = emails[ranInt(emails.size())];
    this->birth = to_string(ranInt(31))+'.'+to_string(ranInt(12))+'.'+to_string(ranInt(10000));
}
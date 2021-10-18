//
//  Person.hpp
//  ContactManagement
//
//  Created by Nathan Dilla on 10/13/21.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Person//stores persons name, address and contact info
{
private:
    int index;
    string firstName;
    string lastName;
    string streetAddress;
    string state;
    string zipCode;
    string phoneNumber;
public:
    Person(string firstName, string lastName, string streetAddress, string state, string zipCode, string phoneNumber);//def constructor
    Person();
    //getters
    int getIndex();
    string getFirstName();
    string getLastName();
    string getFullName();
    string getStreetAddress();
    string getState();
    string getZipCode();
    string getPhoneNumber();
    //setters
    void setFirstName(string);
    void setLastName(string);
    void setFullName(string, string);
    void setStreetAddress(string);
    void setState(string);
    void setZipCode(string);
    void setPhoneNumber(string);
    void display();
};

#endif /* Person_hpp */

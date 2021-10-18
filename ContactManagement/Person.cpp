//
//  Person.cpp
//  ContactManagement
//
//  Created by Nathan Dilla on 10/13/21.
//

#include "Person.hpp"

int Person::numOfContacts = 0;

Person::Person(string fName, string lName, string sAddress, string s, string zCode, string pNum)
{
    firstName = fName;
    lastName = lName;
    streetAddress = sAddress;
    state = s;
    zipCode = zCode;
    phoneNumber = pNum;
    
    numOfContacts++;
}

Person::Person()
{
    firstName = "";
    lastName = "";
    streetAddress = "";
    state = "";
    zipCode = "";
    phoneNumber = "";
}

string Person::getFirstName()
{
    return firstName;
}

string Person::getLastName()
{
    return lastName;
}

string Person::getFullName()
{
    return firstName + " " + lastName;
}

string Person::getStreetAddress()
{
    return streetAddress;
}

string Person::getState()
{
    return state;
}

string Person::getZipCode()
{
    return zipCode;
}

string Person::getPhoneNumber()
{
    return phoneNumber;
}

void Person::setFirstName(string s)
{
    firstName = s;
}

void Person::setLastName(string s)
{
    lastName = s;
}

void Person::setFullName(string f, string l)
{
    firstName = f;
    lastName = l;
}

void Person::setStreetAddress(string s)
{
    streetAddress = s;
}

void Person::setState(string s)
{
    state = s;
}

void Person::setZipCode(string z)
{
    zipCode = z;
}

void Person::setPhoneNumber(string n)
{
    phoneNumber = n;
}

void Person::display()
{
    cout
    << getFullName() << endl
    << getStreetAddress() << endl
    << getState() << endl
    << getZipCode() << endl
    << getPhoneNumber() << endl;
    
    cout << "***********************" << endl;
}


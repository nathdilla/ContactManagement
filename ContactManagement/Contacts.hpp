//
//  Contacts.hpp
//  ContactManagement
//
//  Created by Nathan Dilla on 10/13/21.
//

#ifndef Contacts_hpp
#define Contacts_hpp

#include <stdio.h>
#include <iostream>
#include "Person.hpp"
#include <vector>
#include <fstream>
using namespace std;

class Contacts
{
private:
    vector<Person> contactList;
    int size;
    string fileName;
    bool isLoaded;
public:
    Contacts();
    ~Contacts();
    void saveFile();
    void addFile();
    void newOrLoadMenu();
    void menu();
    void removeByName(string);
    void removeByInt(int);
    int searchByName(string);
    Person searchByNumber(int);
    Person getFile(int);
    void printFile();
    void exportFile();
};

#endif /* Contacts_hpp */

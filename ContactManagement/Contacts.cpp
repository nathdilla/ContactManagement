//
//  Contacts.cpp
//  ContactManagement
//
//  Created by Nathan Dilla on 10/13/21.
//

#include "Contacts.hpp"
#include "Person.hpp"

Contacts::Contacts(){}// default constructor

int Contacts::searchByName(string lname)//function searches through the vector contactList and finds contact by last name
{
    for(int i = 0; i < contactList.size(); i++)
    {
        if (contactList.at(i).getLastName() == lname)
        {
            return i+1;
        }
    }
    return -1;
}

Person Contacts::searchByNumber(int n)// searches through contact list through index number
{
    return contactList.at(n-1);
}

void Contacts::removeByInt(int i) //remove cell from contact list by index
{
    contactList.erase(contactList.begin()+i-1);
}

void Contacts::menu()//code for the menu
{
    string input;
    
    cout << "search - 1" << endl//menu
    << "add - 2"
    << endl
    << "remove - 3"
    << endl
    << "exit = 0"
    << endl;
    
    cout << "***********************" << endl;
    
    cin >> input;
    getchar();
    
    if (input == "1")//search
    {
        cout << "search by num (1) or last name? (2)";
        cin >> input;
        if (input == "1")
        {
            cout<<"index?"<<endl;
            cin>>input;
            searchByNumber(stoi(input)).display();
            menu();
        }
        else if (input == "2")
        {
            cout<<"last name?"<<endl;
            cin>>input;
            int index = searchByName(input);
            if (index != -1)
            {
                searchByNumber(index).display();
                menu();
            }
        }
    }
    else if(input == "2")//add
    {
        addFile();
    }
    else if(input == "3")//remove
    {
        cout<<"index?"<<endl;
        cin>>input;
        removeByInt(stoi(input));
        menu();
    }
}

void Contacts::newOrLoadMenu()//ask user for new file or load
{
    string input;
    
    cout << "create new file (1) or load (2)?" << endl;
    cin >> input;
    
    if(input == "1")
    {
        cout << "file name?" << endl;
        cin >> input;
        fileName = input;
        isLoaded = false;
    }
    else if (input == "2")
    {
        cout << "file name?" << endl;
        cin >> input;
        fileName = input;
        isLoaded = true;
        ifstream newFile;
        string line;
        newFile.open(fileName+".txt");
        int i = 1;
        
        string firstName;
        string lastName;
        string streetAddress;
        string state;
        string zipCode;
        string phoneNumber;
        
        while (std::getline(newFile, line))
        {
            if (i == 1)
            {
                firstName = line;
            }
            else if (i == 2)
            {
                lastName = line;
            }
            else if (i == 3)
            {
                streetAddress = line;
            }
            else if (i == 4)
            {
                state = line;
            }
            else if (i == 5)
            {
                zipCode = line;
            }
            else if (i == 6)
            {
                phoneNumber = line;
                Person newPerson(firstName,lastName,streetAddress,state,zipCode,phoneNumber);
                contactList.push_back(newPerson);
            }
            i++;
            if(i==7)
            {
                i=1;
            }
        }
    }
    menu();
}

void Contacts::addFile()
{
    Person newFile;
    string input;
    cout << "first name?" << endl;//ask first name
    getline(cin, input);
    newFile.setFirstName(input);
    
    cout << "last name?" << endl;//ask last name
    getline(cin, input);
    newFile.setLastName(input);
    
    cout << "street address?" << endl;//ask street address
    getline(cin, input);
    newFile.setStreetAddress(input);
    
    cout << "state?" << endl;//ask state
    getline(cin, input);
    newFile.setState(input);
    
    cout << "zip?" << endl;//ask zip
    getline(cin, input);
    newFile.setZipCode(input);
    
    cout << "phone number?" << endl;//ask phone
    getline(cin, input);
    newFile.setPhoneNumber(input);
    
    cout << "***********************" << endl;
    
    contactList.push_back(newFile);
    
    newFile.display();
    
    menu();
}

void Contacts::saveFile()
{
    cout << "test";
    ofstream newFile(fileName+".txt");
    for(int i = 0; i < contactList.size(); i++)
    {
        Person target = contactList.at(i);
        
        newFile
        << target.getFirstName() << endl
        << target.getLastName() << endl
        << target.getStreetAddress() << endl
        << target.getState() << endl
        << target.getZipCode() << endl
        << target.getPhoneNumber() << endl;

        cout << "WRITING...." << endl
        << target.getFullName() << endl
        << target.getStreetAddress() << endl
        << target.getState() << endl
        << target.getZipCode() << endl
        << target.getPhoneNumber() << endl;

        cout << "***********************" << endl;
    }
    newFile.close();
}

Contacts::~Contacts()
{
    saveFile();
}

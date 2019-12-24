//
//  Family.cpp
//  9.23-HW1
//
//  Created by 김하진 on 19.9. 23.
//  Copyright © 2019 김하진. All rights reserved.
//

/*
 Condition 3:
 The Family class has two member variables, "string fname" (family name)
 and "vector <Person> personList".

 Condition 4:
 Constructors, mutators, and accessor functions
 for Person and Family classes can be freely implemented as needed.
 */
#include "Family.h"
#include <iostream>

// Constructors
Family::Family() //:fname("")
{
    fname = "";
}

Family::Family(std::string fn) //:fname(fn)
{
    fname = fn;
}

Family::Family(std::string fn, std::vector<Person> pl)
{
    fname = fn;
    personList = pl;
}

// Accessors
std::string Family::GetFname() const
{
    return fname;
}

std::vector<Person> Family::GetPersonList() const
{
    return personList;
}

int Family::PersonIndex(std::string name) const
{
    for (int i = 0; i < personList.size(); ++i) {
        if (personList[i].GetName() == name) {
            return i;
        }
    }
    
    // Name doesn't exist
    return -1;
}

int Family::PrintFamily() const
{
    std::cout << "[FAMILY] " << fname << '\n';
    
    for(int i = 0; i < personList.size(); i++) {
        std::cout << "  [PERSON] ";
        personList[i].PrintPerson();
    }
    
    return 0;
}

// Mutators
std::string Family::SetFname(std::string fname_getter)
{
    fname = fname_getter;
    
    return fname;
}

std::vector<Person> Family::SetPersonList(std::vector<Person> personList_getter)
{
    personList = personList_getter;
    
    return personList;
}

std::vector<Person> Family::PushPerson(Person person_getter)
{
    personList.push_back(person_getter);
    
    return personList;
}

std::vector<Person> Family::DeletePerson(std::string name)
{
    std::vector<Person> newList;
    
    for (int i = 0; i < PersonIndex(name); ++i) {
        newList.push_back(personList[i]);
    }
    
    for (int i = PersonIndex(name) + 1; i < personList.size(); ++i) {
        newList.push_back(personList[i]);
    }
    
    personList = newList;
    
    return personList;
}

//
//  Family.hpp
//  9.23-HW1
//
//  Created by 김하진 on 19.9. 23.
//  Copyright © 2019 김하진. All rights reserved.
//

#ifndef Family_h
#define Family_h

#include "Person.h"

#include <iostream>
#include <vector>

class Family {
private:
    std::string fname;
    std::vector<Person> personList;
    
public:
    // Constructors
    Family();
    Family(std::string);
    Family(std::string, std::vector<Person>);
    
    // Accessors
    std::string GetFname() const;
    std::vector<Person> GetPersonList() const;
    
    int PersonIndex(std::string) const;
    int PrintFamily() const;
    
    // Mutators
    std::string SetFname(std::string);
    std::vector<Person> SetPersonList(std::vector<Person>);
    
    std::vector<Person> PushPerson(Person);
    std::vector<Person> DeletePerson(std::string);
};

#endif /* Family_hpp */

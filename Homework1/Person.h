//
//  Person.hpp
//  9.23-HW1
//
//  Created by 김하진 on 19.9. 23.
//  Copyright © 2019 김하진. All rights reserved.
//

#ifndef Person_h
#define Person_h

#include <iostream>

enum Gender { NONE, MALE, FEMALE };

class Person {
private:
    std::string name;
    int age;
    Gender gen;
    
public:
    // Constructors
    Person();
    Person(std::string, int, Gender);
    Person(std::string, int, char);
    
    // Accessors
    std::string GetName() const;
    int GetAge() const;
    Gender GetGen() const;
    
    int PrintPerson() const;
    
    // Mutators
    std::string SetName(std::string);
    int SetAge(int);
    Gender SetGen(Gender);
};

#endif /* Person_hpp */

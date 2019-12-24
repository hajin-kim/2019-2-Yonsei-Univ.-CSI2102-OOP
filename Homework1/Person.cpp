//
//  Person.cpp
//  9.23-HW1
//
//  Created by 김하진 on 19.9. 23.
//  Copyright © 2019 김하진. All rights reserved.
//

/*
 Condition 2:
 The Person class has three member variables:
 "string name, int age, and Gender gen".
 Gender is of the enumeration type: “enum Gender { NONE, MALE, FEMALE};

 Condition 4:
 Constructors, mutators, and accessor functions
 for Person and Family classes
 can be freely implemented as needed.
 */
#include "Person.h"
#include <iostream>

// Constructors
Person::Person() //:name(""), age(0), gen(NONE)
{
    name = "";
    age = 0;
    gen = NONE;
}

Person::Person(std::string n, int a, Gender g) //:name(n), age(a), gen(g)
{
    name = n;
    age = a;
    gen = g;
}

Person::Person(std::string n, int a, char gen_char) //:name(n), age(a)
{
    name = n;
    age = a;
    
    if (gen_char == 'M') {
        gen = MALE;
    }
    else if (gen_char == 'F') {
        gen = FEMALE;
    }
    else {
        gen = NONE;
    }
}

// Accessors
std::string Person::GetName() const
{
    return name;
}

int Person::GetAge() const
{
    return age;
}

Gender Person::GetGen() const
{
    return gen;
}

int Person::PrintPerson() const
{
    char gen_char = '0';
    
    if (gen == MALE) {
        gen_char = 'M';
    }
    else if (gen == FEMALE) {
        gen_char = 'F';
    }
    
    std::cout << name << ' ' << age << ' ' << gen_char << std::endl;
    
    return 0;
}

// Mutators
std::string Person::SetName(std::string name_getter)
{
    name = name_getter;
    return name;
}

int Person::SetAge(int age_getter)
{
    age = age_getter;
    return age;
}

Gender Person::SetGen(Gender gen_getter)
{
    gen = gen_getter;
    return gen;
}

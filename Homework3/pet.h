//
//  pet.h
//  11.16 HW3
//
//  Created by 김하진 on 19.11. 18.
//  Copyright © 2019 김하진. All rights reserved.
//

#ifndef pet_h
#define pet_h

#include <iostream>
#include <string>
using namespace std;

/*
 condition ①
 The program has five classes: Pet, Tetrapod, Dog, Cat, and Bird
 
 condition ③
 Hierarchy: Pet and Tetrapod are abstract classes,
 Tetrapod is the derived class of Pet,
 Dog and Cat is derived from Tetrapod,
 Bird is derived from Pet
 
 condition ④
 All above five classes are implemented in pet.h and pet.cpp
 */

/// Pet
class Pet {
protected:
    string type;
    string name;
    int age;
    string color;
    
public:
    Pet(string _name, int _age, string _color);
    
    string getType() const { return type; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getColor() const { return color; }
    
    virtual string info() const;
    void move() const;
};

/// Tetrapod
class Tetrapod: public Pet {
protected:
    double legLength;
    
public:
    Tetrapod(string _name, int _age, string _color, double _legLength);
    string info() const override;
    void move() const;
};

/// Cat
class Cat: public Tetrapod {
    string hair;
    
public:
    Cat(string _name, int _age, string _color, double _legLength, string _hair);
    string info() const final;
    void move() const;
};

/// Dog
class Dog: public Tetrapod {
    string role;
    
public:
    Dog(string _name, int _age, string _color, double _legLength, string _role);
    string info() const final;
    void move() const;
};

/// Bird
class Bird: public Pet {
    int eggSize;
    
public:
    Bird(string _name, int _age, string _color, int _eggSize);
    string info() const final;
    void move() const;
};

#endif /* pet_h */

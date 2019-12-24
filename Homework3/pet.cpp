//
//  pet.cpp
//  11.16 HW3
//
//  Created by 김하진 on 19.11. 18.
//  Copyright © 2019 김하진. All rights reserved.
//

#include "pet.h"

// Pet
Pet::Pet(string _name, int _age, string _color)
:name(_name), age(_age), color(_color){
    type = "PET";
}


string Pet::info() const {
    return type + ": name(" + name + ") age(" + to_string(age) + ") color(" + color + ")";
}


void Pet::move() const {
}


// Tetrapod
Tetrapod::Tetrapod(string _name, int _age, string _color, double _legLength)
:Pet(_name, _age, _color), legLength(_legLength){
    type = "TETRAPOD";
}


string Tetrapod::info() const {
    return Pet::info() + " legLength(" + to_string(legLength) + ")";
}


void Tetrapod::move() const {
}


// Cat
Cat::Cat(string _name, int _age, string _color, double _legLength, string _hair)
:Tetrapod(_name, _age, _color, _legLength), hair(_hair){
    type = "CAT";
}


string Cat::info() const {
    return Tetrapod::info() + " hair(" + hair + ")";
}

void Cat::move() const {
    cout << "cat move" << endl;
}


// Dog
Dog::Dog(string _name, int _age, string _color, double _legLength, string _role)
:Tetrapod(_name, _age, _color, _legLength), role(_role) {
    type = "DOG";
}


string Dog::info() const {
    return Tetrapod::info() + " role(" + role + ")";
}


void Dog::move() const { 
    cout << "dog move" << endl;
}


// Bird
Bird::Bird(string _name, int _age, string _color, int _eggSize)
:Pet(_name, _age, _color), eggSize(_eggSize){
    type = "BIRD";
}


string Bird::info() const {
    return Pet::info() + " eggSize(" + to_string(eggSize) + ")";
}


void Bird::move() const { 
    cout << "bird fly" << endl;
}


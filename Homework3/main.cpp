//
//  main.cpp
//  11.16 HW3
//
//  Created by 김하진 on 19.11. 18.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

/*
 condition ②
 The project has main.cpp, pet.h, pet.cpp files
 
 condition ⑧
 You can freely implement all other things like member functions and member variables
 
 condition ①, ③, ④: in pet.h
 */
#include "pet.h"
using namespace std;

// your code here

/*
 condition ⑤
 Intro() and move() are the global functions in the main.cpp
 */
void move(vector<Pet*> p);
void intro(Pet* p);

int main()
{
    vector<Pet*> petVec;
    petVec.push_back(new Bird("Poi", 5, "yellow", 7));
    petVec.push_back(new Cat("Tom", 2, "black", 12.5, "long"));
    petVec.push_back(new Dog("Happy", 7, "white", 15.2, "short"));
    
    for (int i = 0; i < petVec.size(); i++) {
        cout << petVec[i]->info() << endl;
    }
    
    move(petVec);
    
    for (int i = 0; i < petVec.size(); i++) {
        intro(petVec[i]);
    }
}

/*
 condition ⑦
 You must use dynamic_cast in move() function
 */
void move(vector<Pet*> petVec) {
    for (int i = 0; i < petVec.size(); ++i) {
        if (petVec[i]->getType() == "BIRD") {
            dynamic_cast<Bird*>(petVec[i])->move();
        }
        else if (petVec[i]->getType() == "CAT") {
            dynamic_cast<Cat*>(petVec[i])->move();
        }
        else if (petVec[i]->getType() == "DOG") {
            dynamic_cast<Dog*>(petVec[i])->move();
        }
    }
}

/*
 condition ⑥
 You must not use dynamic_cast or static_cast in intro() function
 */
void intro(Pet* pet_ptr) {
    cout << pet_ptr->getName() << " is " << pet_ptr->getAge() << " years old, its color is " << pet_ptr->getColor() << endl;
}


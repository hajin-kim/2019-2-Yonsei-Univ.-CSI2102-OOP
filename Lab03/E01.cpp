//
//  E01.cpp
//  9.17-3-P
//
//  Created by 김하진 on 19.9. 17.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

class Person {
private:
    std::string name;
    int age;
    
public:
    Person(){
        name = "";
        age = 0;
    }
    Person(std::string name, int age){
        std::cin >> name >> age;
    }
    
    // Compares p1 age and p2 age, and return true if same,
    bool is_same_age(Person other) const{
        if(age == other.get_age())
            return true;
        else
            return false;
    }
    bool is_older(Person other) const{
        if(age > other.get_age())
            return true;
        else
            return false;
    }
    
    // From user, gets name by keyboard
    void set_name(){
        std::string temp;
        std::cin >> temp;
        name = temp;
    }
    void set_age(){
        int temp;
        std::cin >> temp;
        age = temp;
    }
    
    // Returns name
    std::string get_name() const{
        return name;
    }
    int get_age() const{
        return age;
    }
};

int E01()
{
    Person p1, p2;
    
    p1.set_name();
    p1.set_age();
    p2.set_name();
    p2.set_age();
    
    if(p1.is_same_age(p2))
        std::cout << p1.get_name() + ' ' + p2.get_name();
    else if(p1.is_older(p2))
        std::cout << p1.get_name();
    else
        std::cout << p2.get_name();
    
    return 0;
}

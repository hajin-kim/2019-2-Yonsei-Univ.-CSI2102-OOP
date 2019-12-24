//
//  main.cpp
//  10.15 2-P
//
//  Created by 김하진 on 19.10. 15.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <vector>

class Person {
private:
    std::string name;
    int age;
    
public:
    Person();
    Person(std::string name, int age):name(name), age(age){};
    std::string getName() { return name; }
    int getAge() { return age; }
    virtual void print()
    {
        std::cout << "[PERSON] " << name << ' ' << age;
    }
};

class Student: public Person {
private:
    std::string major;
    
public:
    Student();
    Student(std::string name, int age, std::string major):Person(name, age){ this->major = major; };
    std::string getMajor() { return major; }
    void print()
    {
        std::cout << "[STUDENT] " << this->getName() << ' ' << this->getAge() << ' ' << major;
    }
};

int main() {
    // 여기서 4명을 위한 vector인 people을 declare하고 data를 채운다.
    std::vector<Person*> people(4);
    
    people[0] = new Person("Tom", 25);
    people[1] = new Student("Jane", 19, "Computer");
    people[2] = new Student("Brown", 22, "Management");
    people[3] = new Person("Micky", 27);
    
    for (int i = 0; i < 4; i++) {
        people[i]->print();
        std::cout << std::endl;
    }
    
    return 0;
}

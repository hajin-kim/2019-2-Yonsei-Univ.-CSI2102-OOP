//
//  E03.cpp
//  10.1 1-P
//
//  Created by 김하진 on 19.10. 1.
//  Copyright © 2019 김하진. All rights reserved.
//

#ifndef myE03
#define myE03

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Person;  // Person definition이 뒤에 나오므로, 미리 이 줄만 써줌

const string PERSONNAME[3] = {"Tom", "Jane", "Mary"};
const string CARNAME[3] = {"BMW", "Ford", "Kia"};

// class Car의 definition은 다음과 같다:
class Car
{
public:
    Car();
    Car(string name);
    void setName(string name);
    void setOwner(Person *p);   //owner를 하나 추가
    string getName() const;
    vector<Person*> getOwner() const;
private:
    string name;
    vector<Person*> owner;
};

Car::Car()
{
    name = "";
}

Car::Car(string name)
{
    this->name = name;
}

void Car::setName(string name)
{
    this->name = name;
}

void Car::setOwner(Person* p)
{
    this->owner.push_back(p);
}

string Car::getName() const
{
    return name;
}

vector<Person*> Car::getOwner() const
{
    return owner;
}

// class Person의 definition은 다음과 같다:
class Person
{
public:
    Person();
    Person(string name);
    void setName(string name);
    void setCar(Car *c);   // car를 하나 추가
    string getName() const;
    vector<Car*> getCar() const;
private:
    string name;
    vector<Car*> car;
    friend std::ostream& operator<<(std::ostream& newout, Person target)
    {
        newout << target.name;
        
        for (int i = 0; i < target.car.size(); ++i) {
            newout << ' ' << target.car[i]->getName();
        }
        
        return newout << " \n";
    }
};

Person::Person()
{
    name = "";
}

Person::Person(string name)
{
    this->name = name;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setCar(Car* c)
{
    this->car.push_back(c);
}

string Person::getName() const
{
    return name;
}

vector<Car*> Person::getCar() const
{
    return car;
}

// 두개의 global function들이 다음과 같다:

// 주어진 name을 가지는 person을 Person*의 vector p에서 찾아
// 그 pointer를 return
Person *findPerson(const vector<Person*>& p, string name);

// 주어진 name을 가지는 car를 Car*의 vector c에서 찾아
// 그 pointer를 return
Car *findCar(const vector<Car*>& c, string name);

// main function의 뼈대는 다음과 같다.
int E03_overloading()
{
    vector<Person*> person(3);
    vector<Car*> car(3);

    // 여기서 3명의 person (Tom, Jane, Mary)의 dynamic memory를  allocate한다. (new 이용)
    for (int i = 0; i < 3; ++i) {
        person[i] = new Person(PERSONNAME[i]);
        car[i] = new Car(CARNAME[i]);
    }
    
    string name_getter, car_getter;
    
    std::cin >> name_getter;
    
    while(name_getter != "0") {  // 0이 들어올 때까지 입력을 받는다.
         // person과 car 이름을 입력받는다.
        std::cin >> car_getter;
        
        // findPerson과 findCar를 이용하여 person과 car를 찾는다.
        Person* person_target = findPerson(person, name_getter);
        Car* car_target = findCar(car, car_getter);
        
        // person에 car를 추가 (setCar이용)
        person_target->setCar(car_target);
        
        // car에 person을 추가 (setOwner 이용)
        car_target->setOwner(person_target);
        
        std::cin >> name_getter;
    }

    // 각 person의 car들을 print한다.
    for (int i = 0; i < 3; ++i) {
        std::cout << *person[i];
    }
    
    // 각 car의 owner들을 print한다.
    for (int i = 0; i < 3; ++i) {
        std::cout << car[i]->getName();
        for (int j = 0; j < car[i]->getOwner().size(); ++j) {
            std::cout << ' ' << car[i]->getOwner()[j]->getName();
        }
        std::cout << ' ' << std::endl;
    }
    
    for (int i = 0; i < 3; ++i) {
        delete person[i];
        delete car[i];
    }
    
    return 0;
}

Person* findPerson(const vector<Person*>& p, string name)
{
    for (int i = 0; i < 3; ++i) {
        if (p[i]->getName() == name) {
            return p[i];
        }
    }
    return NULL;
}

Car* findCar(const vector<Car*>& c, string name)
{
    for (int i = 0; i < 3; ++i) {
        if (c[i]->getName() == name) {
            return c[i];
        }
    }
    return NULL;
}

#endif

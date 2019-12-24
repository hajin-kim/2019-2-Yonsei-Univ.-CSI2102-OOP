//
//  P01.cpp
//  11.19 1-P
//
//  Created by 김하진 on 19.11. 19.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

using namespace std;

/// Movable
class Movable {
protected:
    string type;
    
    int x, y;
    string obj_sound;
    
    Movable();
    Movable(string _type, int _x, int _y, string _obj_sound);
public:
    string getType() const;
    virtual void print() const = 0;
    string sound() const;
};

Movable::Movable() {
    type = "Movable";
    x = y = 0;
    obj_sound = "";
}

Movable::Movable(string _type, int _x, int _y, std::string _obj_sound) {
    type = _type;
    x = _x;
    y = _y;
    obj_sound = _obj_sound;
}

string Movable::getType() const {
    return type;
}

void Movable::print() const {
    cout << type << " at (" << x << ',' << y << ")";
}

std::string Movable::sound() const {
    return obj_sound;
}


/// Car
class Car: public Movable {
    string color;
    
public:
    Car(int _x, int _y, string _color);
    void print() const final;
    void carGo() const;
};

Car::Car(int _x, int _y, std::string _color):Movable("Car", _x, _y, "woong") {
    color = _color;
}

void Car::print() const {
    Movable::print();
    cout << " color (" << color << ')' << endl;
}

void Car::carGo() const {
    cout << "car go" << endl;
}


/// Bycicle
class Bicycle: public Movable {
    int age;
    
public:
    Bicycle(int _x, int _y, int _age);
    void print() const final;
    void bycicleGo() const;
};

Bicycle::Bicycle(int _x, int _y, int _age):Movable("Bicycle", _x, _y, "keek") {
    age = _age;
}

void Bicycle::print() const {
    Movable::print();
    cout << " age (" << age << ')' << endl;
}

void Bicycle::bycicleGo() const {
    cout << "bicycle go" << endl;
}


// global functions
void go(Movable* m) {
    if (m->getType() == "Car") {
        static_cast<Car*>(m)->carGo();
    }
    else if (m->getType() == "Bicycle") {
        static_cast<Bicycle*>(m)->bycicleGo();
    }
}


// main
int P01() {
    Movable* m;
    Car* c = new Car(3, 5, "yellow");
    Bicycle* b = new Bicycle(2, 10, 3);
    
    m = c;
    m->print();
    cout << m->sound() << endl;
    go(m);
    
    m = b;
    m->print();
    cout << m->sound() << endl;
    go(m);
    
    return 0;
}

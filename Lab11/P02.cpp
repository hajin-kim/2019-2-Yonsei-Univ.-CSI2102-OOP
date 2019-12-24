//
//  P02.cpp
//  11.19 1-P
//
//  Created by 김하진 on 19.11. 19.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/// Musician
class Musician {
protected:
    string name;
    int age;
    
public:
    Musician() { name = ""; age = 0;}
    Musician(string _name, int _age);
    virtual void play() const = 0;
};

Musician::Musician(string _name, int _age) {
    name = _name;
    age = _age;
}


/// Instrument Player
class InstrumentPlayer: public Musician {
protected:
    string instrument;
    int career;;
    
public:
    InstrumentPlayer(string _name, int _age, string _instrument, int _career);
    void play() const override = 0;
};

InstrumentPlayer::InstrumentPlayer(string _name, int _age, string _instrument, int _career)
:Musician(_name, _age){
    instrument = _instrument;
    career = _career;
}


/// Pianist
class Pianist: public InstrumentPlayer {
    
    
public:
    Pianist(string _name, int _age, string _instrument, int _career);
    void play() const final;
};

Pianist::Pianist(string _name, int _age, string _instrument, int _career)
:InstrumentPlayer(_name, _age, _instrument, _career) {}

void Pianist::play() const {
    cout << "Pianist " << name << '(' << age << ") plays " << instrument << " with career " << career << " years" << endl;
}


/// Guitarist
class Guitarist: public InstrumentPlayer {
    
    
public:
    Guitarist(string _name, int _age, string _instrument, int _career);
    void play() const final;
};

Guitarist::Guitarist(string _name, int _age, string _instrument, int _career)
:InstrumentPlayer(_name, _age, _instrument, _career) {}

void Guitarist::play() const {
    cout << "Guitarist " << name << '(' << age << ") plays " << instrument << " with career " << career << " years" << endl;
}


/// Vocalist
class Vocalist: public Musician {
    string part;
    
public:
    Vocalist(string _name, int _age, string _part);
    void play() const final;
};

Vocalist::Vocalist(string _name, int _age, string _part)
:Musician(_name, _age) {
    part = _part;
}

void Vocalist::play() const {
    cout << "Vocalist " << name << '(' << age << ") plays part " << part << endl;
}

// global functions
void playAll(vector<Musician*> v) {
    
    for (int i = 0; i < v.size(); i++) {
        v[i]->play();
    }
}


// main
int P02() {
    
    vector<Musician*> v;
    Musician* m = new Vocalist("Tom", 35, "Tenor");
    v.push_back(m);
    m = new Pianist("Jane", 28, "Yamaha Grand", 22);
    v.push_back(m);
    m = new Guitarist("Brown", 41, "Gibson", 17);
    v.push_back(m);
    m = new Guitarist("Naomi", 29, "Fender", 19);
    v.push_back(m);
    m = new Vocalist("Kim", 24, "Soprano");
    v.push_back(m);
    
    playAll(v);
    
    return 0;
}

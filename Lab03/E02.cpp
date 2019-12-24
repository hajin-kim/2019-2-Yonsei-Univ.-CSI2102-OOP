//
//  E02.cpp
//  9.17-3-P
//
//  Created by 김하진 on 19.9. 17.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

class Subject {
private:
    std::string name;
    double perfect;   // 만점
public:
    Subject(){
        name = "";
        perfect = 0;
    }
    Subject(std::string n, double p){
        name = n;
        perfect = p;
    }
    
    void set_name(std::string temp){
        name = temp;
    }
    
    void set_perfect(double temp){
        perfect = temp;
    }
    
    std::string get_name(std::string & str_name_getter) const{
        str_name_getter = name;
        return name;
    }
    std::string get_name() const{
        return name;
    }
    
    double get_perfect(double & double_perfect_getter) const{
        double_perfect_getter = perfect;
        return perfect;
    }
    double get_perfect() const{
        return perfect;
    }
    
    double percent(double score) const;
};

double Subject::percent(double score) const
{
    return score / perfect * 100;
}

class Student {
private:
    std::string name;
    Subject subject1, subject2;
    double score1, score2;
public:
    Student(){
        name = "";
        subject1 = Subject();
        subject2 = Subject();
        score1 = 0;
        score2 = 0;
    }
    Student(std::string name_getter, Subject subject1_getter, Subject subject2_getter){
        name = name_getter;
        subject1 = subject1_getter;
        subject2 = subject2_getter;
        score1 = 0;
        score2 = 0;
    }
    
    void set_name(std::string temp){
        name = temp;
    }
    
    void set_subject1(Subject temp){
        subject1 = temp;
    }
    
    void set_subject2(Subject temp){
        subject2 = temp;
    }
    
    void set_score1(double temp){
        score1 = temp;
    }
    
    void set_score2(double temp){
        score2 = temp;
    }
    
    std::string get_name() const{
        return name;
    }
    std::string get_name(std::string & temp) const{
        temp = name;
        return name;
    }
    
    Subject get_subject1() const{
        return subject1;
    }
    Subject get_subject1(Subject & temp) const{
        temp = subject1;
        return subject1;
    }
    
    Subject get_subject2() const{
        return subject2;
    }
    Subject get_subject2(Subject & temp) const{
        temp = subject2;
        return subject2;
    }
    
    double get_score1() const{
        return score1;
    }
    double get_score1(double & temp) const{
        temp = score1;
        return score1;
    }
    
    double get_score2() const{
        return score2;
    }
    double get_score2(double & temp) const{
        temp = score2;
        return score2;
    }
    
    double average() const;
};

double Student::average() const{
    return (subject1.percent(score1) + subject2.percent(score2)) / 2;
}

Subject subjectFromName(Subject sub1, Subject sub2, Subject sub3, std::string name)
{
    if(sub1.get_name() == name)
        return sub1;
    
    if(sub2.get_name() == name)
        return sub2;
    
    if(sub3.get_name() == name)
        return sub3;
    
    return Subject();
}

int E02()
{
    const Subject ENGL("English", 250);
    const Subject MATH("Math", 320);
    const Subject PHYS("Physics", 150);
    
    Student user;
    
    std::string n;
    double d;
    
    std::cin >> n;
    user.set_name(n);
    
    std::cin >> n;
    user.set_subject1(subjectFromName(ENGL, MATH, PHYS, n));
    
    std::cin >> d;
    user.set_score1(d);
    
    std::cin >> n;
    user.set_subject2(subjectFromName(ENGL, MATH, PHYS, n));
    
    std::cin >> d;
    user.set_score2(d);
    
    std::cout << user.average();
    
    return 0;
}

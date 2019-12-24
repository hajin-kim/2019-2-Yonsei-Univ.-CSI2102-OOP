//
//  P05.cpp
//  11.05 1-P
//
//  Created by 김하진 on 19.11. 5.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
using std::cout;
using std::string;
using std::endl;

template<typename A, typename B>
class MyPair {
private:
    A x;
    B y;
public:
    MyPair(A _x, B _y):x(_x), y(_y){};
    A getFirst() {
        return x;
    }
    B getSecond() {
        return y;
    }
};

template<typename A, typename B>
MyPair<A, B> myMax(MyPair<A, B> p1, MyPair<A, B> p2, bool target) {
    if (target == true) {
        return (p1.getFirst() > p2.getFirst())? p1: p2;
    }
    
    return (p1.getSecond() > p2.getSecond())? p1: p2;
}

template<typename A, typename B>
bool CompareByFirst() {
    return true;
}

template<typename A, typename B>
bool CompareBySecond() {
    return false;
}

int P05() {
    
    MyPair<int,int> p1(3,5), p2(1,7);
    MyPair<int,int> p3 = myMax(p1, p2, CompareByFirst<int,int>());
    MyPair<int,int> p4 = myMax(p1, p2, CompareBySecond<int,int>());
    
    cout << p3.getFirst() << " " << p3.getSecond() << endl;
    cout << p4.getFirst() << " " << p4.getSecond() << endl;
    
    MyPair<string,int> p5("abc",4), p6("bcd",3);
    MyPair<string,int> p7 = myMax(p5, p6, CompareByFirst<string,int>());
    MyPair<string,int> p8 = myMax(p5, p6, CompareBySecond<string,int>());
    
    cout << p7.getFirst() << " " << p7.getSecond() << endl;
    cout << p8.getFirst() << " " << p8.getSecond() << endl;
    
    return 0;
}

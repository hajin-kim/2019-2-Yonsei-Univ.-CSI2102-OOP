//
//  P04.cpp
//  11.05 1-P
//
//  Created by 김하진 on 19.11. 5.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
using std::string;

template<typename A, typename B, int sizeA, int sizeB>
class MyClass2 {
private:
    A x[sizeA];
    B y[sizeB];
    
public:
    MyClass2<A, B, sizeA, sizeB> (A _x[], B _y[]) {
        for (int i = 0; i < sizeA; ++i) {
            x[i] = _x[i];
        }
        for (int i = 0; i < sizeB; ++i) {
            y[i] = _y[i];
        }
    };
    void print() {
        for (int i = 0; i < sizeA; ++i) {
            std::cout << x[i] << ' ';
        }
        for (int i = 0; i < sizeB; ++i) {
            std::cout << y[i] << ' ';
        }
    }
};

int P04() {
    
    int a[] = {1, 2, 3, 4, 5};
    string b[] = {"ABC", "DEF", "GHI"};
    
    MyClass2<int,string, 5, 3> x(a, b);
    x.print();
    
    return 0;
}

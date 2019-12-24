//
//  P02.cpp
//  11.05 1-P
//
//  Created by 김하진 on 19.11. 5.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

class Test {
private:
    int x, y;
    
public:
    Test(int _x, int _y):x(_x), y(_y){};
    void print() {
        cout << x << ' ' << y;
    }
};

template <typename Data>
void mySwap(Data& x, Data& y) {
    Data temp = x;
    x = y;
    y = temp;
}

int P02() {
    
    int a = 1, b = 2;
    double c = 3.0, d = 4.0;
    Test e(5, 6), f(7, 8);
    
    mySwap(a, b);
    mySwap(c, d);
    mySwap(e, f);
    cout << a << " " << b << " " << c << " " << d;
    cout << endl;
    e.print();
    cout << " ";
    f.print();
    
    return 0;
}

//
//  P06.cpp
//  11.05 1-P
//
//  Created by 김하진 on 19.11. 5.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;

class MyClass {
private:
    static int cnt;
    
public:
    MyClass() {++cnt;}
    static int getCount() {return cnt;}
};

int MyClass::cnt = 0;

int P06() {
    
    int n;
    MyClass *m;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        m = new MyClass();
    }
    
    cout << m->getCount();
    
    return 0;
}

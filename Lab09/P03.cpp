//
//  P03.cpp
//  11.05 1-P
//
//  Created by 김하진 on 19.11. 5.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

using std::string;
using std::cout;

template <typename Data>
class MyClass {
    Data x;
    
public:
    MyClass<Data>(Data _x):x(_x){};
    Data getData() {
        return x;
    }
    void setData(Data _x) {
        x = _x;
    }
};

int P03() {
    int x = 3;
    int y = 5;
    string s1 = "KOREA";
    string s2 = "USA";
    
    MyClass<int> a(x);
    MyClass<string> str(s1);
    
    cout << a.getData();
    cout << " " << str.getData();
    
    a.setData(y);
    str.setData(s2);
    
    cout << " " << a.getData();
    cout << " " << str.getData();
    
    return 0;
}

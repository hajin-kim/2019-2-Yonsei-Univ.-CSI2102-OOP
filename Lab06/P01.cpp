//
//  P01.cpp
//  10.08-1-P
//
//  Created by 김하진 on 19.10. 8.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

class Test
{
public:
    
    Test() {
        n = 0;
        data = NULL;
    }

   // Test(int n) constructor here
    Test(int n) {
        this->n = n;
        data = new int[n];
    }
   // Test(const Test& other) constructor here
    Test(const Test& other) {
        this->n = other.n;
        data = other.data;
    }
   // setData function here
    void setData(int size, int value) {
        if (n == 0 && size == 0) {
            data = new int[1];
            data[++n] = value;
        }
        else if (n > size) {
            data[size] = value;
        }
        else {
            int* newdata = new int[n];
            for (int i = 0; i < n; ++i) {
                newdata[i] = data[i];
            }
            delete[] data;
            data = new int[n+1];
            for (int i = 0; i < n; ++i) {
                data[i] = newdata[i];
            }
            data[++n] = value;
        }
    }
        
    void print() const {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
    }
    
private:
    int n;
    int *data;
};

int P01() {
    
    Test t1(3);
    t1.setData(0, 2);
    t1.setData(1, 4);
    t1.setData(2, 6);
    
    t1.print();
    cout << endl;
    
    Test t2(t1);     // using copy constructor
    t2.print();
    
    t1.setData(0, 1);
    t1.setData(1, 3);
    t1.setData(2, 5);
    
    cout << endl;
    t1.print();
    cout << endl;
    t2.print();
    
    return 0;
}

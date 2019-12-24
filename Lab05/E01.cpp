//
//  E01.cpp
//  10.1 1-P
//
//  Created by 김하진 on 19.10. 1.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int E01()
{
    // 1
    int x[5]  = {1, 2, 3, 4, 5};
    
    // 2
    for (int i = 0; i < 5; ++i) {
        std::cout << x[i] << ' ';
    }
    std::cout << '\n';
    
    // 3
    int* y[5];
    
    // 4 and 5
    for (int i = 0; i < 5; ++i) {
        y[i] = &x[i];
        std::cout << *y[i] << ' ';
    }
    std::cout << '\n';
    
    // 6 and 7
    for (int i = 0; i < 5; ++i) {
        y[i] = &x[4-i];
        std::cout << *y[i] << ' ';
    }
    std::cout << '\n';
    
    // 8
    int* z;
    
    // 9
    z = x;
    
    // 10
    for (int i = 0; i < 5; ++i) {
        std::cout << *(z++) << ' ';
    }
    
    
    return 0;
}

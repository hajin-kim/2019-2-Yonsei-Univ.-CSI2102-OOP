//
//  E02.cpp
//  10.1 1-P
//
//  Created by 김하진 on 19.10. 1.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int E02()
{
    int n;
    std::cin >> n;
    
    while (n > 0) {
        int* arr = new int[n];
        
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << ' ';
        }
        
        delete[] arr;
        
        std::cout << '\n';
        std::cin >> n;
    }
    
    return 0;
}

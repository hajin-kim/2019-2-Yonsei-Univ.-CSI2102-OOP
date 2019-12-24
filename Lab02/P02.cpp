//
//  P02.cpp
//  9.10-2-P
//
//  Created by 김하진 on 19.9. 10.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int P02()
{
    int inp;
    std::cin >> inp;
    
    switch ((inp+1)/2) {
        case 2:
            std::cout << 'D';
            break;
        case 3:
            std::cout << 'C';
            break;
        case 4:
            std::cout << 'B';
            break;
        case 5:
            std::cout << 'A';
            break;
        default:
            std::cout << 'F';
            break;
    }
    return 0;
}

//
//  P04.cpp
//  9.10-2-P
//
//  Created by 김하진 on 19.9. 11.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int P04()
{
    int inp, f1 = 0, f2 = 1, f3 = 2, now;
    
    std::cin >> inp;
    
    switch (inp) {
        case 1:
            std::cout << f1;
            break;
        case 2:
            std::cout << f1 << ' ' << f2;
            break;
        default:
            std::cout << f1 << ' ' << f2 << ' ' << f3;
            for(int i = 3; i < inp; ++i)
            {
                now = f3 + f1;
                std::cout << ' ' << now;
                f1 = f2;
                f2 = f3;
                f3 = now;
            }
    }
    
    return 0;
}

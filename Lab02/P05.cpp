//
//  P05.cpp
//  9.10-2-P
//
//  Created by 김하진 on 19.9. 11.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int P05()
{
    bool flag = false;
    int inp, sta = 1, end = 20, med;
    
    std::cin >> inp;
    
    std::cout << (med = (sta + end) / 2);
    
    while(!(flag = inp == med))
    {
        if(med > inp)
            end = med;
        else
            sta = med;
        std::cout << ' ' << (med = (sta + end) / 2);
    }
    
    return 0;
}

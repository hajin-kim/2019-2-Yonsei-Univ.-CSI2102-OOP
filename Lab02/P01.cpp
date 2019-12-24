//
//  P01.cpp
//  9.10-2-P
//
//  Created by 김하진 on 19.9. 10.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int P01()
{
    int a, b, c, res;
    
    std::cin >> a >> b >> c;
    
    res = b * b - 4 * a * c;
    
    if(res > 0)
    {
        std::cout << 2;
    }
    else if(res == 0)
        std::cout << 1;
    else
        std::cout << 0;
    
    return 0;
}

//
//  P06.cpp
//  9.10-2-P
//
//  Created by 김하진 on 19.9. 11.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

void swap2(int &x, int &y)
{
    int temp = x;
    x = 2 * y;
    y = temp;
}

int P06()
{
    int x, y;
    
    std::cin >> x >> y;
    
    if(x > 2 * y)
    {
        swap2(x, y);
    }
    
    std::cout << x << ' ' << y;
    
    return 0;
}

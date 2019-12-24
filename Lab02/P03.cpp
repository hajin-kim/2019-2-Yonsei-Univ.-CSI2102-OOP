//
//  P03.cpp
//  9.10-2-P
//
//  Created by 김하진 on 19.9. 11.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <string>

int P03()
{
    std::string a, b, c, temp;
    
    std::cin >> a >> b >> c;
    
    if(a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if(a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    
    std::cout << a + '\n' + b + '\n' + c;
    
    return 0;
}

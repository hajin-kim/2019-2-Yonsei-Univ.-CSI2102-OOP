//
//  P02.cpp
//  2019.09.03-02
//
//  Created by 김하진 on 19.9. 3.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int P02()
{
    int inp;
    
    std::cin >> inp;
    
    int a = inp % 10;
    inp /= 10;
    
    int b = inp % 10;
    inp /= 10;
    
    int c = inp % 10;
    inp /= 10;
    
    int d = inp % 10;
    inp /= 10;
    
    int e = inp % 10;
    
    std::cout << e << ' ' <<  d << ' ' <<  c << ' ' <<  b << ' ' <<  a;
    
    return 0;
}

//
//  P07.cpp
//  9.10-2-P
//
//  Created by 김하진 on 19.9. 10.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int daysInMonth(int month)
{
    switch(month)
    {
        case 12: return 31;
        case 11: return 30;
        case 10: return 31;
        case 9: return 30;
        case 8: return 31;
        case 7: return 31;
        case 6: return 30;
        case 5: return 31;
        case 4: return 30;
        case 3: return 31;
        case 2: return 28;
        case 1: return 31;
    }
    
    return 0;
}

int P07()
{
    int m1, d1, m2, d2, result = 0;
    
    std::cin >> m1 >> d1 >> m2 >> d2;
    
    for(int i = 1; i < m2; ++i)
    {
        result += daysInMonth(i);
    }
    
    for(int i = 1; i < m1; ++i)
    {
        result -= daysInMonth(i);
    }
    
    result += d2 - d1;
    
    std::cout << result;
    
    return 0;
}

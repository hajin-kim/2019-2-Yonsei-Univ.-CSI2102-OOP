//
//  P03.cpp
//  2019.09.03-02
//
//  Created by 김하진 on 19.9. 3.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <string>

int P03()
{
    int inp;
    std::string days = "SUNMONTUEWEDTHUFRISAT";
    
    std::cin >> inp;
    
    std::cout << days.substr(inp*3, 3);
    
    return 0;
}

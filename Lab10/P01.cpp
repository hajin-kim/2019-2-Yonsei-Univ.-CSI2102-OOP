//
//  P01.cpp
//  11.12 1-P
//
//  Created by 김하진 on 19.11. 12.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

int P01() {
    const int days[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    int month;
    
    while (true) {
        try {
            std::cin >> month;
            if (month < 0) {
                throw (std::string)"negative month";
            }
            else if (month > 12) {
                throw (std::string)"month greater than 12";
            }
            if (month == 0) {
                break;
            }
            std::cout << days[month-1] << std::endl;
        } catch (std::string Error) {
            std::cout << "input error: " << Error << ", input again" << std::endl;
        }
        
    }
    
    return 0;
}

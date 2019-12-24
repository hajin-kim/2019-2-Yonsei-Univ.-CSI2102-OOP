//
//  P02.cpp
//  10.29 2-P
//
//  Created by 김하진 on 19.10. 29.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
using std::string;

bool checker(const string inp) {
    if (inp == "a") {
        return true;
    }
    else if (inp.substr(0, 2) == "a+" || inp.substr(0, 2) == "a-") {
        return checker(inp.substr(2, -1));
    }
    return false;
}

int P02() {
    std::string inp;
    std::cin >> inp;
    
    std::cout << ((checker(inp)) ? "yes" : "no");
    
    return 0;
}

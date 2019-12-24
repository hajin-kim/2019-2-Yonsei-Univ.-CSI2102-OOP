//
//  E02.cpp
//  9.23 1-P
//
//  Created by 김하진 on 19.9. 24.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

void inputStrVector(std::vector<std::string>& v)
{
    std::string inp;
    std::cin >> inp;
    
    v.push_back(inp);
}

std::vector<std::string> merge(const std::vector<std::string>& v1, const std::vector<std::string>& v2)
{
    std::vector<std::string> result;
    
    for (int i = 0; i < v1.size(); ++i) {
        result.push_back(v1[i]);
    }
    
    for (int i = 0; i < v2.size(); ++i) {
        result.push_back(v2[i]);
    }
    
    return result;
}

int E02()
{
    int n;
    std::vector<std::string> a, b, printer;
    
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        inputStrVector(a);
    }
    
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        inputStrVector(b);
    }
    
    printer = merge(a, b);
    
    for (int i = 0; i < printer.size(); ++i) {
        std::cout << printer[i] << ' ';
    }
    
    return 0;
}

//
//  E01.cpp
//  9.23 1-P
//
//  Created by 김하진 on 19.9. 24.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <vector>

double dotProduct(const std::vector<double>& a, const std::vector<double>& b);

int E01()
{
    int n;
    std::vector<double> a, b;
    
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        double tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }
    
    for (int i = 0; i < n; ++i) {
        double tmp;
        std::cin >> tmp;
        b.push_back(tmp);
    }
    
    std::cout << dotProduct(a, b);
    
    return 0;
}

double dotProduct(const std::vector<double>& a, const std::vector<double>& b)
{
    double result = 0;
    
    for (int i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    
    return result;
}

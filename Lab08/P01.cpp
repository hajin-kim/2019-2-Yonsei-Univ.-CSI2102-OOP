//
//  P01.cpp
//  10.29 2-P
//
//  Created by 김하진 on 19.10. 29.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
using std::cin;
#include <vector>
using std::vector;

int recursion(vector<int> inp, int count, int result = 0) {
    if (count-- == 0) {
        return result;
    }
    
    result += inp[count];
    
    return recursion(inp, count, result);
}

int P01() {
    int n;
    cin >> n;
    
    vector<int> inp(n);
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }
    
    std::cout << recursion(inp, n);
    
    return 0;
}

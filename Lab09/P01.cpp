//
//  P01.cpp
//  11.05 1-P
//
//  Created by 김하진 on 19.11. 5.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

template<typename Data>
Data average(Data array[], int size) {
    double result = 0;
    
    for (int i = 0; i < size; ++i) {
        result += array[i];
    }
    result /= size;
    
    return result;
}

int P01() {

    int array1[] = { 5, 3, 2, 1, 4 };
    std::cout << average(array1, 5) << std::endl;
    
    double array2[] = { 3.12, 3.45, 9.23, 6.34 };
    std::cout << average(array2, 4) << std::endl;
    
    return 0;
}

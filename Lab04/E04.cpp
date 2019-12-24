//
//  E04.cpp
//  9.23 1-P
//
//  Created by 김하진 on 19.9. 24.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

void transpose(int row, int matrix_getter[][3], int matrix_result[][3])
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            matrix_result[i][j] = matrix_getter[j][i];
        }
    }
}

int E04()
{
    int row = 3;
    int matrix[3][3], matrix_transpose[3][3];
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    std::cout << std::endl;
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            std::cout<< matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    transpose(row, matrix, matrix_transpose);
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            std::cout<< matrix_transpose[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
    return 0;
}

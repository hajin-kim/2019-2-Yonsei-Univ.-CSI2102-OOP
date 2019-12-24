//
//  P02.cpp
//  11.12 1-P
//
//  Created by 김하진 on 19.11. 12.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

class myNegativeIndexError : public std::exception {
    std::string error;
public:
    myNegativeIndexError(std::string e):std::exception(), error(e) {}
    std::string getMessage() const { return error; }
};

class myLargerIndexError : public std::exception {
    std::string error;
public:
    myLargerIndexError(std::string e):std::exception(), error(e) {}
    std::string getMessage() const { return error; }
};

void inputValue(int& index, int& value, int size) {
    std::cin >> index >> value;
    if (index < 0) {
        throw myNegativeIndexError("Negative Index");
    }
    else if (index >= size) {
        throw myLargerIndexError("Wrong Large Index");
    }
}

int P02() {
    
    int a[5] = { 0, 0, 0, 0, 0 };
    
    for (int i = 0; i < 3; i++) {
        int index;
        int value;
        try {
            inputValue(index, value, 5); // 5 = size of array
        }
        catch(myNegativeIndexError e) {
            cout << e.getMessage() << endl;
            exit(0);
        }
        catch(myLargerIndexError e) {
            cout << e.getMessage() << endl;
            exit(0);
        }
        a[index] = value;
    }

    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
    
    return 0;
}

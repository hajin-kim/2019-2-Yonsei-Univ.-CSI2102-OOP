//
//  P03.cpp
//  11.12 1-P
//
//  Created by 김하진 on 19.11. 12.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

using namespace std;

int y = 7;

namespace myspace2 {
int y = 4;

    namespace myspace3 {
        int foo(int x) {
                x += y;
                return x;
        }
    }
}

namespace myspace1 {
    int foo(int x) {
        x += y;
        return x;
    }
}

int P03(int argc, const char * argv[]) {
    
    int z = myspace2::y + myspace1::foo(1)
            - myspace2::myspace3::foo(9) + myspace2::y;
   
    cout << z;
   
    return 0;
}

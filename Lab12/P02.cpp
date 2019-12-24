//
//  P02.cpp
//  11.26 2-P
//
//  Created by 김하진 on 19.11. 26.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;

template<typename T>
void showpq(priority_queue<T> pcl) {
    while (!pcl.empty()) {
        cout << pcl.top() << endl;
        pcl.pop();
    }
}

int P02()
{
    priority_queue<int> pa;
    priority_queue<string> pb;

    // pa에 3, 5, 1, 4, 1, 3 을 순서대로 추가
    pa.push(3);
    pa.push(5);
    pa.push(1);
    pa.push(4);
    pa.push(1);
    pa.push(3);
    // pb에 Tom, Jane, Brown, Scott, Mark, Ted 를 순서대로 추가
    pb.push("Tom");
    pb.push("Jane");
    pb.push("Brown");
    pb.push("Scott");
    pb.push("Mark");
    pb.push("Ted");

    // showpq는 priority_queue의 top element를 print하고 pop 한다.
    // print and pop은 priority_queue가 empty일 때까지 계속한다.
    // showpq는 template function으로 구현하여야 한다.

    showpq(pa);
    showpq(pb);

    map<int,string> m;

    // m에 pa와 pb에 추가한 데이터를 하나씩 짝지어 추가
    // 즉, (3, Tom), (5, Jane), (1, Brown), (4, Scott), (1, Mark), (3, Ted) 순서로 추가
    m.insert(make_pair(3, "Tom"));
    m.insert(make_pair(5, "Jane"));
    m.insert(make_pair(1, "Brown"));
    m.insert(make_pair(4, "Scott"));
    m.insert(make_pair(1, "Mark"));
    m.insert(make_pair(3, "Ted"));
    
    // map m의 내용을 iterator를 사용하여 print
    for (map<int, string>::const_iterator it = m.cbegin(); it != m.cend(); ++it) {
        cout << it->first << ' ' << it->second << endl;
    }
    
    return 0;
}

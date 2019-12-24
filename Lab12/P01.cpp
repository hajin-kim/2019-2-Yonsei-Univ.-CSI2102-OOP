//
//  P01.cpp
//  11.26 2-P
//
//  Created by 김하진 on 19.11. 26.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

/*
 두 개의 class Person과 Resource가 있습니다. Person은 'string name' 이라는 private member variable이 있고, 'Person(name)' constructor와 'string getName()' 이라는 public function을 가지고 있습니다. Resource에는 'int id'와 'string name' 이라는 두 개의 private member variable이 있고, constructor 'Resource(id, name)'이 있으며,  'int getID()', 'string getName()' 이라는 public function들이 있습니다. 아래 main() function을 완성하고 class들을 구현하십시오.
 */

class Person {
private:
    string name;
    
public:
    Person(string name):name(name) {}
    string getName() const { return name; }
    
};

class Resource {
private:
    int id;
    string name;
    
public:
    Resource(int id, string name):id(id), name(name) {}
    int getID() const { return id; }
    string getName() const { return name; }
};

int P01() {
    list<Person*> plist;
    // plist에 Tom, Jane, Brown, Scott 라는 4명의 person들을 추가
    plist.push_back(new Person("Tom"));
    plist.push_back(new Person("Jane"));
    plist.push_back(new Person("Brown"));
    plist.push_back(new Person("Scott"));
    
    deque<Resource*> rdeque;
    // rdeque에 (1 cpu), (2 memory), (3 disk) 의 3명의 resource들을 추가
    rdeque.push_back(new Resource(1, "cpu"));
    rdeque.push_back(new Resource(2, "memory"));
    rdeque.push_back(new Resource(3, "disk"));
    
    stack<Resource*>  rstack;
    // rstack에 rdeque와 같은 순서로 resource들을 추가
    rstack.push(new Resource(1, "cpu"));
    rstack.push(new Resource(2, "memory"));
    rstack.push(new Resource(3, "disk"));
    
    queue<Person*> pqueue;
    // pqueue에 plist와 같은 순서로 person들을 추가
    pqueue.push(new Person("Tom"));
    pqueue.push(new Person("Jane"));
    pqueue.push(new Person("Brown"));
    pqueue.push(new Person("Scott"));

    // plist의 내용을 iterator를 사용하여 출력
    for (list<Person*>::const_iterator pli = plist.begin(); pli != plist.end(); ++pli) {
        cout << (*pli)->getName() << endl;
    }
    
    // rdeque 의 내용을 iterator를 사용하여 출력
    for (deque<Resource*>::const_iterator rdi = rdeque.begin(); rdi != rdeque.end(); ++rdi) {
        cout << (*rdi)->getID() << ' ' << (*rdi)->getName() << endl;
    }
    
    // rstack의 내용을 출력 (iterator 사용 안함)
    while (!rstack.empty()) {
        cout << rstack.top()->getID() << ' ' << rstack.top()->getName() << endl;
        rstack.pop();
    }
    
    // pqueue의 내용을 출력 (iterator 사용 안함)
    while (!pqueue.empty()) {
        cout << pqueue.front()->getName() << endl;
        pqueue.pop();
    }

    return 0;
}

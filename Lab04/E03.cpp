//
//  E03.cpp
//  9.23 1-P
//
//  Created by 김하진 on 19.9. 24.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

class Item {
private:
    std::string name;
    int score;
    
public:
    Item():name(""), score(0){}
    Item(std::string name, int score):name(name), score(score){}
    
    int GetScore() const
    {
        return score;
    }
    
    std::string GetName() const
    {
        return name;
    }
    
    void PrintItem() const
    {
        std::cout << name << ' ' << score << std::endl;
    }
    
    void AddScore(int s)
    {
        score += s;
    }
};

int E03()
{
    std::vector<Item> itemList;
    
    int n;
    std::cin >> n;
    
    std::string name_getter;
    int score_getter;
    
    for (int i = 0; i < n; ++i) {
        
        std::cin >> name_getter >> score_getter;
        
        itemList.push_back(Item(name_getter, score_getter));
    }
    
    std::cin >> name_getter >> score_getter;
    bool flag = true, flag2 = false;
    
    for (int i = 0; i < n; ++i) {
        if (flag) {
            
            if (itemList[i].GetName() > name_getter) {
                Item(name_getter, score_getter).PrintItem();
                flag = false;
            }
            else if (itemList[i].GetName() == name_getter) {
                if (itemList[i].GetScore() < score_getter) {
                    flag2 = true;
                }
                else {
                    Item(name_getter, score_getter).PrintItem();
                }
                flag = false;
            }
        }
        
        itemList[i].PrintItem();
        
        if (flag2) {
            Item(name_getter, score_getter).PrintItem();
            flag2 = false;
        }
    }
    
    if (flag) {
        Item(name_getter, score_getter).PrintItem();
    }
    
    return 0;
}

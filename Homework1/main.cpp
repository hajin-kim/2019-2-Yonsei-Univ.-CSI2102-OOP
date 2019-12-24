//
//  main.cpp
//  9.23-HW1
//
//  Created by 김하진 on 19.9. 23.
//  Copyright © 2019 김하진. All rights reserved.
//

/*
 Condition 1:
 The program has two classes, Person and Family.
 The Person class is implemented in Person.h and Person.cpp.
 Family classes are implemented in Family.h and Family.cpp.
 
 Condition 7:
 All the ERROR handling shown in the following example should be done.
 Error cases not shown here do not need to be implemented.
 
 Condition 2, 3, 4 are in each cpp files.
 */
#include "Person.h"
#include "Family.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int GetData(std::vector<Family>&, std::string);
int PrintMenu();

int FnameIndex(std::vector<Family>, std::string);

int PrintAll(std::vector<Family>);
int PrintFamily(std::vector<Family>, std::string);
int AddMember(std::vector<Family>&, std::string, Person);
int DeleteMember(std::vector<Family>&, std::string, std::string);
int NewFamily(std::vector<Family>&, std::string);
//int QuitSystem();
//int IllegalCommand(std::string);

/*
 Condition 5:
 main.cpp has a main () function.
 */
int main() {
    /*
     Condition 6:
     main () has a "vector <Family> famList" to hold the entire database.
     */
    
    // insert code here...
    std::string menu_getter = "", fname_getter;
    std::string name_getter;
    int age_getter;
    char gender_getter;
    
    std::vector<Family> famList;
    
    // Get data
    std::cout << "--------------------------------------------------" << '\n';
    
    if (GetData(famList, (std::string)"Davis") == 0) {
        std::cout << "Davis family data read completed" << '\n';
    }
        
    if (GetData(famList, (std::string)"Clark") == 0) {
        std::cout << "Clark family data read completed" << '\n';
    }
    
    std::cout << "--------------------------------------------------";
    
    // Main loop:
    while(true)
    {
        PrintMenu();

        std::cin >> menu_getter;
        
        if (menu_getter == "pa") {
            PrintAll(famList);
        }
        else if (menu_getter == "p") {
            std::cin >> fname_getter;
            
            PrintFamily(famList, fname_getter);
        }
        else if (menu_getter == "a") {
            std::cin >> fname_getter >> name_getter
                >> age_getter >> gender_getter;
            
            AddMember(famList, fname_getter, Person(name_getter, age_getter, gender_getter));
        }
        else if (menu_getter == "d") {
            std::cin >> fname_getter >> name_getter;
            
            DeleteMember(famList, fname_getter, name_getter);
        }
        else if (menu_getter == "n") {
            std::cin >> fname_getter;
            
            NewFamily(famList, fname_getter);
        }
        else if (menu_getter == "q") {
//            QuitSystem();
            break;
        }
        else {
//            IllegalCommand(menu_getter);
            std::cout << "  ERROR: illegal command: " << menu_getter << std::endl;
        }
        
//        if (menu_getter == "pa") {
//
//        }
//        else if (menu_getter == "p") {
//            std::cout << fname_getter;
//        }
//        else if (menu_getter == "a") {
//            std::cout << fname_getter << name_getter
//                << age_getter << gender_getter;
//        }
//        else if (menu_getter == "d") {
//            std::cout << fname_getter << name_getter;
//        }
//        else if (menu_getter == "n") {
//            std::cout << fname_getter;
//        }
//        else if (menu_getter == "q") {
//
//        }
//        std::cin >> fname_getter;
//        std::cin >> name_getter;
//        std::cin >> age_getter;
//        std::cin >> gender_getter;
    }
    
    // Terminate program
    std::cout << "QUIT the system";
    
    return 0;
}

int GetData(std::vector<Family>& famList, std::string fname_getter)
{
    // Open file and check fopenning problem
    const char * filename = (fname_getter + ".txt").c_str();
    
    std::ifstream inp(filename);
    
    if(inp.is_open() == false)
        return -1;
    
    // Init
    std::vector<Person> newPersonList;
    
    std::string fname;
    inp >> fname;

    std::string name;
    int age;
    char gen_char = '\0';
    
    // Read all data from ifstream inp
    while (inp >> name >> age >> gen_char) {
        Gender gen_enum = NONE;
        
        if (gen_char == 'M') {
            gen_enum = MALE;
        }
        else if (gen_char == 'F') {
            gen_enum = FEMALE;
        }
        
        newPersonList.push_back(Person(name, age, gen_enum));
    }
    
    // Push to Person vector, of Family class, of famList vector
    famList.push_back(Family(fname, newPersonList));
    
    inp.close();
    
    return 0;
}

int PrintMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------" << '\n';
    std::cout << "Commands Menu:" << '\n';
    std::cout << "  pa : print data of all families" << '\n';
    std::cout << "  p fname : print data of fname family" << '\n';
    std::cout << "  a fname name age gender : add a new member to fname family" << '\n';
    std::cout << "  d fname name : delete a member from fname family" << '\n';
    std::cout << "  n fname : add a new family (of fname) to database" << '\n';
    std::cout << "  q : quit the system" << std::endl;
    std::cout << "  command: ";
    
    return 0;
}

int FnameIndex(std::vector<Family> allFamily, std::string fname)
{
    for (int i = 0; i < allFamily.size(); ++i) {
        // Don't consider overlapping of fname in allFamily
        if (allFamily[i].GetFname() == fname) {
            return i;
        }
    }
    
    // Fname doesn't exist
    return -1;
//
//    bool is_exist = false;
//    int f_index;
//
//    for (int i = 0; i < allFamily.size(); ++i) {
//        // Don't consider overlapping of fname in allFamily
//        if (allFamily[i].GetFname() == fname) {
//            f_index = i;
//            is_exist = true;
//            break;
//        }
//    }
//
//    if (is_exist == false) {
//        return -1;
//    }
//
//    return f_index;
}

int PrintAll(std::vector<Family> allFamily)
{
    std::cout << std::endl;
    
    for (int i = 0; i < allFamily.size(); ++i) {
        allFamily[i].PrintFamily();
    }
    
    return 0;
}

int PrintFamily(std::vector<Family> allFamily, std::string fname)
{
    int f_index = FnameIndex(allFamily, fname);
    
    if (f_index == -1) {
        std::cout << "  ERROR: family name error: " << fname << std::endl;
        return -1;
    }
    else {
        std::cout << std::endl;
        allFamily[f_index].PrintFamily();
    }
    
    return 0;
}

int AddMember(std::vector<Family>& allFamily, std::string fname, Person newPerson)
{
    int f_index = FnameIndex(allFamily, fname);
    
    if (f_index == -1) {
        std::cout << "  ERROR: family name error: " << fname << std::endl;
        return -1;
    }
    else {
        allFamily[f_index].PushPerson(newPerson);
    }
    
    return 0;
}

int DeleteMember(std::vector<Family>& allFamily, std::string fname, std::string name)
{
    int f_index = FnameIndex(allFamily, fname);
    
    if (f_index == -1) {
        std::cout << "  ERROR: family name error: " << fname << std::endl;
        return -1;
    }
    else {
        allFamily[f_index].DeletePerson(name);
    }
    
    return 0;
}

int NewFamily(std::vector<Family>& allFamily, std::string fname)
{
    int f_index = FnameIndex(allFamily, fname);
    
    if (f_index == -1) {
        allFamily.push_back(Family(fname));
    }
    else {
        std::cout << "  ERROR: " << fname << " family already exists" << std::endl;
        return -1;
    }
    
    return 0;
}

//int IllegalCommand(std::string menu)
//{
//    std::cout << "  ERROR: illegal command: " << menu << std::endl;
//
//    return 0;
//}

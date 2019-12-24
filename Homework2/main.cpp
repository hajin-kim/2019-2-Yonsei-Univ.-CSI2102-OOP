//
//  main.cpp
//  10.12 HW2
//
//  Created by 김하진 on 19.10. 15.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

/*
 condition 1, 2: in gobject.h
 
 condition 3:
 The pslib.h and pslib.cpp files should be included in the project without any changes.
 */
#include "pslib.h"
#include "gobject.h"


/*
 condition 4:
 main.cpp has a main() function.
 */
int main(int argc, const char * argv[]) {
    /*
     condition 5:
     main() has a "vector<GObject*> gObj" to hold the entire database.
     The information of all graphical objects read from the input file is stored in this vector.
     */
    std::vector<GObject*> gObj; // init graphic object vector
    ifstream inputFile("command.txt");  // init command file
    
    std::string _psLibFile_name;    // get output file name of psLib
    inputFile >> _psLibFile_name;
    
    cPSLib psLibFile(_psLibFile_name); // init postscript library file
    psLibFile.open();
    
    std::string type;
    // get commands
    while (inputFile >> type) {
        // get common arguments
        std::string name, color;
        inputFile >> name >> color;
        
        // get Line object
        if (type == "line") {
            double x1, y1, x2, y2, width;
            inputFile >> x1 >> y1 >> x2 >> y2 >> width;
            gObj.push_back(new Line("LINE", name, color, x1, y1, x2, y2, width));
        }
        // get Circle object
        else if (type == "circle") {
            double cx, cy, radius, width;
            std::string _f;
            bool fill = false;
            inputFile >> cx >> cy >> radius >> width >> _f;
            if (_f == "true") {
                fill = true;
            }
            gObj.push_back(new Circle("CIRCLE", name, color, cx, cy, radius, width, fill));
        }
        // get Point object
        else if (type == "point") {
            double x, y;
            inputFile >> x >> y;
            gObj.push_back(new Point("POINT", name, color, x, y));
        }
        // get Polygon object
        else if (type == "polygon") {
            int n;
            inputFile >> n;
            std::vector<double> x_vector, y_vector;
            double width;
            std::string _f;
            bool fill = false;
            for (int i = 0; i < n; ++i) {
                double _x, _y;
                inputFile >> _x >> _y;
                x_vector.push_back(_x);
                y_vector.push_back(_y);
            }
            inputFile >> width >> _f;
            if (_f == "true") {
                fill = true;
            }
            gObj.push_back(new Polygon("POLYGON", name, color, x_vector, y_vector, width, fill));
        }
        // get Text object
        else if (type == "text") {
            double x, y;
            std::string text;
            int scale;
            inputFile >> x >> y >> text >> scale;
            gObj.push_back(new Text("TEXT", name, color, x, y, text, scale));
        }
    }
    /*
     condition 6:
     The printed output should look like the example given above and use the print function for each class.
     The print function of each derived class must call GObject's print function inside it.
     You should use polymorphism technique in this part.

     condition 7:
     The postscript drawing should be implemented in draw function of each class.
     You should use polymorphism technique in this part.
     */
    for (int i = 0; i < gObj.size(); ++i) {
        gObj[i]->draw(psLibFile);
        gObj[i]->print();
    }
    
    inputFile.close();
    psLibFile.close();
    
    for (int i = 0; i < gObj.size(); ++i) {
        delete gObj[i];
    }
    
    return 0;
}

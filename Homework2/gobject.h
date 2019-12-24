//
//  gobject.h
//  10.12 HW2
//
//  Created by 김하진 on 19.10. 15.
//  Copyright © 2019 김하진. All rights reserved.
//

#ifndef gobject_h
#define gobject_h

#include <iostream>
#include <vector>

#include "pslib.h"


/*
 condition 1:
 The program has six classes: GObject, Line, Circle, Point, Polygon, and Text.
 All five types graphical object classes are derived classes from the base class GObject.
 All six classes are implemented in “gobject.h” and “gobject.cpp” source files.
 Each class has member variables and functions as in the following figure.
 
 condition 2:
 There should be a single (and the only one) constructor in each class.
 */

// class GObject
class GObject {
protected:
    std::string type, name, color;
    
public:
    GObject(std::string _type, std::string _name, std::string _color);
    virtual void draw(cPSLib& ps);
    virtual void print() const;
};

// class Line
class Line: public GObject {
private:
    double x1, y1, x2, y2, width;
    
public:
    Line(std::string _type, std::string _name, std::string _color,
     double _x1, double _y1, double _x2, double _y2, double _width);
    void draw(cPSLib& ps);
    void print() const;
};

// class Circle
class Circle: public GObject {
private:
    double cx, cy, radius, width;
    bool fill;
    
public:
    Circle(std::string _type, std::string _name, std::string _color,
     double _cx, double _cy, double _radius, double _width, bool _fill);
    void draw(cPSLib& ps);
    void print() const;
};

// class Point
class Point: public GObject {
private:
    double x, y;
    
public:
    Point(std::string _type, std::string _name, std::string _color,
     double _x, double _y);
    void draw(cPSLib& ps);
    void print() const;
};

// class Polygon
class Polygon: public GObject {
private:
    std::vector<double> x, y;
    double width;
    bool fill;
    
public:
    Polygon(std::string _type, std::string _name, std::string _color,
     std::vector<double> _x, std::vector<double> _y, double _width, bool _fill);
    void draw(cPSLib& ps);
    void print() const;
};

// class Text
class Text: public GObject {
private:
    double x, y;
    std::string text;
    int scale;
    
public:
    Text(std::string _type, std::string _name, std::string _color,
     double _x, double _y, std::string _text, int _scale);
    void draw(cPSLib& ps);
    void print() const;
};

#endif /* gobject_h */

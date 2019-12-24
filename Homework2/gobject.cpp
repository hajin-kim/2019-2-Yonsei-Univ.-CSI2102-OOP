//
//  gobject.cpp
//  10.12 HW2
//
//  Created by 김하진 on 19.10. 15.
//  Copyright © 2019 김하진. All rights reserved.
//

#include "gobject.h"

// class GObject
GObject::GObject(std::string _type, std::string _name, std::string _color)
:type(_type), name(_name), color(_color) {

}

void GObject::draw(cPSLib& ps) {
    return;
}

void GObject::print() const {
    std::cout << type << ' ' << name << ' ' << color;
}

// class Line
Line::Line(std::string _type, std::string _name, std::string _color,
 double _x1, double _y1, double _x2, double _y2, double _width)
:GObject(_type, _name, _color) {
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
    width = _width;
}

void Line::draw(cPSLib& ps) {
    ps.drawLine(x1, y1, x2, y2, color, width);
}

void Line::print() const {
    GObject::print();
    std::cout
     << " (" << x1 << ',' << y1 << ") (" << x2 << ',' << y2 << ") "
     << width << std::endl;
}

// class Circle
Circle::Circle(std::string _type, std::string _name, std::string _color,
 double _cx, double _cy, double _radius, double _width, bool _fill)
:GObject(_type, _name, _color) {
    cx = _cx;
    cy = _cy;
    radius = _radius;
    width = _width;
    fill = _fill;
}

void Circle::draw(cPSLib& ps) {
    ps.drawCircle(cx, cy, radius, color, width, fill);
}

void Circle::print() const {
    GObject::print();
    std::cout
     << " (" << cx << ',' << cy << ") "
     << radius << ' ' << width << ' ' << (fill? 1: 0) << std::endl;
}

// class Point
Point::Point(std::string _type, std::string _name, std::string _color,
 double _x, double _y)
:GObject(_type, _name, _color) {
    x = _x;
    y = _y;
}

void Point::draw(cPSLib& ps) {
    ps.drawCircle(x, y, 5, color, 5, true);
}

void Point::print() const {
    GObject::print();
    std::cout
     << " (" << x << ',' << y << ')' << std::endl;
}

// class Polygon
Polygon::Polygon(std::string _type, std::string _name, std::string _color,
 std::vector<double> _x, std::vector<double> _y, double _width, bool _fill)
:GObject(_type, _name, _color) {
    x = _x;
    y = _y;
    width = _width;
    fill = _fill;
}

void Polygon::draw(cPSLib& ps) {
    ps.drawPolygon(x, y, color, width, fill);
}

void Polygon::print() const {
    GObject::print();
    int n = x.size() == y.size()? (int)x.size(): 0;
    std::cout << ' ' << n;
    for (int i = 0; i < n; ++i)
    {
        cout << " (" << x[i] << ',' << y[i] << ")";
    }
    cout << ' ' << width << ' ' << (fill? 1: 0) << std::endl;
}

// class Text
Text::Text(std::string _type, std::string _name, std::string _color,
 double _x, double _y, std::string _text, int _scale)
:GObject(_type, _name, _color) {
    x = _x;
    y = _y;
    text = _text;
    scale = _scale;
}

void Text::draw(cPSLib& ps) {
    ps.drawText(x, y, text, scale, color);
}

void Text::print() const {
    GObject::print();
    std::cout
     << " (" << x << ',' << y << ") \""
     << text << "\" " << scale << std::endl;
}


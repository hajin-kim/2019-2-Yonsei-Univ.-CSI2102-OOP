//------------------------------------------------------------
// pslib.h: postscript program writing utilities
//
// written by In-Kwon Lee (iklee@yonsei.ac.kr)
// Version 4.0: October, 2019
//------------------------------------------------------------

#ifndef _PSLIB_H_
#define _PSLIB_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <vector> 

using namespace std; 

// constants for A4 size
const double A4WIDTH = 595.0f;
const double A4HEIGHT = 842.0f;

// colors
enum psColorIndex {PS_RED, PS_GREEN, PS_BLUE, PS_YELLOW, PS_CYAN,
    PS_MAGENTA, PS_BLACK, PS_WHITE, PS_GRAY};

static double psColor[9][3] = {
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {1.0, 0.0, 1.0},
    {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0},
    {0.5, 0.5, 0.5}
};

class cPSLib
{

public:
	// constructors
	cPSLib(); 
	cPSLib(string fileName);

	// accessor functions
    string getFileName() const;

	// mutator functions
    void setFileName(string fileName);

	// drawing functions
	void drawLine(double x1, double y1, double x2, double y2,
                  string color, double width);
	void drawCircle(double cx, double cy, double radius,
		            string color,  double width, bool fill);
	void drawText(double x, double y, string text,
                  int scale, string color);
	void drawPolygon(const vector<double>& x, const vector<double>& y,
                     string color, double width, bool fill);
	
	// utility functions for writing
	void open();
	void close();

private:
	string fileName;			// postscript file name
	ofstream outStream;			// ouput file stream
    // get color index from the color name
    psColorIndex colorIndexFromName(string colorName);
}; 

#endif

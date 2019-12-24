//------------------------------------------------------------
// pslib.cpp: postscript program writing utilities
//
// written by In-Kwon Lee (iklee@yonsei.ac.kr)
// Version 4.0: October, 2019
//------------------------------------------------------------

#include "pslib.h"

// constructors
cPSLib::cPSLib()
{
    fileName = "out.ps";
}

cPSLib::cPSLib(string fileName)
{
    this->fileName = fileName;
}

// accessor functions
string cPSLib::getFileName() const
{
	return fileName;
}

// mutator functions
void cPSLib::setFileName(string fileName)
{
    this->fileName = fileName;
}

// drawing functions
void cPSLib::drawLine(double x1, double y1, double x2, double y2,
                      string color, double width)
{
    assert(outStream.is_open());
    int cindex = colorIndexFromName(color);
	outStream << "\nnewpath\n";
	outStream << width << " setlinewidth\n";
    outStream << psColor[cindex][0] << " " << psColor[cindex][1] << " "
              << psColor[cindex][2] << " setrgbcolor\n";
	outStream << x1 << " " << y1 << " moveto\n"; 
	outStream << x2 << " " << y2 << " lineto\n"; 
	outStream << "stroke\n";
}

void cPSLib::drawCircle(double cx, double cy, double radius,
                        string color, double width, bool fill)
{
    assert(outStream.is_open());
    int cindex = colorIndexFromName(color);
	outStream << "\nnewpath\n";
	outStream << width << " setlinewidth\n"; 
	outStream << cx << " " << cy << " " << radius << " 0 360 arc\n";
    outStream << psColor[cindex][0] << " " << psColor[cindex][1] << " "
              << psColor[cindex][2] << " setrgbcolor\n";
	if (fill) outStream << "fill\n"; 
	else outStream << "stroke\n"; 
}

void cPSLib::drawText(double x, double y, string Text, int Scale, string color)
{
    assert(outStream.is_open());
    int cindex = colorIndexFromName(color);
	outStream << "\nnewpath\n"; 
	outStream << x << " " << y << " moveto\n"; 
	outStream << "/Times-Roman findfont " << Scale << " scalefont setfont\n"; 
    outStream << psColor[cindex][0] << " " << psColor[cindex][1] << " "
              << psColor[cindex][2] << " setrgbcolor\n";
	outStream << "(" << Text << ") show\n"; 
}

void cPSLib::drawPolygon(const vector<double>& x, const vector<double>& y,
                         string color, double width, bool fill)
{
    assert(outStream.is_open());
    assert(x.size() > 0 && y.size() > 0);
    assert(x.size() == y.size());
    
    int cindex = colorIndexFromName(color);
    
	outStream << "\nnewpath\n"; 
	outStream << width << " setlinewidth\n"; 
    outStream << psColor[cindex][0] << " " << psColor[cindex][1] << " "
              << psColor[cindex][2] << " setrgbcolor\n";
	outStream << x[0] << " " << y[0] << " moveto\n"; 
	for (int i = 1; i < x.size(); i++) {
		outStream << x[i] << " " << y[i] << " lineto\n"; 
	}
	outStream << "closepath\n"; 
	if (fill) outStream << "fill\n"; 
	else outStream << "stroke\n"; 
}

// utility functions
void cPSLib::open()
{
    outStream.open(fileName);
    assert(outStream.is_open());
    outStream << "%%!\n%%postscript generated by pslib\n\n";
    
    // translation
    outStream << A4WIDTH/2.0 << " " << A4HEIGHT/2.0 << " translate\n";
}

void cPSLib::close()
{
    assert(outStream.is_open());
    outStream << "\nshowpage\n";
    outStream.close();
}

psColorIndex cPSLib::colorIndexFromName(string colorName)
{
    if (colorName == "PS_RED") return PS_RED;
    else if (colorName == "PS_GREEN") return PS_GREEN;
    else if (colorName == "PS_BLUE") return PS_BLUE;
    else if (colorName == "PS_YELLOW") return PS_YELLOW;
    else if (colorName == "PS_CYAN") return PS_CYAN;
    else if (colorName == "PS_MAGENTA") return PS_MAGENTA;
    else if (colorName == "PS_BLACK") return PS_BLACK;
    else if (colorName == "PS_WHITE") return PS_WHITE;
    else if (colorName == "PS_GRAY") return PS_GRAY;
    return PS_BLACK;
}

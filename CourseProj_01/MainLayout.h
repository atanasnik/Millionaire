#include <windows.h>		// In this header file, which is the first among our header files, we include the libraries we need
#include <iomanip>			// for the project and also the "using namespace std" directive.
#include <iostream>

#include <fstream>
#include <string>

#include <stdlib.h>
#include <time.h>

#include <conio.h>
#include <vector>

#include <algorithm> // std::remove

using namespace std;

#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H
void clear(void);
void firstLine(void);		// Here we declare the functions we use to manage the layout of the slides
void space1(void);		
void space2(void);
void firstBorder(void);
void border(void);
void indentLeft(string text);
void centerText1(string textLine);
void centerText2(string textLine, double halfFirstLine);
void centerText3(string textLine, double line);
void centerText1NoEndline(string textLine);

#endif
/**
*
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Atanas Nikov
* @idnumber 3MI0600006
* @compiler VC
*
* <File of .h type that contains all of the external library inclusions and the MainLayout.cpp functions declarations>
*
*/

// In this header file, which is the first among our header files, we include the libraries we need
#include <iomanip>					// for the project and also the "using namespace std" directive.
#include <iostream>

#include <fstream>

#include <string>
#include <vector>

#include <stdlib.h> // randomizing
#include <time.h>

#include <cstdio> // std::rename
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
void sortVector(vector<int>& vec);

#endif
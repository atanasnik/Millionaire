#include <windows.h>		// In this header file, which is the first among our header files, we include the libraries we need
#include <iomanip>			// for the project and also the "using namespace std" directive.
#include <iostream>

#include <fstream>
#include <string>

#include <stdlib.h>
#include <time.h>

#include <conio.h>
#include <vector>

using namespace std;

#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

void firstLine(void);		// Here we declare the functions we use to manage the layout of the slides, plus the
void space1(void);			// function that adjusts the size of the console.
void space2(void);
void firstBorder(void);
void border(void);
void changeConsoleDimensions(void);

#endif
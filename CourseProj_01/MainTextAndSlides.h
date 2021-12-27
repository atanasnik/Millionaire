#include "MainLayout.h"
#ifndef MAINTEXTANDSLIDES_H
#define MAINTEXTANDSLIDES_H

void centerText1(string textLine);
void centerText2(string textLine, double halfFirstLine);
void centerText3(string textLine, double line);

void primaryText(void);			// In this header file we declare the functions that create the default text we
void primaryScreen(void);		// have in our slides and the wrapped functions that print the slides.

void categories(void);
void categoriesMenu(void);

#endif
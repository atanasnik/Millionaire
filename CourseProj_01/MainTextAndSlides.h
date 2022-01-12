#include "MainLayout.h"
#ifndef MAINTEXTANDSLIDES_H
#define MAINTEXTANDSLIDES_H


void centerText1(string textLine);
void centerText2(string textLine, double halfFirstLine);
void centerText3(string textLine, double line);
void centerText1NoEndline(string textLine);

void primaryText(void);			// In this header file we declare the functions that create the default text we
void primaryScreen(void);		// have in our slides and the wrapped functions that print the slides.

void categories(void);
void categoriesMenu(void);


void FirstStage(void);

void awardScreen(void);
void defeatScreen1_1(void);
void defeatScreen1_2(void);


void optionSelect(void);
void wrongInputCategoryScreen(void);
void backToMainMenu(void);
void nextQuesionScreen(void);

void playQuestion(ifstream& file, int start);
void playQuestionNoLifelines(ifstream& file, int start);


#endif
#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"

#ifndef INPUTQUESTIONS_H
#define INPUTQUESTIONS_H

int numLength(int num);
void backToInputQuesScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions);
void backToInputAnsScreen(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions);
void backToChooseCorrect(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void backToChooseLevel(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void backToChooseCategory(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID);

void inputQuesScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions);
void inputAnsScreen(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions);

void formatAnswers1(static unsigned int& awardFunctionCall, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void formatAnswers2(static unsigned int& awardFunctionCall, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void formatQuestion(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions, int& makeID);

void chooseCorrect(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void chooseLevel(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void chooseCategory(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID);
void addToFile(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID);
void saveUniqueNum(static unsigned int& awardFunctionCall, int& makeID, vector<int>& allQuestions);

void addedQuesMessageScreen(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions, int& makeID);
#endif

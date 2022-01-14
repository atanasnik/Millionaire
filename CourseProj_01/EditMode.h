#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
#include "InputQuestions.h"

#ifndef EDITMODE_H
#define EDITMODE_H
bool quesExists(static unsigned int& awardFunctionCall, vector<int>& allQuestions, string& inputID);
void editModeIntro(static unsigned int& awardFunctionCall, vector<int>& allQuestions);
void backToEditModeIntro(static unsigned int& awardFunctionCall, vector<int>& allQuestions);
void editModeScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions, string& inputID);
void readQues(string& inputID);
void copyFile(string& inputID);
void replaceQues(static unsigned int& awardFunctionCall, vector<int>& allQuestions, string& inputID);
void replaceAns(static unsigned int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& inpQuestion);
void replaceCorrectAns(static unsigned int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& ansA, string& ansB, string& ansC, string& ansD, string& inpQuestion);
void addNumToQues(static unsigned int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& ansA, string& ansB, string& ansC, string& ansD, string& inpQuestion);
void editSuccessfulMessage(static unsigned int& awardFunctionCall, vector<int>& allQuestions, string& inputID);
#endif

#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
#include "InputQuestions.h"

#ifndef EDITMODE_H
#define EDITMODE_H
bool quesExists(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void editModeIntro(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void backToEditModeIntro(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void editModeScreen(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void readQues(string& inputID);
void copyFile(string& inputID);
void replaceQues(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void replaceAns(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& inpQuestion, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void replaceCorrectAns(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& ansA, string& ansB, string& ansC, string& ansD, string& inpQuestion, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void addNumToQues(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& ansA, string& ansB, string& ansC, string& ansD, string& inpQuestion, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void editSuccessfulMessage(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
#endif

#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"

#ifndef INPUTQUESTIONS_H
#define INPUTQUESTIONS_H

int numLength(int num);
void backToInputQuesScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void backToInputAnsScreen(int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void backToChooseCorrect(int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void backToChooseLevel(int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void backToChooseCategory(int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);

void inputQuesScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void inputAnsScreen(int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);

void formatAnswers1(string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void formatAnswers2(string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void formatQuestion(string& inpQuestion, vector<int>& allQuestions, int& makeID);

void chooseCorrect(int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void chooseLevel(int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void chooseCategory(int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void addToFile(int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);

void addedQuesMessageScreen(int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions, int& makeID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
#endif

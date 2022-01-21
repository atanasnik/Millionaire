#include "MainLayout.h"
#ifndef MAINTEXTANDSLIDES_H
#define MAINTEXTANDSLIDES_H


void primaryText(void);			// In this header file we declare the functions that create the default text we
void primaryScreen(void);		// have in our slides and the wrapped functions that print the slides.

void categories(void);
void categoriesMenu(void);

void findQuestions(int& awardFunctionCall, vector<int>& allQuestions, ifstream& file);
void SearchQuesLevel1(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel2(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel3(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel4(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel5(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel6(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel7(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel8(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel9(int& awardFunctionCall, vector<int>& allQuestions);
void SearchQuesLevel10(int& awardFunctionCall, vector<int>& allQuestions);

void FirstStage(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);

void WinnerScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void awardScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void defeatScreen1_1(void);
void defeatScreen1_2(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);


void optionSelect(int& awardFunctionCall, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void wrongInputMainMenu(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void wrongInputCategoryScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void backToMainMenu(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void nextQuesionScreen(void);

void playQuestion(ifstream& file, int start,int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void readQuestionAndAnswer(ifstream& file, int start,int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void readQuestion(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void answerToQuestionStandart(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, string& ansLetter);
#endif
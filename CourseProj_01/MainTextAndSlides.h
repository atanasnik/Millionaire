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
* <File of .h type that contains the declarations of the functions in MaintextAndSlides.cpp>
*
*/

#include "MainLayout.h"
#ifndef MAINTEXTANDSLIDES_H
#define MAINTEXTANDSLIDES_H

void primaryText(void);			// In this header file we declare the functions that create the default text we
void primaryScreen(void);		// have in our slides and the wrapped functions that print the slides.

void categories(void);
void categoriesMenu(void);

void findQuestions(int& awardFunctionCall, vector<int>& allQuestions, ifstream& file);
void SearchQuesInFiles(int& awardFunctionCall, vector<int>& allQuestions);

void FirstStage(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);

void WinnerScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void awardScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void defeatScreen1_1(int& awardTimes);
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
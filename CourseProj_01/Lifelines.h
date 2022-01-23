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
* <File of .h type that contains the declarations of the functions in Lifelines.cpp>
*
*/

#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"

#ifndef LIFELINES_H
#define LIFELINES_H

char audienceAnswersEasy(char ansLetter);
char audienceAnswersNormal(char ansLetter);
char audienceAnswersHard(char ansLetter);
void percentages(char suggestion);

void Ask_The_Audience_Confirm();
void Ask_The_Audience_Answer(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, string& ansLetter, char& suggestion);

void readAndAnswerQuestion_Ask_Audience_Easy(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void readAndAnswerQuestion_Ask_Audience_Normal(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void readAndAnswerQuestion_Ask_Audience_Hard(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void LifelineAsk_The_Audience(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);



char tellAnswersEasy(char ansLetter);
char tellAnswersNormal(char ansLetter);
char tellAnswersHard(char ansLetter);

void Phone_A_Friend_Confirm();
void Phone_A_Friend_Answer(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, string& ansLetter, char& suggestionPick);

void readAndAnswerQuestion_Phone_A_Friend_Easy(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void readAndAnswerQuestion_Phone_A_Friend_Normal(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void readAndAnswerQuestion_Phone_A_Friend_Hard(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void LifelinePhone_A_Friend(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);

void Fifty_Fifty_Confirm();
void Fifty_Fifty_Answer(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, string& ansLetter);
void LifelineFifty_Fifty(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);


#endif

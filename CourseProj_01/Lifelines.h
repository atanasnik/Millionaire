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
void Ask_The_Audience_Answer(int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes, string& ansLetter, char& suggestion);

void readAndAnswerQuestion_Ask_Audience_Easy(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);
void readAndAnswerQuestion_Ask_Audience_Normal(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);
void readAndAnswerQuestion_Ask_Audience_Hard(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);
void LifelineAsk_The_Audience(int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);



char tellAnswersEasy(char ansLetter);
char tellAnswersNormal(char ansLetter);
char tellAnswersHard(char ansLetter);

void Phone_A_Friend_Confirm();
void Phone_A_Friend_Answer(int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes, string& ansLetter, char& suggestionPick);

void readAndAnswerQuestion_Phone_A_Friend_Easy(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);
void readAndAnswerQuestion_Phone_A_Friend_Normal(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);
void readAndAnswerQuestion_Phone_A_Friend_Hard(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);
void LifelinePhone_A_Friend(int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);

void Fifty_Fifty_Confirm();
void Fifty_Fifty_Answer(int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes, string& ansLetter);
void LifelineFifty_Fifty(int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes);


#endif

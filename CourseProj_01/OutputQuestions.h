#include "MainLayout.h"
#include "MainTextAndSlides.h"

#ifndef OUTPUTQUESTIONS_H
#define OUTPUTQUESTIONS_H

void Question(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void Category(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, char categoryPick);

#endif

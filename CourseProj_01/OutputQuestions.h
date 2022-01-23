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
* <File of .h type that contains the declarations of the functions in OutputQuestions.cpp>
*
*/

#include "MainLayout.h"
#include "MainTextAndSlides.h"

#ifndef OUTPUTQUESTIONS_H
#define OUTPUTQUESTIONS_H

void Question(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes);
void Category(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, char categoryPick);

#endif

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
* <The main file of the project>
*
*/

#include "MainLayout.h"
#include "MainTextAndSlides.h"



int main()
{
	int awardFunctionCall = 0; // A variable that helps counting the levels htroughout the game
	int awardTimes = 0; // Just like the awardFunctionCall variable, we use it to store info about the  game progress
	int useFifty_Fifty = 0; // This one and the other two below tell if the lifelines have been used
	int useCall_A_Friend = 0;
	int useAsk_The_Audience = 0;
	primaryScreen(); // Where the game starts from
	optionSelect(awardFunctionCall, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes); // Main menu that leads to every other part of the program
	return 0;
}
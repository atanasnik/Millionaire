#include "MainLayout.h"
#include "MainTextAndSlides.h"



int main()
{
	unsigned static int awardFunctionCall = 0; // A static variable that helps counting the levels htroughout the game
	primaryScreen(); // Where the game starts from
	optionSelect(awardFunctionCall); // Main menu that leads to every other part of the program
	return 0;
}
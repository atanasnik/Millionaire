#include "MainLayout.h"
#include "MainTextAndSlides.h"



int main()
{
	unsigned static int awardFunctionCall = 0;
	primaryScreen();
	changeConsoleDimensions();
	vector<int> allQuestions;

	optionSelect(awardFunctionCall, allQuestions);


	return 0;
}
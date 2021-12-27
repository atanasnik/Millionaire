#include "MainLayout.h"
#include "MainTextAndSlides.h"

int main()
{
	primaryScreen();
	changeConsoleDimensions();

	char optionPick;
	cin >> optionPick; // TODO: Secure the cases where the input is wrong.

	if (optionPick == 'N')
	{
		categoriesMenu(); // TODO: Let the user pick a number and secure the wrong input cases.
	}						// Checking if pushing works correctly

	return 0;
}
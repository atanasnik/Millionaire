#include "MainLayout.h"
#include "MainTextAndSlides.h"

int main()
{
	primaryScreen();
	changeConsoleDimensions();

	char optionPick;
	cin >> optionPick; // TODO: Secure the cases where the input is wrong.

	if (optionPick == 'N' || optionPick == 'n')
	{
        FirstStage();	// TODO: still have some modifications to do on arrays on FirstStage and etc.
	}						
	if (optionPick == 'X' || optionPick == 'x')
	{
		return 0;
	}
	


	return 0;
}
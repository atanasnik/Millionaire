#include "MainLayout.h"
#include "MainTextAndSlides.h"

void centerText1(string textLine)
{
	int halfWidth = 90 / 2;		// This is precisely half of the width of the border of "="'s.
	double wordSpacing = textLine.length() / 2;
	cout << setw(halfWidth + wordSpacing) << textLine << endl;	// We use the <iomanip> function setw, which provides the space
}																// we need to center the text lines.
void centerText2(string textLine, double halfFirstLine)
{
	int halfWidth = 90 / 2;
	cout << setw(halfWidth + halfFirstLine/2) << textLine << endl;		// We use the different text alingment functions
}																		// in the different situations.
void centerText3(string textLine, double line)
{
	int halfWidth = 90 / 2;
	double rowSpace = line - textLine.length();							// This function copies the starting point of a 
	rowSpace -= line / 2;												// line and makes all lines bellow it start from
	++rowSpace;															// the same point.
	cout << setw(halfWidth - rowSpace) << textLine << endl;
}

// Specific to the first slide:

void primaryText()
{
	cout << endl;
	for (int i = 0; i < 4; ++i)
	{
		string option = {};
		switch (i)
		{
		case 0: option = "Press \"N\" to start a new game."; break;	// These will be the lines of text in our first slide.
		case 1: option = "Press \"C\" to create a new question."; break;
		case 2: option = "Press \"E\" to edit an existing question."; break;
		case 3: option = "Press \"X\" to exit game.";
		}
		centerText1(option);
	}
	cout << endl;
}
void primaryScreen()			// This function wraps up all the work we have done on the primary screen and prints its
{								// default appearance.
	firstBorder();
	primaryText();
	border();
	space1();
}

// Specific to the Categories menu:

void categories()
{
	space2();
	int num;
	int rows = 8;
	string category = "Choose a category: ";

	double halfFirstLine;						// We are gonna use halfFirstLine and line to align the text.
	halfFirstLine = category.length() / 2;

	category.clear();
	category = "1. History";

	double line;
	line = category.length();

	for (int i = 0; i < rows; ++i)
	{
		category = {};
		switch (i)
		{
		case 0: category = "Choose a category: "; break; // These will be the lines of text in our category menu.
		case 1: category = "1. History";
			cout << endl; break;
		case 2: category = "2. Geography"; break;
		case 3: category = "3. Science"; break;
		case 4: category = "4. Literature"; break;
		case 5: category = "5. Fun facts"; break;
		case 6:
			cout << endl;
			category = "6. Random"; break;
		case 7:
			cout << endl;
			category = "Pick a number: "; break;
		}
		switch (i)
		{
		case 0: case 7: centerText1(category); break;
		case 1: centerText2(category, halfFirstLine); break;
		default: centerText3(category, line); break;
		}
	}
	cout << endl;
}
void categoriesMenu()
{
	system("CLS");
	space2();
	border();
	categories();
	border();
	space2();
}

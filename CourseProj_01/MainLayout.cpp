#include "MainLayout.h"


// The following functions are specific to the first slide, but we use some of them in the other slides, too.

void clear()
{
	const int LIMIT = 500;
	for (int i = 0; i < LIMIT; ++i)
	{
		cout << endl;
	}
}

void firstLine()	// Prints the first set of "="'s.
{
	int borderHalf = 29;
	for (int i = 0; i < borderHalf; ++i)
	{
		cout << "=";
	}
}
void space1()		// Manages the spacing above the upper border and bellow the lower border of the slide.
{
	int outsideSpace = 5;
	for (int i = 0; i < outsideSpace; ++i)
	{
		cout << endl;
	}
}
void firstBorder()	// This is the upper border of our first slide.
{
	space1();
	firstLine();
	cout << " Who wants to be a millionaire? ";
	firstLine();
	cout << endl;
}
void border()		// This is the border we are going to use from now on so as to manage our slides' layout.
{
	int width = 90;
	for (int i = 0; i < width; ++i)
	{
		cout << "=";
	}
}

// Specific to the Category menu:

void space2()		// Manages the spacing above the upper border and bellow the lower border of the slide as well.
{
	int outsideSpace = 2;
	for (int i = 0; i < outsideSpace; ++i)
	{
		cout << endl;
	}
}
void indentLeft(string text) // Puts text 5 characters aside when printing
{
	int spacing = 5;
	while (spacing > 0)
	{
		cout << " ";
		--spacing;
	}
	cout << text;
}

void centerText1(string textLine)
{
	int halfWidth = 90 / 2;		// This is precisely half of the width of the border of "="'s.
	double wordSpacing = textLine.length() / 2;
	cout << setw(halfWidth + wordSpacing) << textLine << endl;	// We use the <iomanip> function setw, which provides the space
}
// We need to center the text lines.
void centerText1NoEndline(string textLine)
{
	int halfWidth = 90 / 2;		// This is precisely half of the width of the border of "="'s.
	double wordSpacing = textLine.length() / 2;
	cout << setw(halfWidth + wordSpacing) << textLine;	// We use the <iomanip> function setw, which provides the space
}
void centerText2(string textLine, double halfFirstLine)
{
	int halfWidth = 90 / 2;
	cout << setw(halfWidth + halfFirstLine / 2) << textLine << endl;	// We use the different text alingment functions
}																		// in the different situations.
void centerText3(string textLine, double line)
{
	int halfWidth = 90 / 2;
	double rowSpace = line - textLine.length();							// This function copies the starting point of a 
	rowSpace -= line / 2;												// line and makes all lines bellow it start from
	++rowSpace;															// the same point.
	cout << setw(halfWidth - rowSpace) << textLine << endl;
}
void sortVector(vector<int>& vec)
{
	int temp = 0;
	if (vec.size() > 0)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			for (int j = i + 1; j < vec.size(); ++j)
			{
				if (vec[i] > vec[j])
				{
					temp = vec[i];
					vec[i] = vec[j];
					vec[j] = temp;
				}
			}
		}
	}
	else
	{
		cout << "There are currently no questions.";
			return;
	}
}

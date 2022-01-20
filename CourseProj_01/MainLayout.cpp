#include "MainLayout.h"


// The following functions are specific to the first slide, but we use some of them in the other slides, too.

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
void indentLeft(string text)
{
	int spacing = 5;
	while (spacing > 0)
	{
		cout << " ";
		--spacing;
	}
	cout << text;
}

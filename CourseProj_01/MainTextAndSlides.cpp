#include "MainLayout.h"
#include "MainTextAndSlides.h"

char chooseAns;

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

//Specific to the first question:

void awardScreen1()
{
	system("CLS");
	space1();
	border();
	space2();
	centerText1("Congratulations!");
	centerText1("You've won $1000!");
	cout << endl;
	centerText1("Press any key to proceed...");
	space2();
	border();
	space1();
}
void defeatScreen1_1()
{
	system("CLS");
	space1();
	border();
	space2();
	centerText1("Wrong answer!");
	cout << endl;
	centerText1("The right answer was ");
}
void defeatScreen1_2()
{
	cout << endl;
	centerText1("Press any key to go back to the main menu...");
	cout << endl;
	border();
	space1();
}
void Question(int start) // TODO: perhaps divide to smaller functions later
{
	ifstream file;

	file.open("Level1.txt");


	system("CLS");
	space2();
	border();
	space2();


	if (!file.is_open())
	{
		cout << "A mistake occured." << endl;
	}

	string row; // We are going to read the file through this string

	string num; // This string will store the serial number of the question
	num += to_string(start);
	num += ' ';

	string correct = "$$"; // The $$ sign in our text files stays next to the letter of the right answer
	string ansLetter;

	while (getline(file, row))	// Here we use the find function from the string library to locate the serial number of the question
	{
		size_t location = row.find(num);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, num.length()); // Here we remove the serial number from the question in order to present it

	cout << " " << row << endl; // Prints the line where the serial number was

	while (getline(file, row))
	{
		for (int i = 0; row[i] != '\0'; ++i)
		{
			if (row[i] == '\t')	// The tab (\t) is the symbol that separates the questions from one another
			{
				file.close();
			}
		}
		size_t ans = row.find(correct); // Finds the right answer by the $$ sign
		if (ans != string::npos)
		{
			row.erase(ans, correct.length()); // The correct answer gets stored in another string
			ansLetter += row.substr(ans - 2, ans); // TODO: sometimes prints the whole answer
		}

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	file.close();
	for (int i = 0; i < 5; ++i) // temporary!!!!!!
	{
		cout << endl;
	}
	space2();
	border();
	space2();
	cin >> chooseAns; 
	if (chooseAns == ansLetter[0] || chooseAns == char(ansLetter[0]) + 32) // If the user picks the right answer
	{
		awardScreen1();
	}
	else if (chooseAns != ansLetter[0] && chooseAns != char(ansLetter[0]) + 32) // If the user picks the wrong answer
	{
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2();
	}
}
void FirstStage()
{
	categoriesMenu(); // TODO: Let the user pick a number and secure the wrong input cases.
	int categoryPick;
	cin >> categoryPick; 
	switch (categoryPick)
	{
	case 1:
	{
		srand(time(NULL)); // Using the stdlib.h and the time.h libraries, we pick a random element from an array by its index

		int mixArr1[100] = { 1101, 1102 }; // TODO: needs fixing later, so we can add more elements
		int randIndex = rand() % 2;
		// The array stores our questions' serial numbers, so we pick a random question to present

		int start = mixArr1[randIndex];
		Question(start);

	}
	break;
	case 2: //same applies for the cases below:
	{
		srand(time(NULL));

		int mixArr1[100] = { 1201, 1202 };
		int randIndex = rand() % 2;


		int start = mixArr1[randIndex];
		Question(start);
	}
	break;
	case 3:
	{
		srand(time(NULL));

		int mixArr1[100] = { 1301, 1302 };
		int randIndex = rand() % 2;


		int start = mixArr1[randIndex];
		Question(start);
	}
	break;
	case 4:
	{
		srand(time(NULL));

		int mixArr1[100] = { 1401, 1402 };
		int randIndex = rand() % 2;


		int start = mixArr1[randIndex];
		Question(start);
	}
	break;
	case 5:
	{
		srand(time(NULL));

		int mixArr1[100] = { 1501, 1502 };
		int randIndex = rand() % 2;


		int start = mixArr1[randIndex];
		Question(start);
	}
	break;
	case 6:
	{
		srand(time(NULL));

		int mixArr1[100] = { 1101, 1102, 1201, 1202, 1301, 1302, 1401, 1402, 1501, 1502 };
		int randIndex = rand() % 10;


		int start = mixArr1[randIndex];

		Question(start);
	}
	}
}
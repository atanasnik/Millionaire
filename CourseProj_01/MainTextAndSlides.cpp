#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"

void centerText1(string textLine)
{
	int halfWidth = 90 / 2;		// This is precisely half of the width of the border of "="'s.
	double wordSpacing = textLine.length() / 2;
	cout << setw(halfWidth + wordSpacing) << textLine << endl;	// We use the <iomanip> function setw, which provides the space
}	
																	// we need to center the text lines.
void centerText1NoEndline(string textLine)
{
	int halfWidth = 90 / 2;		// This is precisely half of the width of the border of "="'s.
	double wordSpacing = textLine.length() / 2;
	cout << setw(halfWidth + wordSpacing) << textLine;	// We use the <iomanip> function setw, which provides the space
}
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
		case 0: option = "Press \"N\" to start a new game."; 
			break;	// These will be the lines of text in our first slide.
		case 1: option = "Press \"C\" to create a new question."; 
			break;
		case 2: option = "Press \"E\" to edit an existing question."; 
			break;
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
		case 0: 
		{
			category = "Choose a category: ";
		}
			break;                            // These will be the lines of text in our category menu.
		case 1: 
		{
			category = "1. History";
			cout << endl;
		}
			break;
		case 2: 
		{
			category = "2. Geography";
		}
			break;
		case 3: 
		{
			category = "3. Science";
		}
			break;
		case 4: 
		{
			category = 
			"4. Literature";
		}
			break;
		case 5: 
		{
			category = "5. Fun facts";
		}
			break;
		case 6:
		{
			cout << endl;
			category = "6. Random";
		}
			break;
		case 7:
		{
			cout << endl;
			category = "Pick a number: ";
		}
			break;
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

void optionSelect(static unsigned int& awardFunctionCall)
{
	char optionPick;
	cin >> optionPick;

	if (optionPick == 'N' || optionPick == 'n')
	{
		FirstStage(awardFunctionCall);	// TODO: still have some modifications to do on arrays on FirstStage and etc.
	}

	//TODO: add the other cases for "c", "e" and "x"
}
void wrongInputCategoryScreen(static unsigned int& awardFunctionCall)
{
	system("CLS");
	space1();
	border();
	space2();
	centerText1("You didn't pick a category!");
	cout << endl;
	centerText1("Press any key to return to the main menu...");
	space2();
	border();
	space1();
	backToMainMenu(awardFunctionCall);
}

void backToMainMenu(static unsigned int& awardFunctionCall)
{
	char press;
	while (true)
	{
		if (_kbhit())        // the _kbhit() function from the conio.h library checks if a key is being pressed
		{
			press = _getch(); // if so, the _getch() function reads the pressed character and then we can proceed to the
			system("CLS");	
			primaryScreen();			// next screen, in this case, the Main menu.
			optionSelect(awardFunctionCall);
		}
	}
}
//Specific to the first question:

void awardScreen(static unsigned int& awardFunctionCall) //TODO: Separate award screens for the different levels.
{
	++awardFunctionCall;
	int reward = 0;
	switch (awardFunctionCall)
	{
		case 1: 
		{
			reward = 1000;
		}
			break;
		case 2: 
		{
			reward = 2500;
		}
			break;
		case 3: 
		{
			reward = 5000;
		}
			break;
		case 4:
		{
			reward = 10000;
		}
			break;
		case 5: 
		{
			reward = 25000;
		}
			break;
		case 6: 
		{
			reward = 50000;
		}
			break;
		case 7: 
		{
			reward = 100000;
		}
			break;
		case 8: 
		{
			reward = 250000;
		}
			break;
		case 9: 
		{
			reward = 500000;
		}
			break;
		case 10: 
		{
			reward = 1000000;
		}
			break;
	}
	string rewardText;
	rewardText += to_string(reward);
	rewardText += '$';
	string won = "You've won ";
	system("CLS");
	space1();
	border();
	space2();
	centerText1("Congratulations!");
	centerText1("You've won ");
	centerText2(rewardText, won.length()/2);
	cout << endl;
	centerText1("Press any key to proceed...");
	space2();
	border();
	space1();
	if (awardFunctionCall == 10)
	{
		WinnerScreen(awardFunctionCall);
	}
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
void defeatScreen1_2(static unsigned int& awardFunctionCall)
{
	cout << endl;
	centerText1("Press any key to go back to the main menu...");
	cout << endl;
	border();
	space1();
	backToMainMenu(awardFunctionCall);
}
void nextQuesionScreen(void)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			break;
		}
	}
}
void WinnerScreen(static unsigned int& awardFunctionCall)
{
		nextQuesionScreen();
		system("CLS");
		space1();
		border();
		space2();
		centerText1("Good job!");
		centerText1("You won the game!");
		centerText1("Press any key to go back to main menu...");
		cout << endl;
		border();
		space1();
		backToMainMenu(awardFunctionCall);
}
void FirstStage(static unsigned int& awardFunctionCall)
{
	vector<int> allQuestions =
	{
	1101, 1102, 1201, 1202, 1301, 1302, 1401, 1402, 1501, 1502,
	2101, 2102, 2201, 2202, 2301, 2302, 2401, 2402, 2501, 2502,
	3101, 3102, 3201, 3202, 3301, 3302, 3401, 3402, 3501, 3502,
	4101, 4102, 4201, 4202, 4301, 4302, 4401, 4402, 4501, 4502,
	5101, 5102, 5201, 5202, 5301, 5302, 5401, 5402, 5501, 5502,
	6101, 6102, 6201, 6202, 6301, 6302, 6401, 6402, 6501, 6502,
	7101, 7102, 7201, 7202, 7301, 7302, 7401, 7402, 7501, 7502,
	8101, 8102, 8201, 8202, 8301, 8302, 8401, 8402, 8501, 8502,
	9101, 9102, 9201, 9202, 9301, 9302, 9401, 9402, 9501, 9502,
	10101, 10102, 10201, 10202, 10301, 10302, 10401, 10402, 10501, 10502
	};
	categoriesMenu();
	char categoryPick;
	cin >> categoryPick; 
	switch (categoryPick)
	{
		case '1':
		{
			srand(time(NULL)); // Using the stdlib.h and the time.h libraries, we pick a random element from an array by its index
						
			int start = 0;
			int randIndex = 0;

			history1(allQuestions, start, randIndex, awardFunctionCall);
			history2(allQuestions, start, randIndex, awardFunctionCall);
			history3(allQuestions, start, randIndex, awardFunctionCall);
			history4(allQuestions, start, randIndex, awardFunctionCall);
			history5(allQuestions, start, randIndex, awardFunctionCall);
			history6(allQuestions, start, randIndex, awardFunctionCall);
			history7(allQuestions, start, randIndex, awardFunctionCall);
			history8(allQuestions, start, randIndex, awardFunctionCall);
			history9(allQuestions, start, randIndex, awardFunctionCall);
			history10(allQuestions, start, randIndex, awardFunctionCall);
		}
			break;
		case '2': //same applies for the cases below:
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			geography1(allQuestions, start, randIndex, awardFunctionCall);
			geography2(allQuestions, start, randIndex, awardFunctionCall);
			geography3(allQuestions, start, randIndex, awardFunctionCall);
			geography4(allQuestions, start, randIndex, awardFunctionCall);
			geography5(allQuestions, start, randIndex, awardFunctionCall);
			geography6(allQuestions, start, randIndex, awardFunctionCall);
			geography7(allQuestions, start, randIndex, awardFunctionCall);
			geography8(allQuestions, start, randIndex, awardFunctionCall);
			geography9(allQuestions, start, randIndex, awardFunctionCall);
			geography10(allQuestions, start, randIndex, awardFunctionCall);
		}
			break;
		case '3':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			science1(allQuestions, start, randIndex, awardFunctionCall);
			science2(allQuestions, start, randIndex, awardFunctionCall);
			science3(allQuestions, start, randIndex, awardFunctionCall);
			science4(allQuestions, start, randIndex, awardFunctionCall);
			science5(allQuestions, start, randIndex, awardFunctionCall);
			science6(allQuestions, start, randIndex, awardFunctionCall);
			science7(allQuestions, start, randIndex, awardFunctionCall);
			science8(allQuestions, start, randIndex, awardFunctionCall);
			science9(allQuestions, start, randIndex, awardFunctionCall);
			science10(allQuestions, start, randIndex, awardFunctionCall);
		}
			break;
		case '4':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			literature1(allQuestions, start, randIndex, awardFunctionCall);
			literature2(allQuestions, start, randIndex, awardFunctionCall);
			literature3(allQuestions, start, randIndex, awardFunctionCall);
			literature4(allQuestions, start, randIndex, awardFunctionCall);
			literature5(allQuestions, start, randIndex, awardFunctionCall);
			literature6(allQuestions, start, randIndex, awardFunctionCall);
			literature7(allQuestions, start, randIndex, awardFunctionCall);
			literature8(allQuestions, start, randIndex, awardFunctionCall);
			literature9(allQuestions, start, randIndex, awardFunctionCall);
			literature10(allQuestions, start, randIndex, awardFunctionCall);
		}
			break;
		case '5':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			funFacts1(allQuestions, start, randIndex, awardFunctionCall);
			funFacts2(allQuestions, start, randIndex, awardFunctionCall);
			funFacts3(allQuestions, start, randIndex, awardFunctionCall);
			funFacts4(allQuestions, start, randIndex, awardFunctionCall);
			funFacts5(allQuestions, start, randIndex, awardFunctionCall);
			funFacts6(allQuestions, start, randIndex, awardFunctionCall);
			funFacts7(allQuestions, start, randIndex, awardFunctionCall);
			funFacts8(allQuestions, start, randIndex, awardFunctionCall);
			funFacts9(allQuestions, start, randIndex, awardFunctionCall);
			funFacts10(allQuestions, start, randIndex, awardFunctionCall);
		}
			break;
		case '6':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			topicMix1(allQuestions, start, randIndex, awardFunctionCall);
			topicMix2(allQuestions, start, randIndex, awardFunctionCall);
			topicMix3(allQuestions, start, randIndex, awardFunctionCall);
			topicMix4(allQuestions, start, randIndex, awardFunctionCall);
			topicMix5(allQuestions, start, randIndex, awardFunctionCall);
			topicMix6(allQuestions, start, randIndex, awardFunctionCall);
			topicMix7(allQuestions, start, randIndex, awardFunctionCall);
			topicMix8(allQuestions, start, randIndex, awardFunctionCall);
			topicMix9(allQuestions, start, randIndex, awardFunctionCall);
			topicMix10(allQuestions, start, randIndex, awardFunctionCall);
		}
			break;
		default: 
		{
			wrongInputCategoryScreen(awardFunctionCall);
		}
	}
}

void playQuestion(ifstream& file, int start, static unsigned int& awardFunctionCall) // TODO: perhaps divide to smaller functions later
{
	static unsigned int awardTimes = 0;
	static unsigned int useFifty_Fifty = 0;
	static unsigned int useCall_A_Friend = 0;
	static unsigned int useAsk_The_Audience = 0;
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
	int countLen = 0;

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
			for (int i = ans; row[i + 1] != '\0'; ++i)
			{
				if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
				{
					break;
				}
				++countLen;
			}
			ansLetter += row.substr(ans - 2, ans + countLen);
		}

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}
	
	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	(useFifty_Fifty == 0 || useCall_A_Friend == 0 || useAsk_The_Audience == 0) ?
		(cout << " " << "Current lifelines: " << endl) : (cout << endl);
	(useFifty_Fifty == 0) ? (cout << " " << "50/50 (Press X)" << endl) : (cout << endl);
	(useCall_A_Friend == 0) ? (cout << " " << "Phone a friend (Press Y)" << endl) : (cout << endl);
	(useAsk_The_Audience == 0) ? (cout << " " << "Ask the audience (Press Z)" << endl) : (cout << endl);
	space2();
	border();
	space2();
	string chooseAns;
	cin >> chooseAns;
	if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
	{
		++awardTimes;
		awardScreen(awardFunctionCall);
	}
	else if (chooseAns[0] == 'X' || chooseAns[0] == 'x' && useFifty_Fifty == 0)
	{
		switch (awardTimes)
		{
			case 0:
			{
				Ques1LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
				break;
			case 1:
			{
				Ques2LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
				break;
			case 2:
			{
				Ques3LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
				break;
			case 3: 
			{
				Ques4LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
				break;
			case 4:
			{
				Ques5LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
			break;
			case 5:
			{
				Ques6LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
				break;
			case 6:
			{
				Ques7LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
				break;
			case 7:
			{
				Ques8LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
				break;
			case 8:
			{
				Ques9LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
			break;
				case 9:
			{
				Ques10LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
				++useFifty_Fifty;
			}
		}
	}
	else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' && useCall_A_Friend == 0)
	{
		switch (awardTimes)
		{
			case 0: 
			{
				Ques1LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 1:
			{
				Ques2LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 2:
			{
				Ques3LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 3:
			{
				Ques4LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 4:
			{
				Ques5LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 5:
			{
				Ques6LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 6:
			{
				Ques7LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 7:
			{
				Ques8LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 8:
			{
				Ques9LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
				break;
			case 9:
			{
				Ques9LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
				++useCall_A_Friend;
			}
		}
	}
	else if (chooseAns[0] == 'Z' || chooseAns[0] == 'z' && useAsk_The_Audience == 0)
	{
		switch (awardTimes)
		{
			case 0:
			{
				Ques1LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 1:
			{
				Ques2LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 2:
			{
				Ques3LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 3:
			{
				Ques4LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 4:
			{
				Ques5LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 5:
			{
				Ques6LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 6:
			{
				Ques7LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 7:
			{
				Ques8LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 8:
			{
				Ques9LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}
				break;
			case 9:
			{
				Ques10LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall);
				++useAsk_The_Audience;
			}

		}
	}
	else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
	{
		awardFunctionCall = 0;
		awardTimes = 0;
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2(awardFunctionCall);
	}
}

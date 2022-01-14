#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
#include "InputQuestions.h"
#include "EditMode.h"

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
	int rows = 8;
	string category = "Choose a category:";

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
		case 0: case 7: centerText1(category); 
			break;
		case 1: centerText2(category, halfFirstLine); 
			break;
		default: centerText3(category, line);
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
void SearchQuesLevel1(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level1.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel2(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level2.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel3(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level3.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel4(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level4.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel5(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level5.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel6(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level6.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel7(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level7.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel8(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level8.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel9(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level9.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void SearchQuesLevel10(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;
	file.open("Level10.txt");
	if (!file.is_open())
	{
		centerText1("An error occured.");
	}

	findQuestions(awardFunctionCall, allQuestions, file);

	if (file.is_open())
	{
		file.close();
	}
}
void findQuestions(static unsigned int& awardFunctionCall, vector<int>& allQuestions, ifstream& file)
{
	string row;
	int tempNum = 0;
	while (getline(file, row)) // here we use the std::string function stoi to convert strings to integers 
	{
		if (row[0] == '1' || row[0] == '2' || row[0] == '3' || row[0] == '4' || row[0] == '5' ||
			row[0] == '6' || row[0] == '7' || row[0] == '8' || row[0] == '9')
		{
			tempNum = stoi(row, nullptr); // we use nullptr because we don't want to specify when to stop extracting the symbols
			allQuestions.push_back(tempNum); // then, we add the new integer, which represents the new question, to the main vector
		}
	}
	if (file.is_open())
	{
		file.close();
	}
}


void optionSelect(static unsigned int& awardFunctionCall)
{
	vector<int> allQuestions;

	SearchQuesLevel1(awardFunctionCall, allQuestions);
	SearchQuesLevel2(awardFunctionCall, allQuestions);
	SearchQuesLevel3(awardFunctionCall, allQuestions);
	SearchQuesLevel4(awardFunctionCall, allQuestions);
	SearchQuesLevel5(awardFunctionCall, allQuestions);
	SearchQuesLevel6(awardFunctionCall, allQuestions);
	SearchQuesLevel7(awardFunctionCall, allQuestions);
	SearchQuesLevel8(awardFunctionCall, allQuestions);
	SearchQuesLevel9(awardFunctionCall, allQuestions);
	SearchQuesLevel10(awardFunctionCall, allQuestions);
	int size = allQuestions.size();
	char optionPick;
	cin >> optionPick;

	switch (optionPick)
	{
		case 'N': case 'n':
		{
			FirstStage(awardFunctionCall, allQuestions);
		}
			break;
		case 'C': case 'c':
		{
			inputQuesScreen(awardFunctionCall, allQuestions);
		}
		case 'E': case 'e':
		{
			editModeIntro(awardFunctionCall, allQuestions);
		}
	}
	//TODO: add the other cases for  "e" and "x"
}
void wrongInputCategoryScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
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
	backToMainMenu(awardFunctionCall, allQuestions);
}

void backToMainMenu(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
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

void awardScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
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
		WinnerScreen(awardFunctionCall, allQuestions);
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
void defeatScreen1_2(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	cout << endl;
	centerText1("Press any key to go back to the main menu...");
	cout << endl;
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions);
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
void WinnerScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
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
		backToMainMenu(awardFunctionCall, allQuestions);
}
void FirstStage(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	

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

			history1(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history2(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history3(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history4(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history5(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history6(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history7(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history8(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history9(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			history10(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
		}
			break;
		case '2': //same applies for the cases below:
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			geography1(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography2(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography3(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography4(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography5(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography6(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography7(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography8(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography9(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			geography10(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
		}
			break;
		case '3':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			science1(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science2(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science3(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science4(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science5(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science6(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science7(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science8(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science9(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			science10(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
		}
			break;
		case '4':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			literature1(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature2(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature3(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature4(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature5(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature6(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature7(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature8(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature9(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			literature10(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
		}
			break;
		case '5':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			funFacts1(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts2(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts3(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts4(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts5(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts6(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts7(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts8(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts9(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			funFacts10(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
		}
			break;
		case '6':
		{
			srand(time(NULL));

			int start = 0;
			int randIndex = 0;

			topicMix1(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix2(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix3(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix4(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix5(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix6(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix7(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix8(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix9(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
			topicMix10(allQuestions, start, randIndex, awardFunctionCall, allQuestions);
		}
			break;
		default: 
		{
			wrongInputCategoryScreen(awardFunctionCall, allQuestions);
		}
	}
}

void playQuestion(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions)
// TODO: perhaps divide to smaller functions later
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
		awardScreen(awardFunctionCall, allQuestions);
	}
	else if (chooseAns[0] == 'X' || chooseAns[0] == 'x' && useFifty_Fifty == 0)
	{
		switch (awardTimes)
		{
			case 0:
			{
				Ques1LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
				break;
			case 1:
			{
				Ques2LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
				break;
			case 2:
			{
				Ques3LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
				break;
			case 3: 
			{
				Ques4LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
				break;
			case 4:
			{
				Ques5LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
			break;
			case 5:
			{
				Ques6LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
				break;
			case 6:
			{
				Ques7LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
				break;
			case 7:
			{
				Ques8LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
				break;
			case 8:
			{
				Ques9LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
				++useFifty_Fifty;
			}
			break;
				case 9:
			{
				Ques10LifelineFifty_Fifty(start, awardTimes, awardFunctionCall, allQuestions);
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
				Ques1LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 1:
			{
				Ques2LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 2:
			{
				Ques3LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 3:
			{
				Ques4LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 4:
			{
				Ques5LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 5:
			{
				Ques6LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 6:
			{
				Ques7LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 7:
			{
				Ques8LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 8:
			{
				Ques9LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
				++useCall_A_Friend;
			}
				break;
			case 9:
			{
				Ques9LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall, allQuestions);
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
				Ques1LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 1:
			{
				Ques2LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 2:
			{
				Ques3LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 3:
			{
				Ques4LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 4:
			{
				Ques5LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 5:
			{
				Ques6LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 6:
			{
				Ques7LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 7:
			{
				Ques8LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 8:
			{
				Ques9LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
				++useAsk_The_Audience;
			}
				break;
			case 9:
			{
				Ques10LifelineAsk_The_Audience(start, awardTimes, awardFunctionCall, allQuestions);
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
		defeatScreen1_2(awardFunctionCall, allQuestions);
	}
}

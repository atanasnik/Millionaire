#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
#include "InputQuestions.h"
#include "EditMode.h"




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
		case 3: option = "Press \"Q\" to quit the game.";
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
	clear();
	space2();
	border();
	categories();
	border();
	space2();
}

void SearchQuesLevel1(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	ifstream file;					// Looks for questions in the mentioned text file
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
	string optionPick;
	cin >> optionPick;

	switch (optionPick[0])
	{
		case 'N': case 'n':
		{
			FirstStage(awardFunctionCall, allQuestions); // Leads to the game mode
		}
			break;
		case 'C': case 'c':
		{
			inputQuesScreen(awardFunctionCall, allQuestions); // Leads to the create mode
		}
			break;
		case 'E': case 'e':
		{
			editModeIntro(awardFunctionCall, allQuestions);		// Leads to the edit mode
		}
			break;
		case 'Q': case 'q':
		{
			exit(0);		// Terminates the program immediately, if the user wants to quit
		}
		break;
		default: 
		{
			wrongInputMainMenu(awardFunctionCall, allQuestions);	// Lets the user pick a valid option
		}
	}
}
void wrongInputMainMenu(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	clear();		// If an invalid symbol has been picked, shows this screen, which is a transition to the main menu
	space1();
	border();
	space2();
	centerText1("You didn't pick an option!");
	cout << endl;
	centerText1("Press any key to try again...");
	space2();
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions);
}
void wrongInputCategoryScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	clear();	// Again, a transition to the main menu, in case invalid category is picked
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
			clear();	
			primaryScreen();			// next screen, in this case, the Main menu.
			optionSelect(awardFunctionCall);
			break;
		}
	}
}


void awardScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	++awardFunctionCall;	// Depending on what the value of the static variable is, we increment the award
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
	clear();
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
	if (awardFunctionCall == 10) // In case the user has won the game
	{
		WinnerScreen(awardFunctionCall, allQuestions);
	}
}
void defeatScreen1_1()
{
	clear();	// Gets printed if the user has chosen a wrong answer while playing
	space1();
	border();
	space2();
	centerText1("Wrong answer!");
	cout << endl;
	centerText1("The right answer was ");
}
void defeatScreen1_2(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	cout << endl;	// A transition to the main menu
	centerText1("Press any key to go back to the main menu...");
	cout << endl;
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions);
}
void nextQuesionScreen()
{
	char press;
	while (true)	// Lets the user move to the next question
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
		nextQuesionScreen();	// This screen shows at the end of the game
		clear();				// also is a transition to the main menu
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
			// Below we get the question corresponding to the topic and the level
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
		{	// Wrong input case - brings the user to the main menu through a transition
			wrongInputCategoryScreen(awardFunctionCall, allQuestions);
		}
	}
}

void readQuestionAndAnswer(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes)
{
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
	answerToQuestionStandart(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter);
}
void answerToQuestionStandart(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes, string& ansLetter)
{
	// If a lifeline has been used once in a game, it cannot be used again
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
	else if (chooseAns[0] == 'X' || chooseAns[0] == 'x' && useFifty_Fifty == 0) // The 50/50 lifeline
	{
		LifelineFifty_Fifty(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
		++useFifty_Fifty;
	}
	else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' && useCall_A_Friend == 0) // The "Phone a friend" lifeline
	{
		LifelinePhone_A_Friend(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
		++useCall_A_Friend;
		
	}
	else if (chooseAns[0] == 'Z' || chooseAns[0] == 'z' && useAsk_The_Audience == 0) // The "Ask the audience" lifeline
	{
		LifelineAsk_The_Audience(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
		++useAsk_The_Audience;
		
	}
	else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
	{
		awardFunctionCall = 0;	// Making our static variables equal to 0 means we restart the game
		useCall_A_Friend = 0;
		useAsk_The_Audience = 0;
		useFifty_Fifty = 0;
		awardTimes = 0;
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2(awardFunctionCall, allQuestions);
	}
}
void playQuestion(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	static unsigned int awardTimes = 0; // Just like the awardFunctionCall variable, we use it to tell what the game progress is
	static unsigned int useFifty_Fifty = 0; // This one and the other two below tell if the lifelines have been used
	static unsigned int useCall_A_Friend = 0;
	static unsigned int useAsk_The_Audience = 0;
	clear();
	space2();
	border();
	space2();
	// Printing the question
	readQuestionAndAnswer(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void readQuestion(ifstream& file, int start, static unsigned int& awardFunctionCall, vector<int>& allQuestions, static unsigned int& useFifty_Fifty, static unsigned int& useCall_A_Friend, static unsigned int& useAsk_The_Audience, static unsigned int& awardTimes)
{
	// This function finds the question int the file and reads it
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
}
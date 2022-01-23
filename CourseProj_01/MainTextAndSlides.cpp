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

void SearchQuesInFiles(int& awardFunctionCall, vector<int>& allQuestions)
{
	const int LEVELS = 10;
	for (int i = 1; i < LEVELS + 1; ++i)
	{
		ifstream file;
		string fileName = "Level";				// Looks for questions in the given text file
		fileName += to_string(i);
		fileName += ".txt";
		file.open(fileName);
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
}
void findQuestions(int& awardFunctionCall, vector<int>& allQuestions, ifstream& file)
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


void optionSelect(int& awardFunctionCall, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	vector<int> allQuestions;
	SearchQuesInFiles(awardFunctionCall, allQuestions);
	
	sortVector(allQuestions);
	
	string optionPick;
	cin >> optionPick;

	switch (optionPick[0])
	{
		case 'N': case 'n':
		{
			FirstStage(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes); // Leads to the game mode
		}
			break;
		case 'C': case 'c':
		{
			inputQuesScreen(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes); // Leads to the create mode
		}
			break;
		case 'E': case 'e':
		{
			editModeIntro(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);		// Leads to the edit mode
		}
			break;
		case 'Q': case 'q':
		{
			exit(0);		// Terminates the program immediately, if the user wants to quit
		}
		break;
		default: 
		{
			wrongInputMainMenu(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);	// Lets the user pick a valid option
		}
	}
}
void wrongInputMainMenu(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	clear();		// If an invalid symbol has been picked, shows this screen, which is a transition to the main menu
	space1();
	border();
	space2();
	centerText1("You didn't pick an option!");
	cout << endl;
	centerText1("Press \"R\" to retry");
	space2();
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void wrongInputCategoryScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	clear();	// Again, a transition to the main menu, in case invalid category is picked
	space1();
	border();
	space2();
	centerText1("You didn't pick a category!");
	cout << endl;
	centerText1("Press \"R\" to return to the main menu...");
	space2();
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

void backToMainMenu(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	char press;

	while (true)
	{
		cin >> press;
		if (press == 'r' || press == 'R')
		{
			break;
		}
		indentLeft("You need to press \"R\":");
	}
	clear();
	primaryScreen();			// next screen, in this case, the Main menu.
	optionSelect(awardFunctionCall, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}


void awardScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
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
	centerText1("Press \"P\" to proceed...");
	space2();
	border();
	space1();
	if (awardFunctionCall == 10) // In case the user has won the game
	{
		WinnerScreen(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
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
void defeatScreen1_2(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	cout << endl;	// A transition to the main menu
	centerText1("Press \"R\" to go back to the main menu...");
	cout << endl;
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void nextQuesionScreen()
{
	char press;

	while (true)
	{
		cin >> press;
		if (press == 'P' || press == 'p')
		{
			break;
		}
		indentLeft("You need to press \"P\":");
	}
}
void WinnerScreen(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	awardFunctionCall = 0;	// Restarting the game
	useCall_A_Friend = 0;
	useAsk_The_Audience = 0;
	useFifty_Fifty = 0;
	awardTimes = 0;

	nextQuesionScreen();	// This screen shows at the end of the game
	clear();				// also is a transition to the main menu
	space1();
	border();
	space2();
	centerText1("Good job!");
	centerText1("You won the game!");
	centerText1("Press \"R\" to go back to main menu...");
	cout << endl;
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void FirstStage(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	categoriesMenu();
	const int LEVELS = 10;
	char categoryPick;
	cin >> categoryPick; 

	if (categoryPick >= '1' && categoryPick <= '6')
	{
		srand(time(NULL)); // Using the stdlib.h and the time.h libraries, we pick a random element from an array by its index

		int start = 0;
		int randIndex = 0;
		// Below we get the question corresponding to the topic and the level
		for (int i = 1; i < LEVELS + 1; ++i)
		{

			if (i > 1)
			{
				nextQuesionScreen();
			}

			Category(start, randIndex, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, categoryPick);
			++awardTimes;
			awardScreen(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
		}
	}
	else
	{	// Wrong input case - brings the user to the main menu through a transition
		wrongInputCategoryScreen(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
		
}

void readQuestionAndAnswer(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
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
			for (int i = ans; row[size_t(i) + 1] != '\0'; ++i)
			{
				if (row[i] == ' ' && row[size_t(i) + 1] == ' ' || row[i] == '\t')
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
void answerToQuestionStandart(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience,int& awardTimes, string& ansLetter)
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
		return;
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
		awardFunctionCall = 0;	// Making our variables equal to 0 means we restart the game
		useCall_A_Friend = 0;
		useAsk_The_Audience = 0;
		useFifty_Fifty = 0;
		awardTimes = 0;
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
}
void playQuestion(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	clear();
	space2();
	border();
	space2();
	// Printing the question
	readQuestionAndAnswer(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void readQuestion(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
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
			for (int i = ans; row[size_t(i) + 1] != '\0'; ++i)
			{
				if (row[i] == ' ' && row[size_t(i) + 1] == ' ' || row[i] == '\t')
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
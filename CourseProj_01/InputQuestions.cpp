#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
#include "InputQuestions.h"

int numLength(int num) // Finds the length of a number (the number of digits)
{
	int result = 1;
	while (num > 9)
	{
		num /= 10;
		++result;
	}
	return result;
}

// These functions let the user try again, if the input is wrong
void backToInputQuesScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			clear();
			inputQuesScreen(awardFunctionCall, allQuestions);
		}
	}
}
void backToInputAnsScreen(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			clear();
			inputAnsScreen(awardFunctionCall, inpQuestion, allQuestions);
		}
	}
}
void backToChooseCorrect(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			clear();
			chooseCorrect(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
}
void backToChooseLevel(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			clear();
			chooseLevel(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
}
void backToChooseCategory(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			clear();
			chooseCategory(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNum, makeID);
		}
	}
}

void inputQuesScreen(static unsigned int& awardFunctionCall, vector<int>& allQuestions)
{
	// This function lets the user type in their suggested question
	clear();
	space2();
	border();
	space2();
	centerText1("Type in the question: ");
	space2();
	border();
	space2();
	indentLeft("Question: ");
	string inpQuestion;
	cin.ignore();            // We use cin.ignore() in order to skip the necessary whitespace
	getline(cin, inpQuestion);
	const int SIZE_QUES = 70;
	if (inpQuestion.length() <= SIZE_QUES) //If the question has 70 characters or less, it's extracted.
	{
		inputAnsScreen(awardFunctionCall, inpQuestion, allQuestions);

	}
	else
	{
		centerText1("This question is too long. Please try typing in a shorter one.");
		centerText1("Press any button for another try...");
		backToInputQuesScreen(awardFunctionCall, allQuestions);
	}
}
void inputAnsScreen(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions)
{
	// Lets the user choose possible answers
	clear();
	space2();
	border();
	space2();
	cout << endl;
	centerText1("Type in the possible answers: ");
	space2();
	border();
	space2();

	string ansA, ansB, ansC, ansD;
	indentLeft("A): ");
	getline(cin, ansA);
	cout << endl;

	indentLeft("B): ");
	getline(cin, ansB);
	cout << endl;
	
	indentLeft("C): ");
	getline(cin, ansC);
	cout << endl;
	
	indentLeft("D): ");
	getline(cin, ansD);

	const int ANS_SIZE = 32;			// The answers are valid if they are less than 32 characters
	if (ansA.length() <= ANS_SIZE ||
		ansB.length() <= ANS_SIZE ||
		ansC.length() <= ANS_SIZE ||
		ansD.length() <= ANS_SIZE)
	{
		formatAnswers1(awardFunctionCall, ansA, ansB, ansC, ansD,allQuestions);
		chooseCorrect(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
	}
	else
	{
		centerText1("Some of the answers might be too long. Please try typing in shorter ones.");
		centerText1("Press any button for another try...");
		backToInputAnsScreen(awardFunctionCall, inpQuestion, allQuestions);
	}
}
void formatQuestion(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions, int& makeID)
{
	// Here we genarate our unique serial number and attach it to the question
	makeID += 1; // We add 1 to the number, because we don't want it to end with 00
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (makeID == allQuestions[i]) // We check if there is such number in the array that contains all
									   // serial numbers, and, if so, we increment our number until there is no coincidence
		{
			++makeID;
		}
	}
	int sizeID = numLength(makeID);
	inpQuestion.insert(0, 1, ' ');     // We add the serial number to the question
	int temp = makeID;
	for (int i = 0; i < sizeID; ++i)
	{
	inpQuestion.insert(0, 1, temp % 10 + '0');
	temp /= 10;
	}
}
void formatAnswers1(static unsigned int& awardFunctionCall, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	ansA.insert(0, 1, ' ');		// Here we put A) /B) /C) /D) in front of every answer 
	ansA.insert(0, 1, ')');
	ansA.insert(0, 1, 'A');

	ansB.insert(0, 1, ' ');
	ansB.insert(0, 1, ')');
	ansB.insert(0, 1, 'B');

	ansC.insert(0, 1, ' ');
	ansC.insert(0, 1, ')');
	ansC.insert(0, 1, 'C');
	ansC += "  ";

	ansD.insert(0, 1, ' ');
	ansD.insert(0, 1, ')');
	ansD.insert(0, 1, 'D');
	ansD += '\t';
}
void formatAnswers2(static unsigned int& awardFunctionCall, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	// Formatting the text according to our text formatting algorithm
	if (ansA.length() == ansB.length())	// We add four space bars of length between A) and C), also between B) and D),
	{									// because they will share rows
		ansA += "    ";
		ansB += "    ";
	}
	else if (ansA.length() > ansB.length())
	{
		int difference = ansA.length() - ansB.length();
		ansA += "    ";					// We make sure in every case the spaces are aligned
		ansB += "    ";
		while (difference > 0)
		{
			ansB += " ";
			--difference;
		}
	}
	else
	{
		int difference = ansB.length() - ansA.length();
		ansA += "    ";
		ansB += "    ";
		while (difference > 0)
		{
			ansA += " ";
			--difference;
		}
	}
}
void chooseCorrect(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	// Lets the user choose the answer that is going to be correct
	formatAnswers2(awardFunctionCall, ansA, ansB, ansC, ansD, allQuestions);
	clear();
	space1();
	border();
	space2();
	cout << endl;
	centerText1("Now choose the correct answer");
	centerText1("Press the corresponding key (A, B, C or D): ");
	space2();
	border();
	space2();
	string pick;
	cin >> pick;
	switch (pick[0])			// We add our $$ identfier in front of the right answer
	{
		case 'A': case 'a':
		{
			ansA.insert(2, 2, '$');
		}						
			break;
		case 'B': case 'b':
		{
			ansB.insert(2, 2, '$');
		}
			break;
		case 'C': case 'c':
		{
			ansC.insert(2, 2, '$');
		}
			break;
		case 'D': case 'd':
		{
			ansD.insert(2, 2, '$');
		}
			break;
		default:
		{
			centerText1("You've entered an invalid symbol.");
			centerText1("Press any button for another try...");
			backToChooseCorrect(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
	chooseLevel(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
}
void chooseLevel(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	// Lets the user pick a level of difficulty (1-10)
	clear();
	space1();
	border();
	space2();
	cout << endl;
	centerText1("Choose the level of difficulty.");
	centerText1("Press the corresponding key (1-10): ");
	space2();
	border();
	space2();
	string level;
	int levelNum = 0;
	cin >> level;
	switch (level[0])
	{
		case '1': 
		{
			levelNum = 1;
			if (level[1] == '0') // That covers case "10"
			{
				levelNum = 10;
			}
		}
			break;
		case '2':
		{
			levelNum = 2;
		}
			break; 
		case '3':
		{
			levelNum = 3;
		}
			break;
		case '4':
		{
			levelNum = 4;
		}
			break;
		case '5':
		{
			levelNum = 5;
		}
			break;
		case '6':
		{
			levelNum = 6;
		}
			break;
		case '7':
		{
			levelNum = 7;
		}
			break;
		case '8':
		{
			levelNum = 8;
		}
			break;
		case '9':
		{
			levelNum = 9;
		}
			break;
		default:
		{
			centerText1("You've entered an invalid number.");
			centerText1("Press any button for another try...");
			backToChooseLevel(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
	int makeID = 0;
	const int LEVEL_IDENTITY = 1000;
	makeID = levelNum * LEVEL_IDENTITY;
	chooseCategory(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNum, makeID);
}
void chooseCategory(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID)
{
	// Lets the user choose the category for the question
	clear();
	space2();
	border();
	space2();
	centerText1("Choose the category (History, Geography, Science, Literature, Fun facts).");
	centerText1("Type in the first letter of the chosen category (H, G, S, L ,F): ");
	space2();
	border();
	space2();
	const int CATEGORY_IDENTITY = 100;
	string category;
	cin >> category;
	switch (category[0])
	{
		case 'H': case'h': 
		{
			makeID += 1 * CATEGORY_IDENTITY;
		}
			break;
		case 'G': case'g':
		{
			makeID += 2 * CATEGORY_IDENTITY;
		}
			break;
		case 'S': case's':
		{
			makeID += 3 * CATEGORY_IDENTITY;
		}
			break;
		case 'L': case'l':
		{
			makeID += 4 * CATEGORY_IDENTITY;
		}
			break;
		case 'F': case'f':
		{
			makeID += 5 * CATEGORY_IDENTITY;
		}
			break;
		default:
		{
			centerText1("You've entered an invalid category sign.");
			centerText1("Press any button for another try...");
			backToChooseCategory(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNum, makeID);
		}
	}
	formatQuestion(awardFunctionCall,inpQuestion, allQuestions, makeID);
	addToFile(awardFunctionCall,inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNum, makeID);
	addedQuesMessageScreen(awardFunctionCall, inpQuestion, allQuestions, makeID);
}
void addToFile(static unsigned int& awardFunctionCall, string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID)
{
	// Adds the question to the corresponding text file
	ansA += ansC;
	ansB += ansD;
	ofstream file;
	switch (levelNum)  // Here we open the corresponding file for the chosen level...
		{
		case 1:
		{
			file.open("Level1.txt", ofstream::app);
		}
			break;
		case 2:
		{
			file.open("Level2.txt", ofstream::app);
		}
			break;
		case 3:
		{
			file.open("Level3.txt", ofstream::app);
		}
			break;
		case 4:
		{
			file.open("Level4.txt", ofstream::app);
		}
			break;
		case 5:
		{
			file.open("Level5.txt", ofstream::app);
		}
			break;
		case 6:
		{
			file.open("Level6.txt", ofstream::app);
		}
			break;
		case 7:
		{
			file.open("Level7.txt", ofstream::app);
		}
			break;
		case 8:
		{
			file.open("Level8.txt", ofstream::app);
		}
			break;
		case 9:
		{
			file.open("Level9.txt", ofstream::app);
		}
			break;
		case 10:
		{
			file.open("Level10.txt", ofstream::app);
		}
			break;
	}
	if (!file.is_open())
	{
		centerText1("A mistake occured.");
	}
	file << "\n";					// ...And we add the question and its answers to the file
	file << inpQuestion;
	file << "\n";
	file << "\n";
	file << ansA;
	file << "\n";
	file << ansB;
	if (file.is_open())
	{
		file.close();
	}
}
void addedQuesMessageScreen(static unsigned int& awardFunctionCall, string& inpQuestion, vector<int>& allQuestions, int& makeID)
{
	// Informs the user their question has been added successfully
	clear();
	space1();
	border();
	space2();
	cout << endl;
	centerText1("Your question has been added successfully:");
	centerText1NoEndline("Unique question number: ");
	cout << makeID << endl;
	centerText1("Press any key to go back to main menu...");
	space2();
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions);
}
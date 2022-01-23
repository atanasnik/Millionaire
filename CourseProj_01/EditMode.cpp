#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
#include "InputQuestions.h"
#include "EditMode.h"

void editModeIntro(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// This slide includes a brief explaination about how serial numbers work
	// and how to enter a valid serial number depending on what kind of question we are looking for
	// Then, the user can type in the number they wish to check
	string forHistoryText = "1 - For History";
	double alignSetter = forHistoryText.length() - 1;
	clear();
	cout << endl;
	border();
	cout << endl;
	centerText1("A question's unique number is formed like so:");
	centerText1("The first digit/s should represent the level of difficulty (1 - 10)");
	centerText1("The number of the topic is the next digit:");
	centerText1(forHistoryText);
	centerText3("2 - For Geography", alignSetter);
	centerText3("3 - For Science", alignSetter);
	centerText3("4 - For Literature", alignSetter);
	centerText3("5 - For Fun facts", alignSetter);
	centerText1("Most questions currently end with 01 and 02");
	centerText1("Examples: 7402, 10201");
	border();
	space2();
	indentLeft("Type the number of the question you want to edit here: ");
	string inputID;
	cin >> inputID;
	cout << endl;
	const int MAX_ID_SIZE = 5;
	if (inputID.length() > MAX_ID_SIZE)
	{
		centerText1("There is no such number, make sure you've read the instructions above.");
		centerText1("Press \"T\" to try again...");
		backToEditModeIntro(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
	for (int i = 0; inputID[i] != '\0'; ++i)
	{
		if (inputID[i] < '0' || inputID[i] > '9')
		{
			centerText1("There is no such number, it should only include digits");
			centerText1("Press \"T\" to try again...");
			backToEditModeIntro(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			break;
		}
	}
	if (quesExists(awardFunctionCall, allQuestions, inputID, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes))
	{
		editModeScreen(awardFunctionCall, allQuestions, inputID, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
	else
	{
		centerText1("A question with such number does not currently exist.");
		centerText1("Press \"T\" to try again...");
		backToEditModeIntro(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
}
void backToEditModeIntro(int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// If the user has chosen an invalid number, they are given another chance to type in a valid one
	char press;

	while (true)
	{
		cin >> press;
		if (press == 't' || press == 'T')
		{
			break;
		}
		indentLeft("You need to press \"T\":");
	}
	clear();
	editModeIntro(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void editModeScreen(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// Adds the necessary space after the presented question
	clear();
	cout << endl;
	border();
	cout << endl;
	readQues(inputID);
	copyFile(inputID);
	cout << endl;
	border();
	cout << endl;
	centerText1("Rewrite the question and the answers as desired: ");
	replaceQues(awardFunctionCall, allQuestions, inputID, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);

}
bool quesExists(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// Checks if there is a question with such number
	int temp = stoi(inputID, nullptr);
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (temp == allQuestions[i])
		{
			return true;
		}
	}
	return false;
}
void readQues(string& inputID)
{
	// Reads the question from the file
	ifstream file;
	switch (inputID[0])
	{
		case '1':
		{
			if (inputID[1] == '0' && inputID.length() == 5) // That covers case "10"
			{
				file.open("Level10.txt");
			}
			else if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level1.txt");
			}
		}
			break;
		case '2':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level2.txt");
			}
		}
			break;
		case '3':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level3.txt");
			}
		}
			break;
		case '4':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level4.txt");
			}
		}
			break;
		case '5':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level5.txt");
			}
		}
			break;
		case '6':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level6.txt");
			}
		}
			break;
		case '7':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level17txt");
			}
		}
			break;
		case '8':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level8.txt");
			}
		}
			break;
		case '9':
		{
			if (inputID[1] != '0' && inputID.length() == 4)
			{
				file.open("Level9.txt");
			}
		}
			break;
		}
	if (!file.is_open())
	{
		centerText1("A mistake occured.");
	}

	string row;
	string correct = "$$";
	string ansLetter;
	int countLen = 0;

	while (getline(file, row))
	{
		size_t location = row.find(inputID);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, inputID.length());

	indentLeft("Question: ");
	cout << row << endl;

	while (getline(file, row))
	{
		for (int i = 0; row[i] != '\0'; ++i)
		{
			if (row[i] == '\t')
			{
				file.close();
			}
		}
		size_t ans = row.find(correct);
		if (ans != string::npos)
		{
			row.erase(ans, correct.length());
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
		indentLeft(row);
		cout << endl;
	}
	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	indentLeft("The correct answer currently is: ");
	cout << ansLetter;
}
void copyFile(string& inputID)
{
	// Makes a copy of the file which will exclude the old version of the question, and then the new one will be added
	ifstream file;
	switch (inputID[0])
	{
	case '1':
	{
		if (inputID[1] == '0' && inputID.length() == 5) 
		{
			file.open("Level10.txt");
		}
		else if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level1.txt");
		}
	}
	break;
	case '2':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level2.txt");
		}
	}
	break;
	case '3':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level3.txt");
		}
	}
	break;
	case '4':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level4.txt");
		}
	}
	break;
	case '5':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level5.txt");
		}
	}
	break;
	case '6':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level6.txt");
		}
	}
	break;
	case '7':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level17txt");
		}
	}
	break;
	case '8':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level8.txt");
		}
	}
	break;
	case '9':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			file.open("Level9.txt");
		}
	}
	break;
	}
	if (!file.is_open())
	{
		centerText1("A mistake occured.");
	}

	ofstream copy("copy.txt");
	string row;

	while (getline(file, row))
	{
		size_t location = row.find(inputID);
		if (location != string::npos)
		{
			break;
		}
		copy << row << endl;
	}
	
	bool stopLoop = false;
	while (getline(file, row), !stopLoop)
	{
		for (int i = 0; row[i] != '\0'; ++i)
		{
			if (row[i] == '\t')
			{
				stopLoop = true;
			}
		}
	}
	while (getline(file, row))
	{
		copy << row << endl;
	}
	if (file.is_open())
	{
		file.close();
	}
	if (copy.is_open())
	{
		copy.close();
	}
	switch (inputID[0])
	{
	case '1':
	{
		if (inputID[1] == '0' && inputID.length() == 5) 
		{
			remove("Level10.txt");
			if (rename("copy.txt", "Level10.txt"))
			{
				indentLeft("There was a file error");
			}
		}
		else if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level1.txt");
			if (rename("copy.txt", "Level1.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '2':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level2.txt");
			if (rename("copy.txt", "Level2.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '3':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level3.txt");
			if (rename("copy.txt", "Level3.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '4':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level4.txt");
			if (rename("copy.txt", "Level4.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '5':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level5.txt");
			if (rename("copy.txt", "Level5.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '6':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level6.txt");
			if (rename("copy.txt", "Level6.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '7':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level7.txt");
			if (rename("copy.txt", "Level7.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '8':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level8.txt");
			if (rename("copy.txt", "Level8.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	case '9':
	{
		if (inputID[1] != '0' && inputID.length() == 4)
		{
			remove("Level9.txt");
			if (rename("copy.txt", "Level9.txt"))
			{
				indentLeft("There was a file error");
			}
		}
	}
	break;
	}
}
void replaceQues(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// Lets the user rewrite the question
	string inpQuestion;
	indentLeft("Question: ");
	cin.ignore();
	while (true)
	{
		getline(cin, inpQuestion);
		if (inpQuestion.length() > 0)
		{
			break;
		}
	}
	
	replaceAns(awardFunctionCall, allQuestions, inputID, inpQuestion, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void replaceAns(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& inpQuestion, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// Lets the user change the answers
	string ansA, ansB, ansC, ansD;
	cout << endl;

	indentLeft("A): ");
	while (true)
	{
		getline(cin, ansA);
		if (ansA.length() > 0)
		{
			break;
		}
		indentLeft("Try again: ");
	}

	indentLeft("B): ");
	while (true)
	{
		getline(cin, ansB);
		if (ansB.length() > 0)
		{
			break;
		}
		indentLeft("Try again: ");
	}

	indentLeft("C): ");
	while (true)
	{
		getline(cin, ansC);
		if (ansC.length() > 0)
		{
			break;
		}
		indentLeft("Try again: ");
	}

	indentLeft("D): ");
	while (true)
	{
		getline(cin, ansD);
		if (ansD.length() > 0)
		{
			break;
		}
		indentLeft("Try again: ");
	}

	formatAnswers1(ansA, ansB, ansC, ansD, allQuestions);
	replaceCorrectAns(awardFunctionCall, allQuestions, inputID, ansA, ansB, ansC, ansD, inpQuestion, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void replaceCorrectAns(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& ansA, string& ansB, string& ansC, string& ansD, string& inpQuestion, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// Lets the user change the correct answer
	formatAnswers2(ansA, ansB, ansC, ansD, allQuestions);
	centerText1("New correct answer (A, B, C or D):");
	string pick;
	while (true)
	{
		cin >> pick;
		if (pick[0] == 'A' || pick[0] == 'a' ||
			pick[0] == 'B' || pick[0] == 'b' ||
			pick[0] == 'C' || pick[0] == 'c' ||
			pick[0] == 'D' || pick[0] == 'd')
		{
			break;
		}
		indentLeft("Try again: ");
	}
	switch (pick[0])
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
	}
	addNumToQues(awardFunctionCall, allQuestions, inputID, ansA, ansB, ansC, ansD, inpQuestion, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void addNumToQues(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, string& ansA, string& ansB, string& ansC, string& ansD, string& inpQuestion, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	int makeID = stoi(inputID, nullptr);
	int sizeID = numLength(makeID);
	inpQuestion.insert(0, 1, ' ');		// We add the same serial number to the question
	int temp = makeID;
	for (int i = 0; i < sizeID; ++i)
	{
		inpQuestion.insert(0, 1, temp % 10 + '0');
		temp /= 10;
	}
	int levelNumber = makeID / 1000;
	addToFile(awardFunctionCall, inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNumber, makeID, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	editSuccessfulMessage(awardFunctionCall, allQuestions, inputID, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void editSuccessfulMessage(int& awardFunctionCall, vector<int>& allQuestions, string& inputID, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	clear();
	space1();
	border();
	space2();
	cout << endl;
	centerText1("This question has been changed successfully!");
	centerText1("Press \"R\" to return to main menu...");
	space2();
	border();
	space1();
	backToMainMenu(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

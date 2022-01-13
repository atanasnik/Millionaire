#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
#include "InputQuestions.h"

void backToInputQuesScreen(vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			system("CLS");
			inputQuesScreen(allQuestions);
		}
	}
}
void backToInputAnsScreen(string& inpQuestion, vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			system("CLS");
			inputAnsScreen(inpQuestion, allQuestions);
		}
	}
}
void backToChooseCorrect(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			system("CLS");
			chooseCorrect(inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
}
void backToChooseLevel(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			system("CLS");
			chooseLevel(inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
}
void backToChooseCategory(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID)
{
	char press;
	while (true)
	{
		if (_kbhit())
		{
			press = _getch();
			system("CLS");
			chooseCategory(inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNum, makeID);
		}
	}
}
void inputQuesScreen(vector<int>& allQuestions)
{
	system("CLS");
	space2();
	border();
	space2();
	centerText1("Type in the question: ");
	space2();
	border();
	space2();
	string inpQuestion;
	cin >> inpQuestion;
	const int SIZE_QUES = 70;
	if (inpQuestion.length() <= SIZE_QUES)
	{
		inputAnsScreen(inpQuestion, allQuestions);

	}
	else
	{
		centerText1("This question is too long. Please try typing in a shorter one.");
		centerText1("Press any button for another try...");
		backToInputQuesScreen(allQuestions);
	}
}
void inputAnsScreen(string& inpQuestion, vector<int>& allQuestions)
{
	system("CLS");
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
	cin >> ansA;
	cout << endl;
	/*ansA.insert(0, 1, ' ');
	ansA.insert(0, 1, ')');
	ansA.insert(0, 1, 'A');*/

	indentLeft("B): ");
	cin >> ansB; 
	cout << endl;
	
	indentLeft("C): ");
	cin >> ansC;
	cout << endl;
	
	indentLeft("D): ");
	cin >> ansD;

	const int ANS_SIZE = 32;
	if (ansA.length() <= ANS_SIZE ||
		ansB.length() <= ANS_SIZE ||
		ansC.length() <= ANS_SIZE ||
		ansD.length() <= ANS_SIZE)
	{
		formatAnswers(ansA, ansB, ansC, ansD,allQuestions);
		chooseCorrect(inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
	}
	else
	{
		centerText1("Some of the answers might be too long. Please try typing in shorter ones.");
		centerText1("Press any button for another try...");
		backToInputAnsScreen(inpQuestion, allQuestions);
	}
}
void formatQuestion(string& inpQuestion, vector<int>& allQuestions, int& makeID)
{
	makeID += 1;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (makeID == allQuestions[i])
		{
			++makeID;
		}
	}
	//cout << makeID;
}
void formatAnswers(string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	ansA.insert(0, 1, ' ');
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
	ansD += '/t';

	if (ansA.length() == ansB.length())
	{
		ansA += "    ";
		ansB += "    ";
	}
	else if (ansA.length() > ansB.length())
	{
		int difference = ansA.length() - ansB.length();
		ansA += "    ";
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
void chooseCorrect(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	system("CLS");
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
			ansB.insert(2, 2, '$');
		}
			break;
		default:
		{
			centerText1("You've entered an invalid symbol.");
			centerText1("Press any button for another try...");
			backToChooseCorrect(inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
	chooseLevel(inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
}
void chooseLevel(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions)
{
	system("CLS");
	space1();
	border();
	space2();
	cout << endl;
	centerText1("Choose the level of difficulty.");
	centerText1("Press the corresponding key (1-10): ");
	space2();
	border();
	space2();
	int level;
	int levelNum = 0;
	cin >> level;
	switch (level)
	{
		case 1: 
		{
				levelNum = 1;
			
		}
			break;
		case 2:
		{
			levelNum = 2;
		}
			break; 
		case 3:
		{
			levelNum = 3;
		}
			break;
		case 4:
		{
			levelNum = 4;
		}
			break;
		case 5:
		{
			levelNum = 5;
		}
			break;
		case 6:
		{
			levelNum = 6;
		}
			break;
		case 7:
		{
			levelNum = 7;
		}
			break;
		case 8:
		{
			levelNum = 8;
		}
			break;
		case 9:
		{
			levelNum = 9;
		}
			break;
		case 10:
		{
			levelNum = 10;
		}
			break;
		default:
		{
			centerText1("You've entered an invalid number."); //FAULTY
			centerText1("Press any button for another try...");
			backToChooseLevel(inpQuestion, ansA, ansB, ansC, ansD, allQuestions);
		}
	}
	int makeID = 0;
	const int LEVEL_IDENTITY = 1000;
	makeID = levelNum * LEVEL_IDENTITY;
	chooseCategory(inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNum, makeID);
}
void chooseCategory(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID)
{
	system("CLS");
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
			backToChooseCategory(inpQuestion, ansA, ansB, ansC, ansD, allQuestions, levelNum, makeID);
		}
	}
	formatQuestion(inpQuestion, allQuestions, makeID);
}

#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"

// The "Question1-10 functions are responcible for opening each level's question
void Question1(int start) 
{
	ifstream file;
	file.open("Level1.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question2(int start)
{
	ifstream file;
	file.open("Level2.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question3(int start)
{
	ifstream file;
	file.open("Level3.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question4(int start)
{
	ifstream file;
	file.open("Level4.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question5(int start)
{
	ifstream file;
	file.open("Level5.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question6(int start)
{
	ifstream file;
	file.open("Level6.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question7(int start)
{
	ifstream file;
	file.open("Level7.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question8(int start)
{
	ifstream file;
	file.open("Level8.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question9(int start)
{
	ifstream file;
	file.open("Level9.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}
void Question10(int start)
{
	ifstream file;
	file.open("Level10.txt");
	playQuestion(file, start);
	if (file.is_open())
	{
		file.close();
	}
}


// The <category>1-10 functions pick a serial number from the array which stores all numbers and then
// a random serial number is picked from each subarray of the "allQuestions" array and the question is 
// being presented
void history1(vector<int>& allQues, int start, int randIndex)
{
	vector<int> history1;

	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 11)
		{
			history1.push_back(allQues[i]);
		}
	}
	randIndex = rand() % 2; // The array stores our questions' serial numbers, so we pick a random question to present
	start = history1[randIndex];
	Question1(start);
}
void history2(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history2;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 21)
		{
			history2.push_back(allQues[i]);
		}
	}
	start = history2[randIndex];
	Question2(start);
}
void history3(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history3;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 31)
		{
			history3.push_back(allQues[i]);
		}
	}
	start = history3[randIndex];
	Question3(start);
}
void history4(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history4;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 41)
		{
			history4.push_back(allQues[i]);
		}
	}
	start = history4[randIndex];
	Question4(start);
}
void history5(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history5;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 51)
		{
			history5.push_back(allQues[i]);
		}
	}
	start = history5[randIndex];
	Question5(start);
}
void history6(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history6;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 61)
		{
			history6.push_back(allQues[i]);
		}
	}
	start = history6[randIndex];
	Question6(start);
}
void history7(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history7;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 71)
		{
			history7.push_back(allQues[i]);
		}
	}
	start = history7[randIndex];
	Question7(start);
}
void history8(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history8;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 81)
		{
			history8.push_back(allQues[i]);
		}
	}
	start = history8[randIndex];
	Question8(start);
}
void history9(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history9;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 91)
		{
			history9.push_back(allQues[i]);
		}
	}
	start = history9[randIndex];
	Question9(start);
}
void history10(vector<int>& allQues, int start, int randIndex)
{
	nextQuesionScreen();
	vector<int> history10;
	for (int i = 0; i < allQues.size(); ++i)
	{
		if (allQues[i] / 100 == 101)
		{
			history10.push_back(allQues[i]);
		}
	}
	start = history10[randIndex];
	Question10(start);
}
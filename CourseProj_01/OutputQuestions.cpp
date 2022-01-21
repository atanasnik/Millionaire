#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"

// The "Question1-10 functions are responcible for opening each level's question
void Question1(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level1.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question2(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level2.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question3(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level3.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question4(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level4.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question5(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level5.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question6(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level6.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question7(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level7.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question8(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level8.txt");
	playQuestion(file,start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question9(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level9.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}
void Question10(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	file.open("Level10.txt");
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}


// The <category>1-10 functions pick a serial number from the array which stores all numbers and then
// a random serial number is picked from each subarray of the "allQuestions" array, which is stored in
// MainTextAndSLides, and the question is being presented
void history1(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	vector<int> history1;

	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 11)
		{
			history1.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history1.size(); // The array stores our questions' serial numbers, so we pick a random question to present
	start = history1[randIndex];
	Question1(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history2(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history2;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 21)
		{
			history2.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history2.size();
	start = history2[randIndex];
	Question2(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history3(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history3;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 31)
		{
			history3.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history3.size();
	start = history3[randIndex];
	Question3(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history4(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history4;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 41)
		{
			history4.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history4.size();
	start = history4[randIndex];
	Question4(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history5(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history5;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 51)
		{
			history5.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history5.size();
	start = history5[randIndex];
	Question5(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history6(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history6;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 61)
		{
			history6.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history6.size();
	start = history6[randIndex];
	Question6(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history7(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history7;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 71)
		{
			history7.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history7.size();
	start = history7[randIndex];
	Question7(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history8(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history8;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 81)
		{
			history8.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history8.size();
	start = history8[randIndex];
	Question8(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history9(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history9;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 91)
		{
			history9.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history9.size();
	start = history9[randIndex];
	Question9(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void history10(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> history10;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 101)
		{
			history10.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % history10.size();
	start = history10[randIndex];
	Question10(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

void geography1(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	vector<int> geography1;

	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 12)
		{
			geography1.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography1.size();
	randIndex = rand() % 2;
	start = geography1[randIndex];
	Question1(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography2(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography2;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 22)
		{
			geography2.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography2.size();
	start = geography2[randIndex];
	Question2(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography3(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography3;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 32)
		{
			geography3.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography3.size();
	start = geography3[randIndex];
	Question3(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography4(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography4;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 42)
		{
			geography4.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography4.size();
	start = geography4[randIndex];
	Question4(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography5(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography5;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 52)
		{
			geography5.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography5.size();
	start = geography5[randIndex];
	Question5(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography6(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography6;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 62)
		{
			geography6.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography6.size();
	start = geography6[randIndex];
	Question6(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography7(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography7;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 72)
		{
			geography7.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography7.size();
	start = geography7[randIndex];
	Question7(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography8(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography8;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 82)
		{
			geography8.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography8.size();
	start = geography8[randIndex];
	Question8(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography9(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography9;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 92)
		{
			geography9.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography9.size();
	start = geography9[randIndex];
	Question9(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void geography10(int start, int randIndex,  int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> geography10;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 102)
		{
			geography10.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % geography10.size();
	start = geography10[randIndex];
	Question10(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

void science1(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	vector<int> science1;

	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 13)
		{
			science1.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science1.size();
	randIndex = rand() % 2;
	start = science1[randIndex];
	Question1(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science2(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science2;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 23)
		{
			science2.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science2.size();
	start = science2[randIndex];
	Question2(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science3(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science3;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 33)
		{
			science3.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science3.size();
	start = science3[randIndex];
	Question3(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science4(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science4;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 43)
		{
			science4.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science4.size();
	start = science4[randIndex];
	Question4(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science5(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science5;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 53)
		{
			science5.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science5.size();
	start = science5[randIndex];
	Question5(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science6(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science6;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 63)
		{
			science6.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science6.size();
	start = science6[randIndex];
	Question6(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science7(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science7;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 73)
		{
			science7.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science7.size();
	start = science7[randIndex];
	Question7(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science8(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science8;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 83)
		{
			science8.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science8.size();
	start = science8[randIndex];
	Question8(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science9(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science9;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 93)
		{
			science9.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science9.size();
	start = science9[randIndex];
	Question9(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void science10(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> science10;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 103)
		{
			science10.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % science10.size();
	start = science10[randIndex];
	Question10(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

void literature1(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	vector<int> literature1;

	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 14)
		{
			literature1.push_back(allQuestions[i]);
		}
	}

	randIndex = rand() % literature1.size();
	start = literature1[randIndex];
	Question1(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature2(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature2;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 24)
		{
			literature2.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature2.size();
	start = literature2[randIndex];
	Question2(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature3(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature3;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 34)
		{
			literature3.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature3.size();
	start = literature3[randIndex];
	Question3(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature4(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature4;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 44)
		{
			literature4.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature4.size();
	start = literature4[randIndex];
	Question4(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature5(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature5;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 54)
		{
			literature5.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature5.size();
	start = literature5[randIndex];
	Question5(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature6(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature6;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 64)
		{
			literature6.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature6.size();
	start = literature6[randIndex];
	Question6(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature7(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature7;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 74)
		{
			literature7.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature7.size();
	start = literature7[randIndex];
	Question7(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature8(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature8;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 84)
		{
			literature8.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature8.size();
	start = literature8[randIndex];
	Question8(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature9(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature9;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 94)
		{
			literature9.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature9.size();
	start = literature9[randIndex];
	Question9(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void literature10(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> literature10;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 104)
		{
			literature10.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % literature10.size();
	start = literature10[randIndex];
	Question10(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

void funFacts1(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	vector<int> fun1;

	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 15)
		{
			fun1.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun1.size();
	start = fun1[randIndex];
	Question1(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts2(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun2;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 25)
		{
			fun2.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun2.size();
	start = fun2[randIndex];
	Question2(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts3(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun3;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 35)
		{
			fun3.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun3.size();
	start = fun3[randIndex];
	Question3(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts4(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun4;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 45)
		{
			fun4.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun4.size();
	start = fun4[randIndex];
	Question4(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts5(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun5;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 55)
		{
			fun5.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun5.size();
	start = fun5[randIndex];
	Question5(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts6(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun6;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 65)
		{
			fun6.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun6.size();
	start = fun6[randIndex];
	Question6(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts7(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun7;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 75)
		{
			fun7.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun7.size();
	start = fun7[randIndex];
	Question7(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts8(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun8;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 85)
		{
			fun8.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun8.size();
	start = fun8[randIndex];
	Question8(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts9(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun9;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 95)
		{
			fun9.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun9.size();
	start = fun9[randIndex];
	Question9(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void funFacts10(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> fun10;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 100 == 105)
		{
			fun10.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % fun10.size();
	start = fun10[randIndex];
	Question10(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

void topicMix1(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	vector<int> mix1;

	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 1)
		{
			mix1.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix1.size();
	start = mix1[randIndex];
	Question1(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix2(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix2;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 2)
		{
			mix2.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix2.size();
	start = mix2[randIndex];
	Question2(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix3(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix3;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 3)
		{
			mix3.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix3.size();
	start = mix3[randIndex];
	Question3(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix4(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix4;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 4)
		{
			mix4.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix4.size();
	start = mix4[randIndex];
	Question4(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix5(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix5;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 5)
		{
			mix5.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix5.size();
	start = mix5[randIndex];
	Question5(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix6(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix6;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 6)
		{
			mix6.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix6.size();
	start = mix6[randIndex];
	Question6(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix7(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix7;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 7)
		{
			mix7.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix7.size();
	start = mix7[randIndex];
	Question7(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix8(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix8;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 8)
		{
			mix8.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix8.size();
	start = mix8[randIndex];
	Question8(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix9(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix9;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 9)
		{
			mix9.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix9.size();
	start = mix9[randIndex];
	Question9(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
void topicMix10(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	nextQuesionScreen();
	vector<int> mix10;
	for (int i = 0; i < allQuestions.size(); ++i)
	{
		if (allQuestions[i] == 0)
		{
			cout << "An error occured.";
		}
		if (allQuestions[i] / 1000 == 10)
		{
			mix10.push_back(allQuestions[i]);
		}
	}
	randIndex = rand() % mix10.size();
	start = mix10[randIndex];
	Question10(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}
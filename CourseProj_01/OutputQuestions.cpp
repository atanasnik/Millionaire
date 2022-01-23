/**
*
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Atanas Nikov
* @idnumber 3MI0600006
* @compiler VC
*
* <File of .cpp type that contains question extraction logic>
*
*/

#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"



// The Question function is responcible for opening each level's question
void Question(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	ifstream file;
	switch (awardTimes)
	{
	case 0:
	{
		file.open("Level1.txt");
	}
	break;
	case 1:
	{
		file.open("Level2.txt");
	}
	break;
	case 2:
	{
		file.open("Level3.txt");
	}
	break;
	case 3:
	{
		file.open("Level4.txt");
	}
	break;
	case 4:
	{
		file.open("Level5.txt");
	}
	break;
	case 5:
	{
		file.open("Level6.txt");
	}
	break;
	case 6:
	{
		file.open("Level7.txt");
	}
	break;
	case 7:
	{
		file.open("Level8.txt");
	}
	break;
	case 8:
	{
		file.open("Level9.txt");
	}
	break;
	case 9:
	{
		file.open("Level10.txt");
	}
	break;
	}
	playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	if (file.is_open())
	{
		file.close();
	}
}

// The Category function picks a serial number from the array which stores all numbers and then
// a random serial number is picked from the subarray of the "allQuestions" array, which is stored in
// MainTextAndSLides, and the question is being presented

void Category(int start, int randIndex, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, char categoryPick)
{
	int pick = categoryPick - '0';	// Here we determine what is the category the user has picked
	int numberSign = 0;				
	int denominator = 100;

	// The two variables above we are going to use in order to extract the serial numbers we need
	// from the allQuestions array. This will be done like so:
	// We divide the given serial number by the denominator and if the result is equal to numberSign,
	// then this number from the allQuestions array fulfills our criteria for the case and we extract it

	// In most cases we will divide a given number by 100. 
	// Example: If the current serial number is 1102, and numberSign is equal to 11 (first digit 
	// stands for the level of difficulty, second digits stands for category), then
	// we divide 1102 by 100. The result is 11, so our condition is met.
	switch (pick)
	{
	case 1:
	{
		numberSign = 1;
	}
	break;
	case 2:
	{
		numberSign = 2;
	}
	break;
	case 3:
	{
		numberSign = 3;
	}
	break;
	case 4:
	{
		numberSign = 4;
	}
	break;
	case 5:
	{
		numberSign = 5;
	}
	break;
	case 6:
	{
		numberSign = 1;
		denominator = 1000;
	}
	}

	vector<int> category;

	if (pick < 6)
	{
		switch (awardTimes)
		{
		case 0:
		{
			numberSign += 10;
		}
		break;
		case 1:
		{
			numberSign += 20;
		}
		break;
		case 2:
		{
			numberSign += 30;
		}
		break;
		case 3:
		{
			numberSign += 40;
		}
		break;
		case 4:
		{
			numberSign += 50;
		}
		break;
		case 5:
		{
			numberSign += 60;
		}
		break;
		case 6:
		{
			numberSign += 70;
		}
		break;
		case 7:
		{
			numberSign += 80;
		}
		break;
		case 8:
		{
			numberSign += 90;
		}
		break;
		case 9:
		{
			numberSign += 100;
		}
		break;
		}
		for (int i = 0; i < allQuestions.size(); ++i)
		{
			if (allQuestions[i] == 0)
			{
				cout << "An error occured.";
			}
			if (allQuestions[i] / denominator == numberSign)
			{
				category.push_back(allQuestions[i]);
			}
		}
	}
	else
	{
		switch (awardTimes) // case 0 is missing, bacause numberSign is already equal to 1
		{
		case 1:
		{
			numberSign = 2;
		}
		break;
		case 2:
		{
			numberSign = 3;
		}
		break;
		case 3:
		{
			numberSign = 4;
		}
		break;
		case 4:
		{
			numberSign = 5;
		}
		break;
		case 5:
		{
			numberSign = 6;
		}
		break;
		case 6:
		{
			numberSign = 7;
		}
		break;
		case 7:
		{
			numberSign = 8;
		}
		break;
		case 8:
		{
			numberSign = 9;
		}
		break;
		case 9:
		{
			numberSign = 10;
		}
		break;
		}
		for (int i = 0; i < allQuestions.size(); ++i)
		{
			if (allQuestions[i] == 0)
			{
				cout << "An error occured.";
			}
			if (allQuestions[i] / denominator == numberSign)
			{
				category.push_back(allQuestions[i]);
			}
		}
	}
	if (category.size() != 0)
	{
		randIndex = rand() % category.size(); // The array stores our questions' serial numbers, so we pick a random question to present
	}
	start = category[randIndex];
	Question(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
}

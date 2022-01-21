#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"

char audienceAnswersEasy(char ansLetter)
{
	string answers;
	switch (ansLetter)	// Here we extract the wrong answers from the question
	{
		// In these cases we will take the four events of different correct answers.
		// The "audience" we ask through lifeline has a 30% chance of being wrong, so
		// for the different cases we fill the array with right and wrong answers, where
		// out of 10 elements, 7 are correct, the other 3 are wrong, 3x1 are the same 
		// (here that means that the three are different from one another).
		// Then we pick a random element, so that's how we achieve 70% success rate.
		case 'A':
		{
			answers += {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D'};
		}
			break;
		case 'B':
		{
			answers += {'A', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'C', 'D'};
		}
			break;
		case 'C':
		{
			answers += {'A', 'B', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'D'};
		}
			break;
		case 'D':
		{
			answers += {'A', 'B', 'C', 'D', 'D', 'D', 'D', 'D', 'D', 'D'};
		}
			break;
	}
	srand(time(NULL));
	char suggestion = 0;
	int randomize = 0;
	if (answers.size() != 0)
	{
	randomize = rand() % answers.size();
	suggestion = answers[randomize];
	}
	return suggestion;
}
char audienceAnswersNormal(char ansLetter)
{
	string answers;
	switch (ansLetter)
	{
		// In these cases we will take the four events of different correct answers.
		// The "audience" we ask through lifeline has a 60% chance of being wrong, so
		// for the different cases we fill the array with right and wrong answers, where
		// out of 10 elements, 4 are correct, the other 6 are wrong, 3x2 are the same.
		// Then we pick a random element, so that's how we achieve 40% success rate.
	case 'A':
	{
		answers += {'A', 'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D'};
	}
	break;
	case 'B':
	{
		answers += {'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'D', 'D'};
	}
	break;
	case 'C':
	{
		answers += {'A', 'A', 'B', 'B', 'C', 'C', 'C', 'C', 'D', 'D'};
	}
	break;
	case 'D':
	{
		answers += {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'D', 'D'};
	}
	break;
	}
	srand(time(NULL));
	char suggestion = 0;
	int randomize = 0;
	if (answers.size() != 0)
	{
		randomize = rand() % answers.size();
		suggestion = answers[randomize];
	}
	return suggestion;
}
char audienceAnswersHard(char ansLetter)
{
	string answers;
	switch (ansLetter)
	{
		// In these cases we will take the four events of different correct answers.
		// The "audience" we ask through lifeline has an 80% chance of being wrong, so
		// for the different cases we fill the array with right and wrong answers, where
		// out of 30 elements, 6 are correct, the other 24 are wrong, 3x8 are the same.
		// Then we pick a random element, so that's how we achieve 20% success rate.
		case 'A':
		{
			answers +=
			{
				'A', 'A', 'A', 'A', 'A', 'A',
					'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
					'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
					'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'
			};
		}
		break;
		case 'B':
		{
			answers +=
			{
				'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
					'B', 'B', 'B', 'B', 'B', 'B',
					'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
					'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'
			};
		}
		break;
		case 'C':
		{
			answers +=
			{
				'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
					'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
					'C', 'C', 'C', 'C', 'C', 'C',
					'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'
			};
		}
		break;
		case 'D':
		{
			answers +=
			{
				'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
					'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
					'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
					'D', 'D', 'D', 'D', 'D', 'D'
			};
		}
		break;
		}
	srand(time(NULL));
	char suggestion = 0;
	int randomize = 0;
	if (answers.size() != 0)
	{
		randomize = rand() % answers.size();
		suggestion = answers[randomize];
	}
	return suggestion;
}
void percentages(char suggestion)
{
	char wrong1;
	char wrong2;
	char wrong3;
	// Here we create an array that stores the possible percetages of the suggested answer.
	// We take a random number (say 57) which will represent our suggested answer's percetages, then
	// From the remaining number (100 - 57 = 43) we extract the other three answers that were not 
	// suggested via randomizing.
	vector<int> percent = 
	{	50,
		51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
		61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
		71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
		81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 
	};
	srand(time(NULL));
	int correctSuggest = 0;
	int randomize = rand() % percent.size();
	correctSuggest = percent[randomize];		// Here we choose the percentage of the suggested answer, also randomly
	int secondBiggest = 0;
	int thirdBiggest = 0;
	int fourthBiggest = 0;
	int remainingProc = 100 - correctSuggest;
	const int SIZE = 50;
	vector<int> remainder1(SIZE, 0);					// Then we randomly split the remaining percents into the other three options		
	remainder1[0] = 1;
	for (int i = 1; i < remainingProc; ++i)
	{
		remainder1[i] = remainder1[i - 1] + 1;
	}
	randomize = rand() % (remainder1.size() - 3);
	secondBiggest = remainder1[randomize];

	int remainingProc2 = remainingProc - secondBiggest;
	vector<int> remainder2(SIZE, 0);
	remainder2[0] = 1;
	for (int i = 1; i < remainingProc2; ++i)
	{
		remainder2[i] = remainder2[i - 1] + 1;
	}
	randomize = rand() % (remainder2.size() - 3); 
	thirdBiggest = remainder2[randomize];

	fourthBiggest = remainingProc2 - thirdBiggest;

	// Here we define which are the exact wrong answers:
	string wrongs;
	switch (suggestion)
	{
	case 'A':
	{
		wrongs = { 'B', 'C', 'D' };
		randomize = rand() % wrongs.length();
		wrong1 = wrongs[randomize];

		
		if (wrong1 == wrongs[0])
		{
			wrong2 = wrongs[1];
			wrong3 = wrongs[2];
		}
		else if (wrong1 == wrongs[1])
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[2];
		}
		else
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[1];
		}
	}
	break;
	case 'B':
	{
		wrongs = { 'A', 'C', 'D' };
		randomize = rand() % wrongs.length();
		wrong1 = wrongs[randomize];


		if (wrong1 == wrongs[0])
		{
			wrong2 = wrongs[1];
			wrong3 = wrongs[2];
		}
		else if (wrong1 == wrongs[1])
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[2];
		}
		else
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[1];
		}
	}
	break;
	case 'C':
	{
		wrongs = { 'A', 'B', 'D' };
		randomize = rand() % wrongs.length();
		wrong1 = wrongs[randomize];


		if (wrong1 == wrongs[0])
		{
			wrong2 = wrongs[1];
			wrong3 = wrongs[2];
		}
		else if (wrong1 == wrongs[1])
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[2];
		}
		else
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[1];
		}
	}
	break;
	case 'D':
	{
		wrongs = { 'A', 'B', 'C' };
		randomize = rand() % wrongs.length();
		wrong1 = wrongs[randomize];


		if (wrong1 == wrongs[0])
		{
			wrong2 = wrongs[1];
			wrong3 = wrongs[2];
		}
		else if (wrong1 == wrongs[1])
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[2];
		}
		else
		{
			wrong2 = wrongs[0];
			wrong3 = wrongs[1];
		}
	}
	}

	// Here, in order to represent the audience's votes, we randomize the order of the answers we will print
	string percText;

	vector<int> finalPercs = { secondBiggest, thirdBiggest, fourthBiggest };
	randomize = rand() % finalPercs.size();
	int odd1 = finalPercs[randomize];
	if (odd1 == secondBiggest)
	{
		finalPercs.erase(remove(finalPercs.begin(), finalPercs.end(), secondBiggest), finalPercs.end());
	}
	else if (odd1 == thirdBiggest)
	{
		finalPercs.erase(remove(finalPercs.begin(), finalPercs.end(), thirdBiggest), finalPercs.end());
	}
	else
	{
		finalPercs.erase(remove(finalPercs.begin(), finalPercs.end(), fourthBiggest), finalPercs.end());
	}
	randomize = rand() % finalPercs.size();
	int odd2 = finalPercs[randomize];
	int odd3 = remainingProc - odd1 - odd2;

	// Then we finally print the randomized answers and the percentages.
	centerText1("The audience has voted: ");
	cout << endl;
	switch (suggestion)
	{
	case 'A': 
	{
		percText = suggestion;
		percText += "): ";
		centerText1NoEndline(percText);
		cout << correctSuggest << "%" << endl;

		percText = 'B';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd1 << "%" << endl;

		percText = 'C';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd2 << "%" << endl;

		percText = 'D';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd3 << "%" << endl;
	}
	break;
	case 'B':
	{
		percText = 'A';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd1 << "%" << endl;

		percText = suggestion;
		percText += "): ";
		centerText1NoEndline(percText);
		cout << correctSuggest << "%" << endl;

		percText = 'C';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd2 << "%" << endl;

		percText = 'D';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd3 << "%" << endl;
	
	}
	break; 
	case 'C':
	{
		percText = 'A';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd1 << "%" << endl;

		percText = 'B';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd2 << "%" << endl;

		percText = suggestion;
		percText += "): ";
		centerText1NoEndline(percText);
		cout << correctSuggest << "%" << endl;

		percText = 'D';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd3 << "%" << endl;
	}
	break;
	case 'D':
	{
		percText = 'A';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd1 << "%" << endl;

		percText = 'B';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd2 << "%" << endl;

		percText = 'C';
		percText += "): ";
		centerText1NoEndline(percText);
		cout << odd3 << "%" << endl;

		percText = suggestion;
		percText += "): ";
		centerText1NoEndline(percText);
		cout << correctSuggest << "%" << endl;
	}
	break;
	}
}

void Ask_The_Audience_Answer(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, string& ansLetter, char& suggestion)
{
	// Lets the user pick an answer after they have used this lifeline
	percentages(suggestion);

	cout << endl;
	border();
	space2();
	string chooseAns;
	cin >> chooseAns;
	if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32)
	{
		++awardTimes;
		awardScreen(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
	else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
	{
		awardTimes = 0;
		useFifty_Fifty = 0;
		useCall_A_Friend = 0;
		useAsk_The_Audience = 0;
		awardFunctionCall = 0;
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
}
void Ask_The_Audience_Confirm()
{
	// Asks if the user really wants to use the lifeline (they can cancel their choice)
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Ask the audience\" lifeline?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
}

void readAndAnswerQuestion_Ask_Audience_Easy(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// This function reads the question from the file as we already know from void readQuestion
	// The two functions below are similar, but for a different difficulty
	if (!file.is_open())
	{
		cout << "A mistake occured." << endl;
	}

	string row; 

	string num; 
	num += to_string(start);
	num += ' ';

	string correct = "$$"; 
	string ansLetter;
	int countLen = 0;

	while (getline(file, row))	
	{
		size_t location = row.find(num);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, num.length()); 

	cout << " " << row << endl; 

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

		cout << " " << row << endl; 

	}

	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	char suggestion = audienceAnswersEasy(ansLetter[0]);
	Ask_The_Audience_Answer(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter, suggestion);
}
void readAndAnswerQuestion_Ask_Audience_Normal(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	if (!file.is_open())
	{
		cout << "A mistake occured." << endl;
	}

	string row; 

	string num; 
	num += to_string(start);
	num += ' ';

	string correct = "$$"; 
	string ansLetter;
	int countLen = 0;

	while (getline(file, row))	
	{
		size_t location = row.find(num);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, num.length()); 

	cout << " " << row << endl; 

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

		cout << " " << row << endl; 

	}

	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	char suggestion = audienceAnswersNormal(ansLetter[0]);
	Ask_The_Audience_Answer(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter, suggestion);
}
void readAndAnswerQuestion_Ask_Audience_Hard(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	if (!file.is_open())
	{
		cout << "A mistake occured." << endl;
	}

	string row;

	string num; 
	num += to_string(start);
	num += ' ';

	string correct = "$$";
	string ansLetter;
	int countLen = 0;

	while (getline(file, row))
	{
		size_t location = row.find(num);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, num.length()); 

	cout << " " << row << endl; 

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

		cout << " " << row << endl; 

	}

	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	char suggestion = audienceAnswersHard(ansLetter[0]);
	Ask_The_Audience_Answer(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter, suggestion);
}
void LifelineAsk_The_Audience(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// This function wraps up all the work on the lifeline and presents the lifeline to the user
	ifstream file;
	// Opening a different file depending on the game progress
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
	}
	clear();
	space2();
	border();
	space2();
		
	readQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	Ask_The_Audience_Confirm();
	
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
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
		}
		clear();
		space2();
		border();
		space2();
		switch (awardTimes)
		{
			case 0:
			{
				readAndAnswerQuestion_Ask_Audience_Easy(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 1:
			{
				readAndAnswerQuestion_Ask_Audience_Easy(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 2:
			{
				readAndAnswerQuestion_Ask_Audience_Easy(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 3:
			{
				readAndAnswerQuestion_Ask_Audience_Normal(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 4:
			{
				readAndAnswerQuestion_Ask_Audience_Normal(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 5:
			{
				readAndAnswerQuestion_Ask_Audience_Normal(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 6:
			{
				readAndAnswerQuestion_Ask_Audience_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 7:
			{
				readAndAnswerQuestion_Ask_Audience_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 8:
			{
				readAndAnswerQuestion_Ask_Audience_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 9:
			{
				readAndAnswerQuestion_Ask_Audience_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
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
		}
		playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
	else
	{
	LifelineAsk_The_Audience(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
}


char tellAnswersEasy(char ansLetter)
{
	string answers;
	switch (ansLetter)	// Here we extract the wrong answers from the question
	{
		// In these cases we will take the four events of different correct answers.
		// The "Friend" we phone through the lifeline has a 30% chance of being wrong, so
		// For the different cases we fill the array with right and wrong answers, where
		// out of 10 elements, 7 are correct, the other 3 are wrong, 3x1 are the same 
		// (here that means that the three are different from one another).
		// Then we pick a random element, so that's how we achieve 70% success rate.
	case 'A': 
	{
		answers += {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D'}; 
	}
		break;
	case 'B':
	{
		answers += {'A', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'C', 'D'};
	}
		break;
	case 'C':
	{
		answers += {'A', 'B', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'D'};
	}
		break;
	case 'D': 
	{
		answers += {'A', 'B', 'C', 'D', 'D', 'D', 'D', 'D', 'D', 'D'};
	}
		break;
	}
	srand(time(NULL));
	char suggestion = 0;
	int randomize = 0;
	if (answers.size() != 0)
	{
		randomize = rand() % answers.size();
		suggestion = answers[randomize];
	}
	return suggestion;
}
char tellAnswersNormal(char ansLetter)
{
	string answers;
	switch (ansLetter)	// Here we extract the wrong answers from the question
	{
		// For the different cases we fill the array with right and wrong answers, where
		// out of 10 elements, 4 are correct, the other 6 are wrong, 3x2 of them are the same. 
		// Then we pick a random element, so that's how we achieve 40% success rate.
	case 'A':
	{
		answers += {'A', 'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D'};
	}
	break;
	case 'B':
	{
		answers += {'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'D', 'D'};
	}
	break;
	case 'C':
	{
		answers += {'A', 'A', 'B', 'B', 'C', 'C', 'C', 'C', 'D', 'D'};
	}
	break;
	case 'D':
	{
		answers += {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'D', 'D'};
	}
	break;
	}
	srand(time(NULL));
	char suggestion;
	int randomize = 0;
	if (answers.size() != 0)
	{
		randomize = rand() % answers.size();
	}
	suggestion = answers[randomize];
	return suggestion;
}
char tellAnswersHard(char ansLetter)
{
	string answers;
	switch (ansLetter)	// Here we extract the wrong answers from the question
	{
		// For the different cases we fill the array with right and wrong answers, where
		// out of 30 elements, 6 are correct, the other 24 are wrong, 3x8 of them are the same. 
		// Then we pick a random element, so that's how we achieve 20% success rate.
	case 'A':
	{
		answers += 
		{
			'A', 'A', 'A', 'A', 'A', 'A',
			'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
			'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
			'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D' 
		};
	}
	break;
	case 'B':
	{
		answers += 
		{
			'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
			'B', 'B', 'B', 'B', 'B', 'B',
			'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
			'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'
		};
	}
	break;
	case 'C':
	{
		answers += 
		{
			'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
			'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
			'C', 'C', 'C', 'C', 'C', 'C',
			'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'
		};
	}
	break;
	case 'D':
	{
		answers +=
		{
			'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
			'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
			'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
			'D', 'D', 'D', 'D', 'D', 'D'
		};
	}
	break;
	}
	srand(time(NULL));
	char suggestion = 0;
	int randomize = 0;
	if (answers.size() != 0)
	{
		randomize = rand() % answers.size();
		suggestion = answers[randomize];
	}
	return suggestion;
}

void Phone_A_Friend_Confirm()
{
	// Similarly to the one above, asks the user to confirm their choice
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
}
void Phone_A_Friend_Answer(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, string& ansLetter, char& suggestionPick)
{
	// Lets the user answer after they have picked this lifeline
	cout << endl;
	centerText1NoEndline("Hi, I think the answer is ");
	cout << suggestionPick << ')';
	space1();
	space2();
	border();
	space2();
	string chooseAns;
	cin >> chooseAns;
	if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32)
	{
		++awardTimes;
		awardScreen(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
	else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
	{
		awardTimes = 0;
		useFifty_Fifty = 0;
		useCall_A_Friend = 0;
		useAsk_The_Audience = 0;
		awardFunctionCall = 0;
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
}
void readAndAnswerQuestion_Phone_A_Friend_Easy(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// Presents the question and lets the user answer while using the lifeline
	// The other two functions below are for the other two levels of difficulty
	if (!file.is_open())
	{
		cout << "A mistake occured." << endl;
	}

	string row; 

	string num; 
	num += to_string(start);
	num += ' ';

	string correct = "$$"; 
	string ansLetter;
	int countLen = 0;

	while (getline(file, row))
	{
		size_t location = row.find(num);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, num.length()); 

	cout << " " << row << endl; 

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

		cout << " " << row << endl; 

	}

	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	char suggestionPick = tellAnswersEasy(ansLetter[0]);
	Phone_A_Friend_Answer(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter, suggestionPick);
}
void readAndAnswerQuestion_Phone_A_Friend_Normal(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	if (!file.is_open())
	{
		cout << "A mistake occured." << endl;
	}

	string row;

	string num; 
	num += to_string(start);
	num += ' ';

	string correct = "$$"; 
	string ansLetter;
	int countLen = 0;

	while (getline(file, row))	 
	{
		size_t location = row.find(num);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, num.length()); 

	cout << " " << row << endl; 

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

		cout << " " << row << endl;

	}

	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	char suggestionPick = tellAnswersNormal(ansLetter[0]);
	Phone_A_Friend_Answer(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter, suggestionPick);
}
void readAndAnswerQuestion_Phone_A_Friend_Hard(ifstream& file, int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	if (!file.is_open())
	{
		cout << "A mistake occured." << endl;
	}

	string row;

	string num; 
	num += to_string(start);
	num += ' ';

	string correct = "$$"; 
	string ansLetter;
	int countLen = 0;

	while (getline(file, row))
	{
		size_t location = row.find(num);
		if (location != string::npos)
		{
			break;
		}
	}

	row.erase(0, num.length()); 

	cout << " " << row << endl; 

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

		cout << " " << row << endl; 

	}

	if (file.is_open())
	{
		file.close();
	}
	cout << endl;
	char suggestionPick = tellAnswersHard(ansLetter[0]);
	Phone_A_Friend_Answer(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter, suggestionPick);
}
void LifelinePhone_A_Friend(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// This function wraps up the "Phone a friend" work and presents the lifeline
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
	}
	clear();
	space2();
	border();
	space2();

	
	readQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	Phone_A_Friend_Confirm();
	
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
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
		}
		clear();
		space2();
		border();
		space2();
		switch (awardTimes)
			{
			case 0:
			{
				readAndAnswerQuestion_Phone_A_Friend_Easy(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 1:
			{
				readAndAnswerQuestion_Phone_A_Friend_Easy(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 2:
			{
				readAndAnswerQuestion_Phone_A_Friend_Easy(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 3:
			{
				readAndAnswerQuestion_Phone_A_Friend_Normal(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 4:
			{
				readAndAnswerQuestion_Phone_A_Friend_Normal(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 5:
			{
				readAndAnswerQuestion_Phone_A_Friend_Normal(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 6:
			{
				readAndAnswerQuestion_Phone_A_Friend_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 7:
			{
				readAndAnswerQuestion_Phone_A_Friend_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 8:
			{
				readAndAnswerQuestion_Phone_A_Friend_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
				break;
			case 9:
			{
				readAndAnswerQuestion_Phone_A_Friend_Hard(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
			}
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
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
		}
		playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
	else
	{
		LifelinePhone_A_Friend(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
}


void Fifty_Fifty_Confirm()
{
	// Once again, this is used to ask the user to confirm their choice
	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
}
void Fifty_Fifty_Answer(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes, string& ansLetter)
{
	// Lets the user answer while using this lifeline
	space1();
	space2();
	border();
	space2();
	string chooseAns;
	cin >> chooseAns;
	if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32)
	{
		++awardTimes;
		awardScreen(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
	else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
	{
		awardTimes = 0;
		useFifty_Fifty = 0;
		useCall_A_Friend = 0;
		useAsk_The_Audience = 0;
		awardFunctionCall = 0;
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2(awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
	}
}
void LifelineFifty_Fifty(int start, int& awardFunctionCall, vector<int>& allQuestions, int& useFifty_Fifty, int& useCall_A_Friend, int& useAsk_The_Audience, int& awardTimes)
{
	// This is the "50/50" lifeline functionality, wrapped up
	{
		ifstream file;
		
		switch (awardTimes) // Depending on the progress, we open a different file, once again
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
		}
		
		clear();
		space2();
		border();
		space2();


		if (!file.is_open())
		{
			cout << "A mistake occured." << endl;
		}

		string row; 

		string num; 
		num += to_string(start);
		num += ' ';

		string correct = "$$"; 
		string ansLetter;
		int countLen = 0;
		string wrongAns1, wrongAns2, wrongAns3;
		while (getline(file, row))	
		{
			size_t location = row.find(num);
			if (location != string::npos)
			{
				break;
			}
		}

		row.erase(0, num.length()); 

		cout << " " << row << endl; 

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
				switch (ansLetter[0])	// Here we extract the wrong answers from the question
				{
				case 'A': wrongAns1 = "B)", wrongAns2 = "C)", wrongAns3 = "D)";
					break;
				case 'B': wrongAns1 = "A)", wrongAns2 = "C)", wrongAns3 = "D)";
					break;
				case 'C': wrongAns1 = "A)", wrongAns2 = "B)", wrongAns3 = "D)";
					break;
				case 'D': wrongAns1 = "A)", wrongAns2 = "B)", wrongAns3 = "C)";
					break;
				}
			}

			cout << " " << row << endl; 

		}

		if (file.is_open())
		{
			file.close();
		}

		string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
		srand(time(NULL));
		char odd;
		int randomize = rand() % 2; // here we take one random wrong answer out of three and then
		odd = wrongs[randomize];	// take the other two that are left, which we are going to 
		char takeWrong1, takeWrong2;	// delete (so as to execute the 50/50 lifeline)
		if (odd == wrongAns1[0])
		{
			takeWrong1 = wrongAns2[0];
			takeWrong2 = wrongAns3[0];
		}
		else if (odd == wrongAns2[0])
		{
			takeWrong1 = wrongAns1[0];
			takeWrong2 = wrongAns3[0];
		}
		else
		{
			takeWrong1 = wrongAns1[0];
			takeWrong2 = wrongAns2[0];
		}
		string wrongLetter1 = { takeWrong1, ')' };
		string wrongLetter2 = { takeWrong2, ')' };

		Fifty_Fifty_Confirm();

		// Here the answer option is executed in the very same function
		string confirm;
		cin >> confirm;
		if (confirm[0] == 'Y' || confirm[0] == 'y')
		{
			clear();

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
			}
			
			clear();
			space2();
			border();
			space2();


			if (!file.is_open())
			{
				cout << "A mistake occured." << endl;
			}

			string row; 

			string num; 
			num += to_string(start);
			num += ' ';

			string correct = "$$";
			string ansLetter;
			int countLen = 0;
			int countWrong1 = 0, countWrong2 = 0;
			string wrongAns1, wrongAns2, wrongAns3;
			while (getline(file, row))	
			{
				size_t location = row.find(num);
				if (location != string::npos)
				{
					break;
				}
			}

			row.erase(0, num.length()); 

			cout << " " << row << endl; 

			while (getline(file, row))
			{
				for (int i = 0; row[i] != '\0'; ++i)
				{
					if (row[i] == '\t')	 
					{
						file.close();
					}
				}
				size_t wrong1 = row.find(wrongLetter1); // Here we find the two wrong answers that we have
				if (wrong1 != string::npos)				// marked and then we remove them (replace them with white space)
				{
					for (int i = wrong1; row[size_t(i) + 1] != '\0'; ++i)
					{
						if (row[i] == ' ' && row[size_t(i) + 1] == ' ' || row[i] == '\t')
						{
							break;
						}
						++countWrong1;
					}
					row.replace(wrong1, countWrong1, countWrong1, ' ');
				}
				size_t wrong2 = row.find(wrongLetter2);
				if (wrong2 != string::npos)
				{
					for (int i = wrong2; row[size_t(i) + 1] != '\0'; ++i)
					{
						if (row[i] == ' ' && row[size_t(i) + 1] == ' ' || row[i] == '\t')
						{
							break;
						}
						++countWrong2;
					}
					row.replace(wrong2, countWrong2, countWrong2, ' ');					
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

				cout << " " << row << endl; 

			}
			if (file.is_open())
			{
				file.close();
			}
			Fifty_Fifty_Answer(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes, ansLetter);
		}
		else if (confirm[0] == 'n' || confirm[0] == 'N') // If the user wants to go back, they are being shown the same question again
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
		}
			playQuestion(file, start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
		}
		else
		{
		 LifelineFifty_Fifty(start, awardFunctionCall, allQuestions, useFifty_Fifty, useCall_A_Friend, useAsk_The_Audience, awardTimes);
		}
	}
}

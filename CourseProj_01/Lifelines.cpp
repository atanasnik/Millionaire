#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"
int audienceAnswersEasy(char ansLetter)
{
	string answers;
	switch (ansLetter)	// Here we extract the wrong answers from the question
	{
		// In these cases we will take the four events of different correct answers.
		// The "audience" we ask through lifeline has 30% chance of being wrong, so
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
	char suggestion;
	int randomize = rand() % answers.size();
	suggestion = answers[randomize];
	return suggestion;
}
void percentagesEasy(char suggestion)
{
	char wrong1;
	char wrong2;
	char wrong3;
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
	correctSuggest = percent[randomize];

	int secondBiggest = 0;
	int thirdBiggest = 0;
	int fourthBiggest = 0;
	int remainingProc = 100 - correctSuggest;
	vector<int> remainder1(50, 0);
	remainder1[0] = 1;
	for (int i = 1; i < remainingProc; ++i)
	{
		remainder1[i] = remainder1[i - 1] + 1;
	}
	randomize = rand() % remainder1.size() - 3;
	secondBiggest = remainder1[randomize];

	int remainingProc2 = remainingProc - secondBiggest;
	vector<int> remainder2(50, 0);
	remainder2[0] = 1;
	for (int i = 1; i < remainingProc2; ++i)
	{
		remainder2[i] = remainder2[i - 1] + 1;
	}
	randomize = rand() % remainder2.size() - 3;
	thirdBiggest = remainder2[randomize];

	fourthBiggest = remainingProc2 - thirdBiggest;

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

	string text;
	centerText1("The audience has voted: ");
	/*centerText1NoEndline(text = ((suggestion == 'A') ?
								suggestion : (wrong1 == 'A') ?
								wrong1 : (wrong2 == 'A') ?
								wrong2 : (wrong3 == 'A') ?
								wrong3 : '0'));
	centerText1NoEndline("): ");
	centerText1NoEndline(text = ((suggestion == 'A')? correctSuggest : ;

	centerText1(text = (suggestion == 'B') ? suggestion : (wrong1 == 'B') ? wrong1 : (wrong2 == 'B') ? wrong2 : (wrong3 == 'B') ? wrong3 : '0');
	centerText1(text = (suggestion == 'C') ? suggestion : (wrong1 == 'C') ? wrong1 : (wrong2 == 'C') ? wrong2 : (wrong3 == 'C') ? wrong3 : '0');
	centerText1(text = (suggestion == 'D') ? suggestion : (wrong1 == 'D') ? wrong1 : (wrong2 == 'D') ? wrong2 : (wrong3 == 'D') ? wrong3 : '0');*/
	



}
void Ques1LifelineAsk_The_Audience(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{

	ifstream file;
	file.open("Level1.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersEasy(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Ask the audience\" lifeline?";
	string instruct = "Press Y for yes and N for no: ";
}

char tellAnswersEasy(char ansLetter)
{
	string answers;
	switch (ansLetter)	// Here we extract the wrong answers from the question
	{
		// In these cases we will take the four events of different correct answers.
		// The "Friend" we phone through the lifeline has 30% chance of being wrong, so
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
	char suggestion;
	int randomize = rand() % answers.size();
	suggestion = answers[randomize];
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
	int randomize = rand() % answers.size();
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
		// Then we pick a random element, so that's how we achieve 40% success rate.
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
	char suggestion;
	int randomize = rand() % answers.size();
	suggestion = answers[randomize];
	return suggestion;
}
void Ques1LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level1.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersEasy(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level1.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level1.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques1LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques2LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level2.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersEasy(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level2.txt");
		system("CLS");
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

			cout << " " << row << endl; 

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level2.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques2LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques3LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level3.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersEasy(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level3.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level3.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques3LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques4LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level4.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersNormal(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level4.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level4.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques4LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques5LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level5.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersNormal(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level5.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level5.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques5LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques6LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level6.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersNormal(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level6.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level6.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques6LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques7LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level7.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersHard(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level7.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level7.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques7LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques8LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level8.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersHard(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level8.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level8.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques8LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques9LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level9.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersHard(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level9.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level9.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques9LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}
void Ques10LifelinePhone_A_Friend(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level10.txt");
	system("CLS");
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

		cout << " " << row << endl;

	}
	char suggestionPick = tellAnswersHard(ansLetter[0]);
	if (file.is_open())
	{
		file.close();
	}
	space2();
	cout << endl;
	string ask = "Are you sure you want to use the \"Phone a friend\" lifeline ?";
	string instruct = "Press Y for yes and N for no: ";
	centerText1(ask);
	centerText1(instruct);
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'y' || confirm[0] == 'Y')
	{
		fstream file;
		file.open("Level10.txt");
		system("CLS");
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
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
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32)
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level10.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques10LifelinePhone_A_Friend(start, awardTimes, awardFunctionCall);
	}
}

void Ques1LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level1.txt");
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
	string wrongAns1, wrongAns2, wrongAns3;
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	if (file.is_open())
	{
		file.close();
	}

	string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
	srand(time(NULL));
	char odd;
	int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level1.txt");
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
		int countWrong1 = 0, countWrong2 = 0;
		string wrongAns1, wrongAns2, wrongAns3;
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong1;
				}
				row.replace(wrong1, countWrong1, countWrong1, ' ');
				/*row.erase(wrong1, wrong1 + countWrong1);
				row.insert(wrong1, countWrong1, ' ');*/
			}
			size_t wrong2 = row.find(wrongLetter2);
			if (wrong2 != string::npos)
			{
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong2;
				}
				row.replace(wrong2, countWrong2, countWrong2, ' ');
				/*row.erase(wrong2, wrong2 + countWrong2);
				row.insert(wrong2, countWrong2, ' ');*/
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
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level1.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques1LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
void Ques2LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	{
		ifstream file;
		file.open("Level2.txt");
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
		string wrongAns1, wrongAns2, wrongAns3;
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

			cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

		}

		if (file.is_open())
		{
			file.close();
		}

		string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
		srand(time(NULL));
		char odd;
		int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

		space2();
		cout << endl;
		centerText1("Are you sure you want to use 50/50?");
		centerText1("Press Y for yes and N for no: ");
		space2();
		border();
		space2();
		string confirm;
		cin >> confirm;
		if (confirm[0] == 'Y' || confirm[0] == 'y')
		{
			system("CLS");

			ifstream file;
			file.open("Level2.txt");
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
			int countWrong1 = 0, countWrong2 = 0;
			string wrongAns1, wrongAns2, wrongAns3;
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
				size_t wrong1 = row.find(wrongLetter1);
				if (wrong1 != string::npos)
				{
					for (int i = wrong1; row[i + 1] != '\0'; ++i)
					{
						if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
						{
							break;
						}
						++countWrong1;
					}
					row.replace(wrong1, countWrong1, countWrong1, ' ');
					/*row.erase(wrong1, wrong1 + countWrong1);
					row.insert(wrong1, countWrong1, ' ');*/
				}
				size_t wrong2 = row.find(wrongLetter2);
				if (wrong2 != string::npos)
				{
					for (int i = wrong2; row[i + 1] != '\0'; ++i)
					{
						if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
						{
							break;
						}
						++countWrong2;
					}
					row.replace(wrong2, countWrong2, countWrong2, ' ');
					/*row.erase(wrong2, wrong2 + countWrong2);
					row.insert(wrong2, countWrong2, ' ');*/
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
			space1();
			space2();
			border();
			space2();
			string chooseAns;
			cin >> chooseAns;
			if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
			{
				++awardTimes;
				awardScreen(awardFunctionCall);
			}
			else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
			{
				awardTimes = 0;
				awardFunctionCall = 0;
				defeatScreen1_1();
				centerText1(ansLetter);
				defeatScreen1_2(awardFunctionCall);
			}
		}
		else if (confirm[0] == 'n' || confirm[0] == 'N')
		{
			ifstream file;
			file.open("Level2.txt");
			playQuestion(file, start, awardFunctionCall);
		}
		else
		{
			Ques2LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
		}
	}
}
void Ques3LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	{
		ifstream file;
		file.open("Level3.txt");
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
		string wrongAns1, wrongAns2, wrongAns3;
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

			cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

		}

		if (file.is_open())
		{
			file.close();
		}

		string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
		srand(time(NULL));
		char odd;
		int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

		space2();
		cout << endl;
		centerText1("Are you sure you want to use 50/50?");
		centerText1("Press Y for yes and N for no: ");
		space2();
		border();
		space2();
		string confirm;
		cin >> confirm;
		if (confirm[0] == 'Y' || confirm[0] == 'y')
		{
			system("CLS");

			ifstream file;
			file.open("Level3.txt");
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
			int countWrong1 = 0, countWrong2 = 0;
			string wrongAns1, wrongAns2, wrongAns3;
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
				size_t wrong1 = row.find(wrongLetter1);
				if (wrong1 != string::npos)
				{
					for (int i = wrong1; row[i + 1] != '\0'; ++i)
					{
						if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
						{
							break;
						}
						++countWrong1;
					}
					row.replace(wrong1, countWrong1, countWrong1, ' ');
					/*row.erase(wrong1, wrong1 + countWrong1);
					row.insert(wrong1, countWrong1, ' ');*/
				}
				size_t wrong2 = row.find(wrongLetter2);
				if (wrong2 != string::npos)
				{
					for (int i = wrong2; row[i + 1] != '\0'; ++i)
					{
						if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
						{
							break;
						}
						++countWrong2;
					}
					row.replace(wrong2, countWrong2, countWrong2, ' ');
					/*row.erase(wrong2, wrong2 + countWrong2);
					row.insert(wrong2, countWrong2, ' ');*/
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
			space1();
			space2();
			border();
			space2();
			string chooseAns;
			cin >> chooseAns;
			if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
			{
				++awardTimes;
				awardScreen(awardFunctionCall);
			}
			else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
			{
				awardTimes = 0;
				awardFunctionCall = 0;
				defeatScreen1_1();
				centerText1(ansLetter);
				defeatScreen1_2(awardFunctionCall);
			}
		}
		else if (confirm[0] == 'n' || confirm[0] == 'N')
		{
			ifstream file;
			file.open("Level3.txt");
			playQuestion(file, start, awardFunctionCall);
		}
		else
		{
			Ques3LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
		}
	}
}
void Ques4LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level4.txt");
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
	string wrongAns1, wrongAns2, wrongAns3;
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	if (file.is_open())
	{
		file.close();
	}

	string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
	srand(time(NULL));
	char odd;
	int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level4.txt");
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
		int countWrong1 = 0, countWrong2 = 0;
		string wrongAns1, wrongAns2, wrongAns3;
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong1;
				}
				row.replace(wrong1, countWrong1, countWrong1, ' ');
				/*row.erase(wrong1, wrong1 + countWrong1);
				row.insert(wrong1, countWrong1, ' ');*/
			}
			size_t wrong2 = row.find(wrongLetter2);
			if (wrong2 != string::npos)
			{
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong2;
				}
				row.replace(wrong2, countWrong2, countWrong2, ' ');
				/*row.erase(wrong2, wrong2 + countWrong2);
				row.insert(wrong2, countWrong2, ' ');*/
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
		//cout << endl;
		/*cout << " " << "Current lifelines: " << endl;
		cout << " " << "50/50 (Press X)" << endl;
		cout << " " << "Phone a friend (Press Y)" << endl;
		cout << " " << "Ask the audience (Press Z)" << endl;*/
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level4.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques4LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
void Ques5LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level5.txt");
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
	string wrongAns1, wrongAns2, wrongAns3;
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	if (file.is_open())
	{
		file.close();
	}

	string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
	srand(time(NULL));
	char odd;
	int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level5.txt");
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
		int countWrong1 = 0, countWrong2 = 0;
		string wrongAns1, wrongAns2, wrongAns3;
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong1;
				}
				row.replace(wrong1, countWrong1, countWrong1, ' ');
				/*row.erase(wrong1, wrong1 + countWrong1);
				row.insert(wrong1, countWrong1, ' ');*/
			}
			size_t wrong2 = row.find(wrongLetter2);
			if (wrong2 != string::npos)
			{
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong2;
				}
				row.replace(wrong2, countWrong2, countWrong2, ' ');
				/*row.erase(wrong2, wrong2 + countWrong2);
				row.insert(wrong2, countWrong2, ' ');*/
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
		//cout << endl;
		/*cout << " " << "Current lifelines: " << endl;
		cout << " " << "50/50 (Press X)" << endl;
		cout << " " << "Phone a friend (Press Y)" << endl;
		cout << " " << "Ask the audience (Press Z)" << endl;*/
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level5.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques5LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
void Ques6LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level6.txt");
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
	string wrongAns1, wrongAns2, wrongAns3;
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	if (file.is_open())
	{
		file.close();
	}

	string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
	srand(time(NULL));
	char odd;
	int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level6.txt");
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
		int countWrong1 = 0, countWrong2 = 0;
		string wrongAns1, wrongAns2, wrongAns3;
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong1;
				}
				row.replace(wrong1, countWrong1, countWrong1, ' ');
				/*row.erase(wrong1, wrong1 + countWrong1);
				row.insert(wrong1, countWrong1, ' ');*/
			}
			size_t wrong2 = row.find(wrongLetter2);
			if (wrong2 != string::npos)
			{
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong2;
				}
				row.replace(wrong2, countWrong2, countWrong2, ' ');
				/*row.erase(wrong2, wrong2 + countWrong2);
				row.insert(wrong2, countWrong2, ' ');*/
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
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level6.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques6LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
void Ques7LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level7.txt");
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
	string wrongAns1, wrongAns2, wrongAns3;
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	if (file.is_open())
	{
		file.close();
	}

	string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
	srand(time(NULL));
	char odd;
	int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level7.txt");
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
		int countWrong1 = 0, countWrong2 = 0;
		string wrongAns1, wrongAns2, wrongAns3;
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong1;
				}
				row.replace(wrong1, countWrong1, countWrong1, ' ');
				/*row.erase(wrong1, wrong1 + countWrong1);
				row.insert(wrong1, countWrong1, ' ');*/
			}
			size_t wrong2 = row.find(wrongLetter2);
			if (wrong2 != string::npos)
			{
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong2;
				}
				row.replace(wrong2, countWrong2, countWrong2, ' ');
				/*row.erase(wrong2, wrong2 + countWrong2);
				row.insert(wrong2, countWrong2, ' ');*/
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
		//cout << endl;
		/*cout << " " << "Current lifelines: " << endl;
		cout << " " << "50/50 (Press X)" << endl;
		cout << " " << "Phone a friend (Press Y)" << endl;
		cout << " " << "Ask the audience (Press Z)" << endl;*/
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level7.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques7LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
void Ques8LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level8.txt");
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
	string wrongAns1, wrongAns2, wrongAns3;
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	if (file.is_open())
	{
		file.close();
	}

	string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
	srand(time(NULL));
	char odd;
	int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level8.txt");
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
		int countWrong1 = 0, countWrong2 = 0;
		string wrongAns1, wrongAns2, wrongAns3;
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong1;
				}
				row.replace(wrong1, countWrong1, countWrong1, ' ');
				/*row.erase(wrong1, wrong1 + countWrong1);
				row.insert(wrong1, countWrong1, ' ');*/
			}
			size_t wrong2 = row.find(wrongLetter2);
			if (wrong2 != string::npos)
			{
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong2;
				}
				row.replace(wrong2, countWrong2, countWrong2, ' ');
				/*row.erase(wrong2, wrong2 + countWrong2);
				row.insert(wrong2, countWrong2, ' ');*/
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
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level8.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques8LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
void Ques9LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level9.txt");
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
	string wrongAns1, wrongAns2, wrongAns3;
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

	}

	if (file.is_open())
	{
		file.close();
	}

	string wrongs = { wrongAns1[0], wrongAns2[0], wrongAns3[0] };
	srand(time(NULL));
	char odd;
	int randomize = rand() % 2; // here we take one random  wrong answer out of three and then
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level9.txt");
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
		int countWrong1 = 0, countWrong2 = 0;
		string wrongAns1, wrongAns2, wrongAns3;
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong1;
				}
				row.replace(wrong1, countWrong1, countWrong1, ' ');
				/*row.erase(wrong1, wrong1 + countWrong1);
				row.insert(wrong1, countWrong1, ' ');*/
			}
			size_t wrong2 = row.find(wrongLetter2);
			if (wrong2 != string::npos)
			{
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
					{
						break;
					}
					++countWrong2;
				}
				row.replace(wrong2, countWrong2, countWrong2, ' ');
				/*row.erase(wrong2, wrong2 + countWrong2);
				row.insert(wrong2, countWrong2, ' ');*/
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
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level9.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques9LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
void Ques10LifelineFifty_Fifty(int start, static unsigned int& awardTimes, static unsigned int& awardFunctionCall)
{
	ifstream file;
	file.open("Level10.txt");
	system("CLS");
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
			for (int i = ans; row[i + 1] != '\0'; ++i)
			{
				if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
				{
					break;
				}
				++countLen;
			}
			ansLetter += row.substr(ans - 2, ans + countLen);
			switch (ansLetter[0])
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
	int randomize = rand() % 2; 
	odd = wrongs[randomize];	 
	char takeWrong1, takeWrong2;
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

	space2();
	cout << endl;
	centerText1("Are you sure you want to use 50/50?");
	centerText1("Press Y for yes and N for no: ");
	space2();
	border();
	space2();
	string confirm;
	cin >> confirm;
	if (confirm[0] == 'Y' || confirm[0] == 'y')
	{
		system("CLS");

		ifstream file;
		file.open("Level10.txt");
		system("CLS");
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
			size_t wrong1 = row.find(wrongLetter1);
			if (wrong1 != string::npos)
			{
				for (int i = wrong1; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
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
				for (int i = wrong2; row[i + 1] != '\0'; ++i)
				{
					if (row[i] == ' ' && row[i + 1] == ' ' || row[i] == '\t')
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

			cout << " " << row << endl;

		}
		if (file.is_open())
		{
			file.close();
		}
		space1();
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32)
		{
			++awardTimes;
			awardScreen(awardFunctionCall);
		}
		
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) 
		{
			awardTimes = 0;
			awardFunctionCall = 0;
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2(awardFunctionCall);
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level10.txt");
		playQuestion(file, start, awardFunctionCall);
	}
	else
	{
		Ques10LifelineFifty_Fifty(start, awardTimes, awardFunctionCall);
	}
}
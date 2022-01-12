#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"

char tellAnswersEasy(char ansLetter)
{
	string answers;
	switch (ansLetter)	// Here we extract the wrong answers from the question
	{
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
	int randomize = rand() % 2;
	suggestion = answers[randomize];
	return suggestion;
}
void Ques1LifelinePhone_A_Friend(int start)
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
	char suggestionPick = tellAnswersEasy(ansLetter[0]);

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
		Question1NoLifelines(start);
		centerText1NoEndline("Hi, I think the answer is ");
		cout << suggestionPick << ')';
		space2();
		border();
		space2();
		typeAnsNoLifeline(ansLetter);
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		Question1(start);
	}
}
void typeAnsNoLifeline(string ansLetter)
{
	string chooseAns;
	cin >> chooseAns;
	if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
	{
		awardScreen();
	}
	else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
	{
		defeatScreen1_1();
		centerText1(ansLetter);
		defeatScreen1_2();
	}
}
void Ques2LifelinePhone_A_Friend(int start)
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
	char suggestionPick = tellAnswersEasy(ansLetter[0]);

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
		Question2NoLifelines(start);
		centerText1NoEndline("Hi, I think the answer is ");
		cout << suggestionPick << ')';
		space2();
		border();
		space2();
		typeAnsNoLifeline(ansLetter);
		if (file.is_open())
		{
			file.close();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		Question2(start);
	}
}
void Ques1LifelineFifty_Fifty(int start)
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level1.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques1LifelineFifty_Fifty(start);
	}
}
void Ques2LifelineFifty_Fifty(int start)
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
				awardScreen();
			}
			//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
			//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
			//{
			//	//Ques1LifelineConfirm(start);
			//	//TODO: ADD LIFELINES
			//}
			else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
			{
				defeatScreen1_1();
				centerText1(ansLetter);
				defeatScreen1_2();
			}
		}
		else if (confirm[0] == 'n' || confirm[0] == 'N')
		{
			ifstream file;
			file.open("Level2.txt");
			playQuestion(file, start);
		}
		else
		{
			Ques2LifelineFifty_Fifty(start);
		}
	}
}
void Ques3LifelineFifty_Fifty(int start)
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
				awardScreen();
			}
			//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
			//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
			//{
			//	//Ques1LifelineConfirm(start);
			//	//TODO: ADD LIFELINES
			//}
			else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
			{
				defeatScreen1_1();
				centerText1(ansLetter);
				defeatScreen1_2();
			}
		}
		else if (confirm[0] == 'n' || confirm[0] == 'N')
		{
			ifstream file;
			file.open("Level3.txt");
			playQuestion(file, start);
		}
		else
		{
			Ques3LifelineFifty_Fifty(start);
		}
	}
}
void Ques4LifelineFifty_Fifty(int start)
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level4.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques4LifelineFifty_Fifty(start);
	}
}
void Ques5LifelineFifty_Fifty(int start)
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level5.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques5LifelineFifty_Fifty(start);
	}
}
void Ques6LifelineFifty_Fifty(int start)
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level6.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques6LifelineFifty_Fifty(start);
	}
}
void Ques7LifelineFifty_Fifty(int start)
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level7.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques7LifelineFifty_Fifty(start);
	}
}
void Ques8LifelineFifty_Fifty(int start)
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level8.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques8LifelineFifty_Fifty(start);
	}
}
void Ques9LifelineFifty_Fifty(int start)
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level9.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques9LifelineFifty_Fifty(start);
	}
}
void Ques10LifelineFifty_Fifty(int start)
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
		file.open("Level10.txt");
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
			awardScreen();
		}
		//else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
		//	chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		//{
		//	//Ques1LifelineConfirm(start);
		//	//TODO: ADD LIFELINES
		//}
		else if (chooseAns[0] != ansLetter[0] && chooseAns[0] != char(ansLetter[0]) + 32) // If the user picks the wrong answer
		{
			defeatScreen1_1();
			centerText1(ansLetter);
			defeatScreen1_2();
		}
	}
	else if (confirm[0] == 'n' || confirm[0] == 'N')
	{
		ifstream file;
		file.open("Level10.txt");
		playQuestion(file, start);
	}
	else
	{
		Ques10LifelineFifty_Fifty(start);
	}
}
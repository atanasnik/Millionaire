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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

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
		cout << endl;
		cout << " " << "Current lifelines: " << endl;
		//cout << " " << "50/50 (Press X)" << endl;
		cout << " " << "Phone a friend (Press Y)" << endl;
		cout << " " << "Ask the audience (Press Z)" << endl;
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			awardScreen();
		}
		else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
			chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		{
			//Ques1LifelineConfirm(start);
			//TODO: ADD LIFELINES
		}
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

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
		cout << endl;
		cout << " " << "Current lifelines: " << endl;
		//cout << " " << "50/50 (Press X)" << endl;
		cout << " " << "Phone a friend (Press Y)" << endl;
		cout << " " << "Ask the audience (Press Z)" << endl;
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			awardScreen();
		}
		else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
			chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		{
			//Ques1LifelineConfirm(start);
			//TODO: ADD LIFELINES
		}
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
void Ques3LifelineFifty_Fifty(int start)
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

		cout << " " << row << endl; // Prints the rest of the question (and the possible answers)

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
		cout << endl;
		cout << " " << "Current lifelines: " << endl;
		//cout << " " << "50/50 (Press X)" << endl;
		cout << " " << "Phone a friend (Press Y)" << endl;
		cout << " " << "Ask the audience (Press Z)" << endl;
		space2();
		border();
		space2();
		string chooseAns;
		cin >> chooseAns;
		if (chooseAns[0] == ansLetter[0] || chooseAns[0] == char(ansLetter[0]) + 32) // If the user picks the right answer
		{
			awardScreen();
		}
		else if (chooseAns[0] == 'Y' || chooseAns[0] == 'y' ||
			chooseAns[0] == 'Z' || chooseAns[0] == 'z')
		{
			//Ques1LifelineConfirm(start);
			//TODO: ADD LIFELINES
		}
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
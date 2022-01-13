#include "MainLayout.h"
#include "MainTextAndSlides.h"
#include "OutputQuestions.h"
#include "Lifelines.h"

#ifndef INPUTQUESTIONS_H
#define INPUTQUESTIONS_H

void backToInputQuesScreen(vector<int>& allQuestions);
void backToInputAnsScreen(string& inpQuestion, vector<int>& allQuestions);
void backToChooseCorrect(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void backToChooseLevel(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void backToChooseCategory(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID);

void inputQuesScreen(vector<int>& allQuestions);
void inputAnsScreen(string& inpQuestion, vector<int>& allQuestions);

void formatAnswers(string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void formatQuestion(string& inpQuestion, vector<int>& allQuestions, int& makeID);

void chooseCorrect(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void chooseLevel(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions);
void chooseCategory(string& inpQuestion, string& ansA, string& ansB, string& ansC, string& ansD, vector<int>& allQuestions, int& levelNum, int& makeID);

#endif

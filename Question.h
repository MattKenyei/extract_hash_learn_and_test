#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Book.h"
using namespace std;

class Question {
public:
    string text;
    vector<string> options;
    int correctAnswer;

    Question();

    Question(const string& questionText, const vector<string>& questionOptions, int questionCorrectAnswer);
};

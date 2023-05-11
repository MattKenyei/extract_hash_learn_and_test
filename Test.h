#pragma once
#include "Question.h"
class Test {
public:
    vector<Question> questions;

    Test();

    void loadQuestionsFromFile(const string& filename);

    void runTest(Book b);
};

#include "Question.h"

Question::Question()
{
}

Question::Question(const string& questionText, const vector<string>& questionOptions, int questionCorrectAnswer)
{
   text = questionText;
   options = questionOptions;
   correctAnswer = questionCorrectAnswer;   
}

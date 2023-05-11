#include "Test.h"
Test::Test()
{
}

void Test::loadQuestionsFromFile(const string& filename)
{

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "�� ������� ������� ���� � ���������." << endl;
        return;
    }
    cout << "������ ������������" << endl;
    string line;
    while (getline(inFile, line)) {
        // ������ ������
        string questionText = line;

        // ������ �������� �������
        vector<string> questionOptions;
        for (int i = 0; i < 3; i++) {
            getline(inFile, line);
            questionOptions.push_back(line);
        }

        // ������ ���������� �����
        int questionCorrectAnswer;
        inFile >> questionCorrectAnswer;
        questionCorrectAnswer--;
        // ��������� ������ ������
        getline(inFile, line);
        getline(inFile, line);

        // ������� ����� ������ � ��������� ��� � ����
        Question question(questionText, questionOptions, questionCorrectAnswer);
        questions.push_back(question);
    }
}

void Test::runTest(Book b)
{
    int numQuestions = questions.size();
    int score = 0;
    bool correct[21];
    for (int i = 0; i < 20; i++)
        correct[i] = true;
    for (int i = 0; i < numQuestions; i++) {
        // ������� ������� ������ � �������� �������
        cout << questions[i].text << endl;
        for (int j = 0; j < 3; j++) 
        {
            cout << j + 1 << ". " << questions[i].options[j] << endl;
        }

        // �������� ����� ������������
        int userAnswer;
        cin >> userAnswer;

        // ��������� ����� ������������
        if (userAnswer - 1 == questions[i].correctAnswer) {
            cout << "���������!" << endl;
            score++;
        }
        else {
            cout << "�����������." << endl;
            correct[i] = false;
        }
    }

    // ������� ���������� �����
    cout << "���� ��������. �� �������� ��������� �� " << score << " �� " << numQuestions << " ��������." << endl;
    if (score < numQuestions)
    {
        cout << "������ �� ��������, �� ������� �� �������� �������: " << endl;
        for (int i = 0; i < numQuestions; i++)
            if (correct[i] == false)
            {
                if (i == 0)
                {
                    cout << "�" << i + 1 << endl;
                    cout << b.chapters[0].GetText() << endl;
                }
                else if (i == 1)
                {
                    cout << "�" << i + 1 << endl;
                    cout << b.chapters[1].GetText() << endl;
                }
                else if (i == 2 || i == 9)
                {
                    cout << "�3" << endl;
                    cout << b.chapters[2].GetText() << endl;
                    correct[9] = true;
                }
                else if (i == 3 || i == 8)
                {
                    cout << "�4" << endl;
                    cout << b.chapters[3].GetText() << endl;
                    correct[8] = true;
                }
                else if(i == 4 || i == 5 || i == 6 || i == 7)
                {
                    cout << "�5" << endl;
                    cout << b.chapters[4].GetText() << endl;
                    correct[5] = true;
                    correct[6] = true;
                    correct[7] = true;
                }
                else if (i == 10 || i == 19 || i == 15)
                {
                    cout << "�11" << endl;
                    cout << b.chapters[5].GetText() << endl;
                    correct[15] = true;
                    correct[19] = true;
                }
                else if (i == 11 || i == 12 || i == 14)
                {
                    cout << "�12" << endl;
                    cout << b.chapters[6].GetText() << endl;
                    correct[12] = true;
                    correct[14] = true;
                }
                else if (i == 13 || i == 16 || i == 17 || i == 18)
                {
                    cout << "�13" << endl;
                    cout << b.chapters[7].GetText() << endl;
                    correct[16] = true;
                    correct[17] = true;
                    correct[18] = true;
                }
            }
    }
}

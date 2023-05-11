#include "Test.h"
#include "Book.h"
int main() 
{
    system("color F0");
    setlocale(LC_ALL, "Russian");
    Book book("Book.txt");
    book.Run();
    Test test;
    system("cls");
    test.loadQuestionsFromFile("questions.txt");
    test.runTest(book);

    return 0;
}

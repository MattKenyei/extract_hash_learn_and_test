#include "Book.h"

Book::Book(std::string file_name) : file_name_(file_name)
{
}

void Book::Run()
{
    std::ifstream file(file_name_);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << file_name_ << std::endl;
        return;
    }

   

    std::string line;
    std::string chapter_name;
    std::string chapter_text;
    bool is_reading_chapter = false;

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        if (is_reading_chapter)
        {
            if (line.find("Chapter") == 0)
            {
                chapters.emplace_back(chapter_name, chapter_text);
                chapter_name = line;
                chapter_text = "";
            }
            else
            {
                chapter_text += line + "\n";
            }
        }
        else if (line.find("Chapter") == 0)
        {
            is_reading_chapter = true;
            chapter_name = line;
        }
    }

    if (!chapter_name.empty())
    {
        chapters.emplace_back(chapter_name, chapter_text);
    }

    if (chapters.empty())
    {
        std::cerr << "Главы отсутствуют в файле: " << file_name_ << std::endl;
        return;
    }

    bool exit_requested = false;
    while (!exit_requested)
    {
        for (int i = 0; i < chapters.size(); ++i)
            std::cout << chapters[i].GetName() << "\n";

        std::cout << "\nВведите номер главы (0 чтобы выйти): ";
        int chapter_number;
        std::cin >> chapter_number;

        if (chapter_number == 0)
        {
            exit_requested = true;
        }
        else if (chapter_number < 1 || chapter_number > chapters.size())
        {
            std::cout << "\nНеправильный номер. Выберите номер между 1 и " << chapters.size() << ".\n";
        }
        else
        {
            std::cout << "\n" << chapters[chapter_number - 1].GetText() << "\n";
            std::string response;
            std::cout << "Введите любой символ для прочтения дальше или напишите 'exit' чтобы выйти: ";
            std::getline(std::cin >> std::ws, response);
            if (response == "exit")
            {
                exit_requested = true;
            }
        }
    }
}

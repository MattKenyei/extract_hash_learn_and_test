#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Chapter
{
private:
    std::string name_;
    std::string text_;
public:
    Chapter(std::string name, std::string text) : name_(name), text_(text) {}
    std::string GetName() const { return name_; }
    std::string GetText() const { return text_; }
};
class Book
{
private:
    std::string file_name_;
public:
    Book() {};
    std::vector<Chapter> chapters;
    Book(std::string file_name);
    void Run();
};




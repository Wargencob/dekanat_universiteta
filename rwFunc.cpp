#include "rwFunc.h"
#include "student.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

std::vector<std::string> split(std::string text, char splitChar)
{
    std::vector<std::string> result;

    int stringStart = 0;
    int stringEnd = 0;

    bool isStart = true;
    bool isEnd = false;

    for (int i = 0; i < text.length(); i++)
    {
        if (isStart)
        {
            stringStart = i;
            isStart = false;
        }
        if (text[i] == splitChar || text[i] == '\n')
        {
            stringEnd = i;
            isEnd = true;
        }

        if (!isStart && isEnd)
        {
            result.push_back(text.substr(stringStart, stringEnd - stringStart));

            isStart = true;
            isEnd = false;
        }
    }

    if (!isStart)
    {
        result.push_back(text.substr(stringStart, text.length() - stringStart));
    }

    return result;
}

std::vector<std::string> readTextFromFile(std::string filePath, char splitChar)
{
    std::ifstream inputFileStream (filePath);
    std::stringstream buffer;

    if(inputFileStream.is_open())
    {
        buffer << inputFileStream.rdbuf();

        std::string text = buffer.str();

        std::vector<std::string> result = split(text, splitChar);

        inputFileStream.close();

        return result;
    }
    else
    {
        std::cout << "This file is not exist" << std::endl;
    }
}

void writeTextInFile(std::string text, std::string filePath)
{
    std::ofstream outputFileStream (filePath, std::ios::app);

    if(outputFileStream.is_open())
    {
        outputFileStream << text;
        outputFileStream.close();
    }
    else
    {
        std::cout << "This file is not exist" << std::endl;
    }
}


std::vector<Student> getVectorOfStudentFromText(std::vector<std::string> text){
    int count = 0;

    std::vector<Student> result;

    Student buffer;

    int offset = 5;

    for(int i = 0; i + offset - 1 < text.size(); i+=offset)
    {
        buffer.id = std::stoi(text[i]);
        buffer.recordBookNumber = std::stoi(text[i + 1]);
        buffer.nameAndSurname = text[i+2];
        buffer.phoneNumber = std::stoll(text[i+3]);
        buffer.avg = std::stod(text[i+4]);

        result.push_back(buffer);
    }

    return result;
}


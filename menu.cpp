#include "menu.h"
#include <iostream>
#include <string>
#include <vector>
#include "rwFunc.h"
#include "student.h"

void menu()
{
    std::string filePath = "your file path";

    std::cout << "Hello, this application can work with dekanat db" << std::endl;
    std::cout << "1. Read and write db source into the console" << std::endl;
    std::cout << "2. Add new Student to the db" << std::endl;
    std::cout << "3. Exit from app" << std::endl;
    std::cout << "Write a number of menu position:" << std::endl;

    int number;

    bool end = false;

    while(!end)
    {
        std::cin >> number;

        switch (number)
        {
        case 1:
        {
            std::vector<std::string> text = readTextFromFile(filePath, ';');

            std::vector<Student> result = getVectorOfStudentFromText(text);

            for (int i = 0; i < result.size(); i++)
            {
                std::cout << result[i].id << " " <<
                    result[i].recordBookNumber << " " <<
                    result[i].nameAndSurname << " " <<
                    result[i].phoneNumber << " " <<
                    result[i].avg << std::endl;
            }

            std::cout << "Write a number of menu position:" << std::endl;

            break;
        }
        case 2:
        {
            std::string text;
            std::string id;
            std::string recordBookNumber;
            std::string name;
            std::string surname;
            std::string phoneNumber;
            std::string avg;
            std::cout << "Enter id:" << std::endl;
            std::cin >> id;
            std::cout << "Enter Record book number:" << std::endl;
            std::cin >> recordBookNumber;
            std::cout << "Enter name:" << std::endl;
            std::cin >> name;
            std::cout << "Enter surname:" << std::endl;
            std::cin >> surname;
            std::cout << "Enter phone number:" << std::endl;
            std::cin >> phoneNumber;
            std::cout << "Enter avg (format with '.'):" << std::endl;
            std::cin >> avg;
            text = id + ";" + recordBookNumber + ";" + name + " " + surname + ";" + phoneNumber + ";" + avg;
            writeTextInFile(text, filePath);

            std::cout << "Write a number of menu position:" << std::endl;

            break;
        }
        case 3:
        {
            end = true;
            break;
        }
        default:
        {
            std::cout << "Wrong number, try again" << std::endl;
            break;
        }

        }
    }

}

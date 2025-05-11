#include "menu.h"
#include <iostream>
#include <string>
#include <vector>
#include "rwFunc.h"
#include "student.h"

void menu()
{
    std::string filePath = "/home/wargen/dekanat_universiteta/doffice.db";

    std::cout << "Привет, это приложение для работы с БД деканата" << std::endl;
    std::cout << "1. Чтение из данных в БД" << std::endl;
    std::cout << "2. Добавить нового студента в БД" << std::endl;
    std::cout << "3. Выйти из приложения" << std::endl;
    std::cout << "Введите номер пункта меню:" << std::endl;

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

            std::cout << "Введите номер пункта меню:" << std::endl;

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
            std::cout << "Введите айди пользователя:" << std::endl;
            std::cin >> id;
            std::cout << "Введите номер зачётной книжки:" << std::endl;
            std::cin >> recordBookNumber;
            std::cout << "Введите имя студента:" << std::endl;
            std::cin >> name;
            std::cout << "Введите фамилию:" << std::endl;
            std::cin >> surname;
            std::cout << "Введите номер телефона:" << std::endl;
            std::cin >> phoneNumber;
            std::cout << "Введите средний балл (в формате 'число.число'):" << std::endl;
            std::cin >> avg;
            text = id + ";" + recordBookNumber + ";" + name + " " + surname + ";" + phoneNumber + ";" + avg;
            writeTextInFile(text, filePath);

            std::cout << "Введите номер пункта меню:" << std::endl;

            break;
        }
        case 3:
        {
            end = true;
            break;
        }
        default:
        {
            std::cout << "Такого номера не существует, попробуйте ещё раз" << std::endl;
            break;
        }

        }
    }

}

#ifndef RWFUNC_H
#define RWFUNC_H

#include <vector>
#include <string>

#include "student.h"

std::vector<std::string> readTextFromFile(std::string filePath, char splitChar);

void writeTextInFile(std::string text, std::string filePath);

std::vector<std::string> split(std::string text);

std::vector<Student> getVectorOfStudentFromText(std::vector<std::string> text);

#endif // RWFUNC_H

#ifndef RWFUNC_H
#define RWFUNC_H

#include <vector>
#include <string>

std::vector<std::string> readTextFromFile(std::string filePath);

void writeTextInFile(std::vector<std::string>);

std::vector<std::string> split(std::string text);

#endif // RWFUNC_H

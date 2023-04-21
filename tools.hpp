//#pragma once

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>

void pauseWithOptionalTimeout(double seconds = 0.0);
void appendToLogFile(const std::string& fileName, const std::string& content);
std::string getCurrentDateTime();

#endif // TOOLS_HPP
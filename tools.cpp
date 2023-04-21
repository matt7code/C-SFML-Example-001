#include "tools.hpp"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include <fstream>
#include <ctime>

void pauseWithOptionalTimeout(double seconds) {
    if (seconds > 0.0) {
        // If a timeout is provided, pause for the specified duration
        std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
    }
    else {
        // If no timeout is provided, wait for user input
        std::cout << "Press Enter to resume...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void appendToLogFile(const std::string& fileName, const std::string& content) {
    // Open a file for writing
    std::ofstream file(fileName, std::ios::out | std::ios::app);

    if (file.is_open()) {
        // Write data to the file
        file << "LOG: Program Run " << content << std::endl;

        // Close the file
        file.close();
        std::cout << "File created successfully." << std::endl;
    }
    else {
        std::cout << "Failed to create file." << std::endl;
    }
}

std::string getCurrentDateTime() {
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Convert the time point to a time_t value
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    // Convert the time_t value to a tm structure
    std::tm tm;
    localtime_s(&tm, &time); // Use localtime_s instead of localtime

    // Extract the components of the date and time
    int year = tm.tm_year + 1900; // Year since 1900
    int month = tm.tm_mon + 1;    // Month [0-11]
    int day = tm.tm_mday;         // Day of the month [1-31]
    int hour = tm.tm_hour;       // Hour [0-23]
    int minute = tm.tm_min;      // Minute [0-59]
    int second = tm.tm_sec;      // Second [0-59]

    // Format the date and time as a string
    std::string result = std::to_string(year) + "-" +
        (month < 10 ? "0" : "") + std::to_string(month) + "-" +
        (day < 10 ? "0" : "") + std::to_string(day) + " " +
        (hour < 10 ? "0" : "") + std::to_string(hour) + ":" +
        (minute < 10 ? "0" : "") + std::to_string(minute) + ":" +
        (second < 10 ? "0" : "") + std::to_string(second);

    return result;
}



